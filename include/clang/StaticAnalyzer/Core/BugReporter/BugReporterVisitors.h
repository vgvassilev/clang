//===- BugReporterVisitors.h - Generate PathDiagnostics ---------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
//  This file declares BugReporterVisitors, which are used to generate enhanced
//  diagnostic traces.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_STATICANALYZER_CORE_BUGREPORTER_BUGREPORTERVISITORS_H
#define LLVM_CLANG_STATICANALYZER_CORE_BUGREPORTER_BUGREPORTERVISITORS_H

#include "clang/Analysis/ProgramPoint.h"
#include "clang/Basic/LLVM.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/RangedConstraintManager.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/SVals.h"
#include "llvm/ADT/FoldingSet.h"
#include "llvm/ADT/IntrusiveRefCntPtr.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/StringRef.h"
#include <list>
#include <memory>
#include <utility>

namespace clang {

class BinaryOperator;
class CFGBlock;
class DeclRefExpr;
class Expr;
class Stmt;

namespace ento {

class PathSensitiveBugReport;
class BugReporterContext;
class ExplodedNode;
class MemRegion;
class PathDiagnosticPiece;
using PathDiagnosticPieceRef = std::shared_ptr<PathDiagnosticPiece>;

/// BugReporterVisitors are used to add custom diagnostics along a path.
class BugReporterVisitor : public llvm::FoldingSetNode {
public:
  BugReporterVisitor() = default;
  BugReporterVisitor(const BugReporterVisitor &) = default;
  BugReporterVisitor(BugReporterVisitor &&) {}
  virtual ~BugReporterVisitor();

  /// Return a diagnostic piece which should be associated with the
  /// given node.
  /// Note that this function does *not* get run on the very last node
  /// of the report, as the PathDiagnosticPiece associated with the
  /// last node should be unique.
  /// Use \ref getEndPath to customize the note associated with the report
  /// end instead.
  ///
  /// The last parameter can be used to register a new visitor with the given
  /// BugReport while processing a node.
  virtual PathDiagnosticPieceRef VisitNode(const ExplodedNode *Succ,
                                           BugReporterContext &BRC,
                                           PathSensitiveBugReport &BR) = 0;

  /// Last function called on the visitor, no further calls to VisitNode
  /// would follow.
  virtual void finalizeVisitor(BugReporterContext &BRC,
                               const ExplodedNode *EndPathNode,
                               PathSensitiveBugReport &BR);

  /// Provide custom definition for the final diagnostic piece on the
  /// path - the piece, which is displayed before the path is expanded.
  ///
  /// NOTE that this function can be implemented on at most one used visitor,
  /// and otherwise it crahes at runtime.
  virtual PathDiagnosticPieceRef getEndPath(BugReporterContext &BRC,
                                            const ExplodedNode *N,
                                            PathSensitiveBugReport &BR);

  virtual void Profile(llvm::FoldingSetNodeID &ID) const = 0;

  /// Generates the default final diagnostic piece.
  static PathDiagnosticPieceRef
  getDefaultEndPath(const BugReporterContext &BRC, const ExplodedNode *N,
                    const PathSensitiveBugReport &BR);
};

namespace bugreporter {

/// Specifies the type of tracking for an expression.
enum class TrackingKind {
  /// Default tracking kind -- specifies that as much information should be
  /// gathered about the tracked expression value as possible.
  Thorough,
  /// Specifies that a more moderate tracking should be used for the expression
  /// value. This will essentially make sure that functions relevant to it
  /// aren't pruned, but otherwise relies on the user reading the code or
  /// following the arrows.
  Condition
};

/// Defines a set of options altering tracking behavior.
struct TrackingOptions {
  /// Specifies the kind of tracking.
  TrackingKind Kind = TrackingKind::Thorough;
  /// Specifies whether we should employ false positive suppression
  /// (inlined defensive checks, returned null).
  bool EnableNullFPSuppression = true;
};

/// Describes an event when the value got stored into a memory region.
///
/// As opposed to checker checkBind API, it reacts also to binds
/// generated by the checker as well.  It can be useful when the binding
/// happened as a result of evalCall, for example.
struct StoreInfo {
  enum Kind {
    /// The value got stored into the region during initialization:
    ///   int x = 42;
    Initialization,
    /// The value got stored into the region during assignment:
    ///   int x;
    ///   x = 42;
    Assignment,
    /// The value got stored into the region as block capture.
    /// Block data is modeled as a separate region, thus whenever
    /// the analyzer sees a captured variable, its value is copied
    /// into a special block region.
    BlockCapture
  };

  /// The type of store operation.
  Kind StoreKind;
  /// The node where the store happened.
  const ExplodedNode *StoreSite;
  /// The expression where the value comes from.
  /// NOTE: might be null.
  Expr *SourceOfTheValue;
  /// Symbolic value that is being stored.
  SVal Value;
  /// Memory regions involved in the store operation.
  ///   Dest <- Origin
  /// NOTE: Origin might be null, when the stored value doesn't come
  ///       from another region.
  const MemRegion *Dest, *Origin;
};

class Tracker;
using TrackerRef = llvm::IntrusiveRefCntPtr<Tracker>;

class ExpressionHandler;
class StoreHandler;

/// A generalized component for tracking expressions, values, and stores.
///
/// Tracker aimes at providing a sensible set of default behaviors that can be
/// used by any checker, while providing mechanisms to hook into any part of the
/// tracking process and insert checker-specific logic.
class Tracker : public llvm::RefCountedBase<Tracker> {
private:
  using ExpressionHandlerPtr = std::unique_ptr<ExpressionHandler>;
  using StoreHandlerPtr = std::unique_ptr<StoreHandler>;

  PathSensitiveBugReport &Report;
  std::list<ExpressionHandlerPtr> ExpressionHandlers;
  std::list<StoreHandlerPtr> StoreHandlers;

protected:
  /// \param Report The bug report to which visitors should be attached.
  Tracker(PathSensitiveBugReport &Report);

public:
  virtual ~Tracker() = default;

  static TrackerRef create(PathSensitiveBugReport &Report) {
    return new Tracker(Report);
  }

  PathSensitiveBugReport &getReport() { return Report; }

  /// Describes a tracking result with the most basic information of what was
  /// actually done (or not done).
  struct Result {
    /// Usually it means that the tracker added visitors.
    bool FoundSomethingToTrack = false;
    /// Signifies that the tracking was interrupted at some point.
    /// Usually this information is important only for sub-trackers.
    bool WasInterrupted = false;

    /// Combines the current result with the given result.
    void combineWith(const Result &Other) {
      // If we found something in one of the cases, we can
      // say we found something overall.
      FoundSomethingToTrack |= Other.FoundSomethingToTrack;
      // The same goes to the interruption.
      WasInterrupted |= Other.WasInterrupted;
    }
  };

  /// Track expression value back to its point of origin.
  ///
  /// \param E The expression value which we are tracking
  /// \param N A node "downstream" from the evaluation of the statement.
  /// \param Opts Tracking options specifying how we want to track the value.
  virtual Result track(const Expr *E, const ExplodedNode *N,
                       TrackingOptions Opts = {});

  /// Track how the value got stored into the given region and where it came
  /// from.
  ///
  /// \param V We're searching for the store where \c R received this value.
  /// \param R The region we're tracking.
  /// \param Opts Tracking options specifying how we want to track the value.
  /// \param Origin Only adds notes when the last store happened in a
  ///        different stackframe to this one. Disregarded if the tracking kind
  ///        is thorough.
  ///        This is useful, because for non-tracked regions, notes about
  ///        changes to its value in a nested stackframe could be pruned, and
  ///        this visitor can prevent that without polluting the bugpath too
  ///        much.
  virtual Result track(SVal V, const MemRegion *R, TrackingOptions Opts = {},
                       const StackFrameContext *Origin = nullptr);

  /// Handle the store operation and produce the note.
  ///
  /// \param SI The information fully describing the store.
  /// \param Opts Tracking options specifying how we got to it.
  ///
  /// NOTE: this method is designed for sub-trackers and visitors.
  virtual PathDiagnosticPieceRef handle(StoreInfo SI, TrackingOptions Opts);

  /// Add custom expression handler with the highest priority.
  ///
  /// It means that it will be asked for handling first, and can prevent
  /// other handlers from running if decides to interrupt.
  void addHighPriorityHandler(ExpressionHandlerPtr SH) {
    ExpressionHandlers.push_front(std::move(SH));
  }

  /// Add custom expression handler with the lowest priority.
  ///
  /// It means that it will be asked for handling last, and other handlers can
  /// prevent it from running if any of them decides to interrupt.
  void addLowPriorityHandler(ExpressionHandlerPtr SH) {
    ExpressionHandlers.push_back(std::move(SH));
  }

  /// Add custom store handler with the highest priority.
  ///
  /// It means that it will be asked for handling first, and will prevent
  /// other handlers from running if it produces non-null note.
  void addHighPriorityHandler(StoreHandlerPtr SH) {
    StoreHandlers.push_front(std::move(SH));
  }

  /// Add custom store handler with the lowest priority.
  ///
  /// It means that it will be asked for handling last, only
  /// if all other handlers failed to produce the note.
  void addLowPriorityHandler(StoreHandlerPtr SH) {
    StoreHandlers.push_back(std::move(SH));
  }

  /// Add custom expression/store handler with the highest priority
  ///
  /// See other overloads for explanation.
  template <class HandlerType, class... Args>
  void addHighPriorityHandler(Args &&... ConstructorArgs) {
    addHighPriorityHandler(std::make_unique<HandlerType>(
        *this, std::forward<Args>(ConstructorArgs)...));
  }

  /// Add custom expression/store handler with the lowest priority
  ///
  /// See other overloads for explanation.
  template <class HandlerType, class... Args>
  void addLowPriorityHandler(Args &&... ConstructorArgs) {
    addLowPriorityHandler(std::make_unique<HandlerType>(
        *this, std::forward<Args>(ConstructorArgs)...));
  }
};

/// Handles expressions during the tracking.
class ExpressionHandler {
private:
  Tracker &ParentTracker;

public:
  ExpressionHandler(Tracker &ParentTracker) : ParentTracker(ParentTracker) {}
  virtual ~ExpressionHandler() {}

  /// Handle the given expression from the given node.
  ///
  /// \param E The expression value which we are tracking
  /// \param Original A node "downstream" where the tracking started.
  /// \param ExprNode A node where the evaluation of \c E actually happens.
  /// \param Opts Tracking options specifying how we are tracking the value.
  virtual Tracker::Result handle(const Expr *E, const ExplodedNode *Original,
                                 const ExplodedNode *ExprNode,
                                 TrackingOptions Opts) = 0;

  /// \Return the tracker that initiated the process.
  Tracker &getParentTracker() { return ParentTracker; }
};

/// Handles stores during the tracking.
class StoreHandler {
private:
  Tracker &ParentTracker;

public:
  StoreHandler(Tracker &ParentTracker) : ParentTracker(ParentTracker) {}
  virtual ~StoreHandler() {}

  /// Handle the given store and produce the node.
  ///
  /// \param E The expression value which we are tracking
  /// \param N A node where the evaluation of \c E actually happens.
  /// \param Opts Tracking options specifying how we are tracking the value.
  ///
  /// \return the produced note, null if the handler doesn't support this kind
  ///         of stores.
  virtual PathDiagnosticPieceRef handle(StoreInfo SI, TrackingOptions Opts) = 0;

  Tracker &getParentTracker() { return ParentTracker; }
};

/// Visitor that tracks expressions and values.
class TrackingBugReporterVisitor : public BugReporterVisitor {
private:
  TrackerRef ParentTracker;

public:
  TrackingBugReporterVisitor(TrackerRef ParentTracker)
      : ParentTracker(ParentTracker) {}

  Tracker &getParentTracker() { return *ParentTracker; }
};

/// Attempts to add visitors to track expression value back to its point of
/// origin.
///
/// \param N A node "downstream" from the evaluation of the statement.
/// \param E The expression value which we are tracking
/// \param R The bug report to which visitors should be attached.
/// \param EnableNullFPSuppression Whether we should employ false positive
///         suppression (inlined defensive checks, returned null).
///
/// \return Whether or not the function was able to add visitors for this
///         statement. Note that returning \c true does not actually imply
///         that any visitors were added.
bool trackExpressionValue(const ExplodedNode *N, const Expr *E,
                          PathSensitiveBugReport &R, TrackingOptions Opts = {});

/// Track how the value got stored into the given region and where it came
/// from.
///
/// \param V We're searching for the store where \c R received this value.
/// \param R The region we're tracking.
/// \param Opts Tracking options specifying how we want to track the value.
/// \param Origin Only adds notes when the last store happened in a
///        different stackframe to this one. Disregarded if the tracking kind
///        is thorough.
///        This is useful, because for non-tracked regions, notes about
///        changes to its value in a nested stackframe could be pruned, and
///        this visitor can prevent that without polluting the bugpath too
///        much.
void trackStoredValue(KnownSVal V, const MemRegion *R,
                      PathSensitiveBugReport &Report, TrackingOptions Opts = {},
                      const StackFrameContext *Origin = nullptr);

const Expr *getDerefExpr(const Stmt *S);

} // namespace bugreporter

class TrackConstraintBRVisitor final : public BugReporterVisitor {
  DefinedSVal Constraint;
  bool Assumption;
  bool IsSatisfied = false;
  bool IsZeroCheck;

  /// We should start tracking from the last node along the path in which the
  /// value is constrained.
  bool IsTrackingTurnedOn = false;

public:
  TrackConstraintBRVisitor(DefinedSVal constraint, bool assumption)
      : Constraint(constraint), Assumption(assumption),
        IsZeroCheck(!Assumption && Constraint.getAs<Loc>()) {}

  void Profile(llvm::FoldingSetNodeID &ID) const override;

  /// Return the tag associated with this visitor.  This tag will be used
  /// to make all PathDiagnosticPieces created by this visitor.
  static const char *getTag();

  PathDiagnosticPieceRef VisitNode(const ExplodedNode *N,
                                   BugReporterContext &BRC,
                                   PathSensitiveBugReport &BR) override;

private:
  /// Checks if the constraint is valid in the current state.
  bool isUnderconstrained(const ExplodedNode *N) const;
};

/// \class NilReceiverBRVisitor
/// Prints path notes when a message is sent to a nil receiver.
class NilReceiverBRVisitor final : public BugReporterVisitor {
public:
  void Profile(llvm::FoldingSetNodeID &ID) const override {
    static int x = 0;
    ID.AddPointer(&x);
  }

  PathDiagnosticPieceRef VisitNode(const ExplodedNode *N,
                                   BugReporterContext &BRC,
                                   PathSensitiveBugReport &BR) override;

  /// If the statement is a message send expression with nil receiver, returns
  /// the receiver expression. Returns NULL otherwise.
  static const Expr *getNilReceiver(const Stmt *S, const ExplodedNode *N);
};

/// Visitor that tries to report interesting diagnostics from conditions.
class ConditionBRVisitor final : public BugReporterVisitor {
  // FIXME: constexpr initialization isn't supported by MSVC2013.
  constexpr static llvm::StringLiteral GenericTrueMessage =
      "Assuming the condition is true";
  constexpr static llvm::StringLiteral GenericFalseMessage =
      "Assuming the condition is false";

public:
  void Profile(llvm::FoldingSetNodeID &ID) const override {
    static int x = 0;
    ID.AddPointer(&x);
  }

  /// Return the tag associated with this visitor.  This tag will be used
  /// to make all PathDiagnosticPieces created by this visitor.
  static const char *getTag();

  PathDiagnosticPieceRef VisitNode(const ExplodedNode *N,
                                   BugReporterContext &BRC,
                                   PathSensitiveBugReport &BR) override;

  PathDiagnosticPieceRef VisitNodeImpl(const ExplodedNode *N,
                                       BugReporterContext &BRC,
                                       PathSensitiveBugReport &BR);

  PathDiagnosticPieceRef
  VisitTerminator(const Stmt *Term, const ExplodedNode *N,
                  const CFGBlock *SrcBlk, const CFGBlock *DstBlk,
                  PathSensitiveBugReport &R, BugReporterContext &BRC);

  PathDiagnosticPieceRef VisitTrueTest(const Expr *Cond,
                                       BugReporterContext &BRC,
                                       PathSensitiveBugReport &R,
                                       const ExplodedNode *N, bool TookTrue);

  PathDiagnosticPieceRef VisitTrueTest(const Expr *Cond, const DeclRefExpr *DR,
                                       BugReporterContext &BRC,
                                       PathSensitiveBugReport &R,
                                       const ExplodedNode *N, bool TookTrue,
                                       bool IsAssuming);

  PathDiagnosticPieceRef
  VisitTrueTest(const Expr *Cond, const BinaryOperator *BExpr,
                BugReporterContext &BRC, PathSensitiveBugReport &R,
                const ExplodedNode *N, bool TookTrue, bool IsAssuming);

  PathDiagnosticPieceRef VisitTrueTest(const Expr *Cond, const MemberExpr *ME,
                                       BugReporterContext &BRC,
                                       PathSensitiveBugReport &R,
                                       const ExplodedNode *N, bool TookTrue,
                                       bool IsAssuming);

  PathDiagnosticPieceRef
  VisitConditionVariable(StringRef LhsString, const Expr *CondVarExpr,
                         BugReporterContext &BRC, PathSensitiveBugReport &R,
                         const ExplodedNode *N, bool TookTrue);

  /// Tries to print the value of the given expression.
  ///
  /// \param CondVarExpr The expression to print its value.
  /// \param Out The stream to print.
  /// \param N The node where we encountered the condition.
  /// \param TookTrue Whether we took the \c true branch of the condition.
  ///
  /// \return Whether the print was successful. (The printing is successful if
  ///         we model the value and we could obtain it.)
  bool printValue(const Expr *CondVarExpr, raw_ostream &Out,
                  const ExplodedNode *N, bool TookTrue, bool IsAssuming);

  bool patternMatch(const Expr *Ex,
                    const Expr *ParentEx,
                    raw_ostream &Out,
                    BugReporterContext &BRC,
                    PathSensitiveBugReport &R,
                    const ExplodedNode *N,
                    Optional<bool> &prunable,
                    bool IsSameFieldName);

  static bool isPieceMessageGeneric(const PathDiagnosticPiece *Piece);
};

/// Suppress reports that might lead to known false positives.
///
/// Currently this suppresses reports based on locations of bugs.
class LikelyFalsePositiveSuppressionBRVisitor final
    : public BugReporterVisitor {
public:
  static void *getTag() {
    static int Tag = 0;
    return static_cast<void *>(&Tag);
  }

  void Profile(llvm::FoldingSetNodeID &ID) const override {
    ID.AddPointer(getTag());
  }

  PathDiagnosticPieceRef VisitNode(const ExplodedNode *, BugReporterContext &,
                                   PathSensitiveBugReport &) override {
    return nullptr;
  }

  void finalizeVisitor(BugReporterContext &BRC, const ExplodedNode *N,
                       PathSensitiveBugReport &BR) override;
};

/// When a region containing undefined value or '0' value is passed
/// as an argument in a call, marks the call as interesting.
///
/// As a result, BugReporter will not prune the path through the function even
/// if the region's contents are not modified/accessed by the call.
class UndefOrNullArgVisitor final : public BugReporterVisitor {
  /// The interesting memory region this visitor is tracking.
  const MemRegion *R;

public:
  UndefOrNullArgVisitor(const MemRegion *InR) : R(InR) {}

  void Profile(llvm::FoldingSetNodeID &ID) const override {
    static int Tag = 0;
    ID.AddPointer(&Tag);
    ID.AddPointer(R);
  }

  PathDiagnosticPieceRef VisitNode(const ExplodedNode *N,
                                   BugReporterContext &BRC,
                                   PathSensitiveBugReport &BR) override;
};

class SuppressInlineDefensiveChecksVisitor final : public BugReporterVisitor {
  /// The symbolic value for which we are tracking constraints.
  /// This value is constrained to null in the end of path.
  DefinedSVal V;

  /// Track if we found the node where the constraint was first added.
  bool IsSatisfied = false;

  /// Since the visitors can be registered on nodes previous to the last
  /// node in the BugReport, but the path traversal always starts with the last
  /// node, the visitor invariant (that we start with a node in which V is null)
  /// might not hold when node visitation starts. We are going to start tracking
  /// from the last node in which the value is null.
  bool IsTrackingTurnedOn = false;

public:
  SuppressInlineDefensiveChecksVisitor(DefinedSVal Val, const ExplodedNode *N);

  void Profile(llvm::FoldingSetNodeID &ID) const override;

  /// Return the tag associated with this visitor.  This tag will be used
  /// to make all PathDiagnosticPieces created by this visitor.
  static const char *getTag();

  PathDiagnosticPieceRef VisitNode(const ExplodedNode *Succ,
                                   BugReporterContext &BRC,
                                   PathSensitiveBugReport &BR) override;
};

/// The bug visitor will walk all the nodes in a path and collect all the
/// constraints. When it reaches the root node, will create a refutation
/// manager and check if the constraints are satisfiable
class FalsePositiveRefutationBRVisitor final : public BugReporterVisitor {
private:
  /// Holds the constraints in a given path
  ConstraintMap Constraints;

public:
  FalsePositiveRefutationBRVisitor();

  void Profile(llvm::FoldingSetNodeID &ID) const override;

  PathDiagnosticPieceRef VisitNode(const ExplodedNode *N,
                                   BugReporterContext &BRC,
                                   PathSensitiveBugReport &BR) override;

  void finalizeVisitor(BugReporterContext &BRC, const ExplodedNode *EndPathNode,
                       PathSensitiveBugReport &BR) override;
  void addConstraints(const ExplodedNode *N,
                      bool OverwriteConstraintsOnExistingSyms);
};

/// The visitor detects NoteTags and displays the event notes they contain.
class TagVisitor : public BugReporterVisitor {
public:
  void Profile(llvm::FoldingSetNodeID &ID) const override;

  PathDiagnosticPieceRef VisitNode(const ExplodedNode *N,
                                   BugReporterContext &BRC,
                                   PathSensitiveBugReport &R) override;
};

} // namespace ento

} // namespace clang

#endif // LLVM_CLANG_STATICANALYZER_CORE_BUGREPORTER_BUGREPORTERVISITORS_H
