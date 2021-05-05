// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -fopenmp -x c++ %s -verify -debug-info-kind=limited -triple x86_64-unknown-unknown -emit-llvm -o - | FileCheck %s --check-prefix=CHECK1

// RUN: %clang_cc1 -fopenmp-simd -x c++ %s -verify -debug-info-kind=limited -triple x86_64-unknown-unknown -emit-llvm -o - | FileCheck %s --check-prefix=CHECK2
// expected-no-diagnostics

void a() {
  float _Complex b;
#pragma omp parallel firstprivate(b)
  ;
}


// CHECK1-LABEL: define {{[^@]+}}@_Z1av
// CHECK1-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG6:![0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[B:%.*]] = alloca { float, float }, align 4
// CHECK1-NEXT:    [[B_CASTED:%.*]] = alloca i64, align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata { float, float }* [[B]], metadata [[META10:![0-9]+]], metadata !DIExpression()), !dbg [[DBG12:![0-9]+]]
// CHECK1-NEXT:    [[TMP0:%.*]] = load { float, float }, { float, float }* [[B]], align 4, !dbg [[DBG13:![0-9]+]]
// CHECK1-NEXT:    [[CONV:%.*]] = bitcast i64* [[B_CASTED]] to { float, float }*, !dbg [[DBG13]]
// CHECK1-NEXT:    store { float, float } [[TMP0]], { float, float }* [[CONV]], align 4, !dbg [[DBG13]]
// CHECK1-NEXT:    [[TMP1:%.*]] = load i64, i64* [[B_CASTED]], align 8, !dbg [[DBG13]]
// CHECK1-NEXT:    call void (%struct.ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%struct.ident_t* @[[GLOB1:[0-9]+]], i32 1, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, i64)* @.omp_outlined. to void (i32*, i32*, ...)*), i64 [[TMP1]]), !dbg [[DBG13]]
// CHECK1-NEXT:    ret void, !dbg [[DBG14:![0-9]+]]
//
//
// CHECK1-LABEL: define {{[^@]+}}@.omp_outlined._debug__
// CHECK1-SAME: (i32* noalias [[DOTGLOBAL_TID_:%.*]], i32* noalias [[DOTBOUND_TID_:%.*]], <2 x float> [[B_COERCE:%.*]]) #[[ATTR2:[0-9]+]] !dbg [[DBG15:![0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[B:%.*]] = alloca { float, float }, align 4
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca i32*, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca i32*, align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = bitcast { float, float }* [[B]] to <2 x float>*
// CHECK1-NEXT:    store <2 x float> [[B_COERCE]], <2 x float>* [[TMP0]], align 4
// CHECK1-NEXT:    store i32* [[DOTGLOBAL_TID_]], i32** [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata i32** [[DOTGLOBAL_TID__ADDR]], metadata [[META23:![0-9]+]], metadata !DIExpression()), !dbg [[DBG24:![0-9]+]]
// CHECK1-NEXT:    store i32* [[DOTBOUND_TID_]], i32** [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata i32** [[DOTBOUND_TID__ADDR]], metadata [[META25:![0-9]+]], metadata !DIExpression()), !dbg [[DBG24]]
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata { float, float }* [[B]], metadata [[META26:![0-9]+]], metadata !DIExpression()), !dbg [[DBG27:![0-9]+]]
// CHECK1-NEXT:    ret void, !dbg [[DBG28:![0-9]+]]
//
//
// CHECK1-LABEL: define {{[^@]+}}@.omp_outlined.
// CHECK1-SAME: (i32* noalias [[DOTGLOBAL_TID_:%.*]], i32* noalias [[DOTBOUND_TID_:%.*]], i64 [[B:%.*]]) #[[ATTR3:[0-9]+]] !dbg [[DBG29:![0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca i32*, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca i32*, align 8
// CHECK1-NEXT:    [[B_ADDR:%.*]] = alloca i64, align 8
// CHECK1-NEXT:    store i32* [[DOTGLOBAL_TID_]], i32** [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata i32** [[DOTGLOBAL_TID__ADDR]], metadata [[META33:![0-9]+]], metadata !DIExpression()), !dbg [[DBG34:![0-9]+]]
// CHECK1-NEXT:    store i32* [[DOTBOUND_TID_]], i32** [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata i32** [[DOTBOUND_TID__ADDR]], metadata [[META35:![0-9]+]], metadata !DIExpression()), !dbg [[DBG34]]
// CHECK1-NEXT:    store i64 [[B]], i64* [[B_ADDR]], align 8
// CHECK1-NEXT:    call void @llvm.dbg.declare(metadata i64* [[B_ADDR]], metadata [[META36:![0-9]+]], metadata !DIExpression()), !dbg [[DBG34]]
// CHECK1-NEXT:    [[CONV:%.*]] = bitcast i64* [[B_ADDR]] to { float, float }*, !dbg [[DBG37:![0-9]+]]
// CHECK1-NEXT:    [[TMP0:%.*]] = load i32*, i32** [[DOTGLOBAL_TID__ADDR]], align 8, !dbg [[DBG37]]
// CHECK1-NEXT:    [[TMP1:%.*]] = load i32*, i32** [[DOTBOUND_TID__ADDR]], align 8, !dbg [[DBG37]]
// CHECK1-NEXT:    [[TMP2:%.*]] = bitcast { float, float }* [[CONV]] to <2 x float>*, !dbg [[DBG37]]
// CHECK1-NEXT:    [[TMP3:%.*]] = load <2 x float>, <2 x float>* [[TMP2]], align 8, !dbg [[DBG37]]
// CHECK1-NEXT:    call void @.omp_outlined._debug__(i32* [[TMP0]], i32* [[TMP1]], <2 x float> [[TMP3]]) #[[ATTR4:[0-9]+]], !dbg [[DBG37]]
// CHECK1-NEXT:    ret void, !dbg [[DBG37]]
//
//
// CHECK2-LABEL: define {{[^@]+}}@_Z1av
// CHECK2-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG6:![0-9]+]] {
// CHECK2-NEXT:  entry:
// CHECK2-NEXT:    [[B:%.*]] = alloca { float, float }, align 4
// CHECK2-NEXT:    call void @llvm.dbg.declare(metadata { float, float }* [[B]], metadata [[META10:![0-9]+]], metadata !DIExpression()), !dbg [[DBG12:![0-9]+]]
// CHECK2-NEXT:    ret void, !dbg [[DBG13:![0-9]+]]
//
