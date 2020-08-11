// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -msve-vector-bits=512 -fallow-half-arguments-and-returns -S -disable-llvm-passes -emit-llvm -o - %s | FileCheck %s

#include <arm_sve.h>

#define N __ARM_FEATURE_SVE_BITS_EXPERIMENTAL

typedef svint32_t fixed_int32_t __attribute__((arm_sve_vector_bits(N)));
typedef svbool_t fixed_bool_t __attribute__((arm_sve_vector_bits(N)));

fixed_bool_t global_pred;
fixed_int32_t global_vec;

// CHECK-LABEL: @foo(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca <16 x i32>, align 16
// CHECK-NEXT:    [[PRED_ADDR:%.*]] = alloca <vscale x 16 x i1>, align 2
// CHECK-NEXT:    [[VEC_ADDR:%.*]] = alloca <vscale x 4 x i32>, align 16
// CHECK-NEXT:    [[PG:%.*]] = alloca <vscale x 16 x i1>, align 2
// CHECK-NEXT:    [[SAVED_CALL_RVALUE:%.*]] = alloca <vscale x 4 x i32>, align 16
// CHECK-NEXT:    [[RETVAL_COERCE:%.*]] = alloca <vscale x 4 x i32>, align 16
// CHECK-NEXT:    store <vscale x 16 x i1> [[PRED:%.*]], <vscale x 16 x i1>* [[PRED_ADDR]], align 2
// CHECK-NEXT:    store <vscale x 4 x i32> [[VEC:%.*]], <vscale x 4 x i32>* [[VEC_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <vscale x 16 x i1>, <vscale x 16 x i1>* [[PRED_ADDR]], align 2
// CHECK-NEXT:    [[TMP1:%.*]] = load <8 x i8>, <8 x i8>* @global_pred, align 2
// CHECK-NEXT:    [[TMP2:%.*]] = load <vscale x 16 x i1>, <vscale x 16 x i1>* bitcast (<8 x i8>* @global_pred to <vscale x 16 x i1>*), align 2
// CHECK-NEXT:    [[TMP3:%.*]] = load <8 x i8>, <8 x i8>* @global_pred, align 2
// CHECK-NEXT:    [[TMP4:%.*]] = load <vscale x 16 x i1>, <vscale x 16 x i1>* bitcast (<8 x i8>* @global_pred to <vscale x 16 x i1>*), align 2
// CHECK-NEXT:    [[TMP5:%.*]] = call <vscale x 16 x i1> @llvm.aarch64.sve.and.z.nxv16i1(<vscale x 16 x i1> [[TMP0]], <vscale x 16 x i1> [[TMP2]], <vscale x 16 x i1> [[TMP4]])
// CHECK-NEXT:    store <vscale x 16 x i1> [[TMP5]], <vscale x 16 x i1>* [[PG]], align 2
// CHECK-NEXT:    [[TMP6:%.*]] = load <vscale x 16 x i1>, <vscale x 16 x i1>* [[PG]], align 2
// CHECK-NEXT:    [[TMP7:%.*]] = load <16 x i32>, <16 x i32>* @global_vec, align 16
// CHECK-NEXT:    [[TMP8:%.*]] = load <vscale x 4 x i32>, <vscale x 4 x i32>* bitcast (<16 x i32>* @global_vec to <vscale x 4 x i32>*), align 16
// CHECK-NEXT:    [[TMP9:%.*]] = load <vscale x 4 x i32>, <vscale x 4 x i32>* [[VEC_ADDR]], align 16
// CHECK-NEXT:    [[TMP10:%.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[TMP6]])
// CHECK-NEXT:    [[TMP11:%.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.add.nxv4i32(<vscale x 4 x i1> [[TMP10]], <vscale x 4 x i32> [[TMP8]], <vscale x 4 x i32> [[TMP9]])
// CHECK-NEXT:    store <vscale x 4 x i32> [[TMP11]], <vscale x 4 x i32>* [[SAVED_CALL_RVALUE]], align 16
// CHECK-NEXT:    [[CASTFIXEDSVE:%.*]] = bitcast <vscale x 4 x i32>* [[SAVED_CALL_RVALUE]] to <16 x i32>*
// CHECK-NEXT:    [[TMP12:%.*]] = load <16 x i32>, <16 x i32>* [[CASTFIXEDSVE]], align 16
// CHECK-NEXT:    store <16 x i32> [[TMP12]], <16 x i32>* [[RETVAL]], align 16
// CHECK-NEXT:    [[TMP13:%.*]] = bitcast <vscale x 4 x i32>* [[RETVAL_COERCE]] to i8*
// CHECK-NEXT:    [[TMP14:%.*]] = bitcast <16 x i32>* [[RETVAL]] to i8*
// CHECK-NEXT:    call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 [[TMP13]], i8* align 16 [[TMP14]], i64 64, i1 false)
// CHECK-NEXT:    [[TMP15:%.*]] = load <vscale x 4 x i32>, <vscale x 4 x i32>* [[RETVAL_COERCE]], align 16
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP15]]
//
fixed_int32_t foo(svbool_t pred, svint32_t vec) {
  svbool_t pg = svand_z(pred, global_pred, global_pred);
  return svadd_m(pg, global_vec, vec);
}

// CHECK-LABEL: @test_ptr_to_global(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca <16 x i32>, align 16
// CHECK-NEXT:    [[GLOBAL_VEC_PTR:%.*]] = alloca <16 x i32>*, align 8
// CHECK-NEXT:    [[RETVAL_COERCE:%.*]] = alloca <vscale x 4 x i32>, align 16
// CHECK-NEXT:    store <16 x i32>* @global_vec, <16 x i32>** [[GLOBAL_VEC_PTR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load <16 x i32>*, <16 x i32>** [[GLOBAL_VEC_PTR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load <16 x i32>, <16 x i32>* [[TMP0]], align 16
// CHECK-NEXT:    store <16 x i32> [[TMP1]], <16 x i32>* [[RETVAL]], align 16
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <vscale x 4 x i32>* [[RETVAL_COERCE]] to i8*
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <16 x i32>* [[RETVAL]] to i8*
// CHECK-NEXT:    call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 [[TMP2]], i8* align 16 [[TMP3]], i64 64, i1 false)
// CHECK-NEXT:    [[TMP4:%.*]] = load <vscale x 4 x i32>, <vscale x 4 x i32>* [[RETVAL_COERCE]], align 16
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP4]]
//
fixed_int32_t test_ptr_to_global() {
  fixed_int32_t *global_vec_ptr;
  global_vec_ptr = &global_vec;
  return *global_vec_ptr;
}

//
// Test casting pointer from fixed-length array to scalable vector.
// CHECK-LABEL: @array_arg(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca <16 x i32>, align 16
// CHECK-NEXT:    [[ARR_ADDR:%.*]] = alloca <16 x i32>*, align 8
// CHECK-NEXT:    [[RETVAL_COERCE:%.*]] = alloca <vscale x 4 x i32>, align 16
// CHECK-NEXT:    store <16 x i32>* [[ARR:%.*]], <16 x i32>** [[ARR_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load <16 x i32>*, <16 x i32>** [[ARR_ADDR]], align 8
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds <16 x i32>, <16 x i32>* [[TMP0]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = load <16 x i32>, <16 x i32>* [[ARRAYIDX]], align 16
// CHECK-NEXT:    store <16 x i32> [[TMP1]], <16 x i32>* [[RETVAL]], align 16
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <vscale x 4 x i32>* [[RETVAL_COERCE]] to i8*
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <16 x i32>* [[RETVAL]] to i8*
// CHECK-NEXT:    call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 [[TMP2]], i8* align 16 [[TMP3]], i64 64, i1 false)
// CHECK-NEXT:    [[TMP4:%.*]] = load <vscale x 4 x i32>, <vscale x 4 x i32>* [[RETVAL_COERCE]], align 16
// CHECK-NEXT:    ret <vscale x 4 x i32> [[TMP4]]
//
fixed_int32_t array_arg(fixed_int32_t arr[]) {
  return arr[0];
}

// CHECK-LABEL: @address_of_array_idx(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca <8 x i8>, align 2
// CHECK-NEXT:    [[ARR:%.*]] = alloca [3 x <8 x i8>], align 2
// CHECK-NEXT:    [[PARR:%.*]] = alloca <8 x i8>*, align 8
// CHECK-NEXT:    [[RETVAL_COERCE:%.*]] = alloca <vscale x 16 x i1>, align 16
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], [3 x <8 x i8>]* [[ARR]], i64 0, i64 0
// CHECK-NEXT:    store <8 x i8>* [[ARRAYIDX]], <8 x i8>** [[PARR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load <8 x i8>*, <8 x i8>** [[PARR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load <8 x i8>, <8 x i8>* [[TMP0]], align 2
// CHECK-NEXT:    store <8 x i8> [[TMP1]], <8 x i8>* [[RETVAL]], align 2
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <vscale x 16 x i1>* [[RETVAL_COERCE]] to i8*
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <8 x i8>* [[RETVAL]] to i8*
// CHECK-NEXT:    call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 [[TMP2]], i8* align 2 [[TMP3]], i64 8, i1 false)
// CHECK-NEXT:    [[TMP4:%.*]] = load <vscale x 16 x i1>, <vscale x 16 x i1>* [[RETVAL_COERCE]], align 16
// CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP4]]
//
fixed_bool_t address_of_array_idx() {
  fixed_bool_t arr[3];
  fixed_bool_t *parr;
  parr = &arr[0];
  return *parr;
}
