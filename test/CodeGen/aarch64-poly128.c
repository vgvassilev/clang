// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
// RUN: -disable-O0-optnone -ffp-contract=fast -emit-llvm -o - %s | opt -S -mem2reg \
// RUN:  | FileCheck %s

// Test new aarch64 intrinsics with poly128
// FIXME: Currently, poly128_t equals to uint128, which will be spilt into
// two 64-bit GPR(eg X0, X1). Now moving data from X0, X1 to FPR128 will
// introduce 2 store and 1 load instructions(store X0, X1 to memory and
// then load back to Q0). If target has NEON, this is better replaced by
// FMOV or INS.

#include <arm_neon.h>

// CHECK-LABEL: @test_vstrq_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128* [[PTR:%.*]] to i8*
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast i8* [[TMP0]] to i128*
// CHECK-NEXT:    store i128 [[VAL:%.*]], i128* [[TMP1]], align 16
// CHECK-NEXT:    ret void
//
void test_vstrq_p128(poly128_t * ptr, poly128_t val) {
  vstrq_p128(ptr, val);

}

// CHECK-LABEL: @test_vldrq_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128* [[PTR:%.*]] to i8*
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast i8* [[TMP0]] to i128*
// CHECK-NEXT:    [[TMP2:%.*]] = load i128, i128* [[TMP1]], align 16
// CHECK-NEXT:    ret i128 [[TMP2]]
//
poly128_t test_vldrq_p128(poly128_t * ptr) {
  return vldrq_p128(ptr);

}

// CHECK-LABEL: @test_ld_st_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128* [[PTR:%.*]] to i8*
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast i8* [[TMP0]] to i128*
// CHECK-NEXT:    [[TMP2:%.*]] = load i128, i128* [[TMP1]], align 16
// CHECK-NEXT:    [[ADD_PTR:%.*]] = getelementptr inbounds i128, i128* [[PTR]], i64 1
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast i128* [[ADD_PTR]] to i8*
// CHECK-NEXT:    [[TMP4:%.*]] = bitcast i8* [[TMP3]] to i128*
// CHECK-NEXT:    store i128 [[TMP2]], i128* [[TMP4]], align 16
// CHECK-NEXT:    ret void
//
void test_ld_st_p128(poly128_t * ptr) {
   vstrq_p128(ptr+1, vldrq_p128(ptr));

}

// CHECK-LABEL: @test_vmull_p64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VMULL_P64_I:%.*]] = call <16 x i8> @llvm.aarch64.neon.pmull64(i64 [[A:%.*]], i64 [[B:%.*]]) [[ATTR3:#.*]]
// CHECK-NEXT:    [[VMULL_P641_I:%.*]] = bitcast <16 x i8> [[VMULL_P64_I]] to i128
// CHECK-NEXT:    ret i128 [[VMULL_P641_I]]
//
poly128_t test_vmull_p64(poly64_t a, poly64_t b) {
  return vmull_p64(a, b);
}

// CHECK-LABEL: @test_vmull_high_p64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[SHUFFLE_I_I:%.*]] = shufflevector <2 x i64> [[A:%.*]], <2 x i64> [[A]], <1 x i32> <i32 1>
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <1 x i64> [[SHUFFLE_I_I]] to i64
// CHECK-NEXT:    [[SHUFFLE_I7_I:%.*]] = shufflevector <2 x i64> [[B:%.*]], <2 x i64> [[B]], <1 x i32> <i32 1>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <1 x i64> [[SHUFFLE_I7_I]] to i64
// CHECK-NEXT:    [[VMULL_P64_I_I:%.*]] = call <16 x i8> @llvm.aarch64.neon.pmull64(i64 [[TMP0]], i64 [[TMP1]]) [[ATTR3]]
// CHECK-NEXT:    [[VMULL_P641_I_I:%.*]] = bitcast <16 x i8> [[VMULL_P64_I_I]] to i128
// CHECK-NEXT:    ret i128 [[VMULL_P641_I_I]]
//
poly128_t test_vmull_high_p64(poly64x2_t a, poly64x2_t b) {
  return vmull_high_p64(a, b);
}

// CHECK-LABEL: @test_vreinterpretq_p128_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <16 x i8> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_s8(int8x16_t a) {
  return vreinterpretq_p128_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <8 x i16> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_s16(int16x8_t a) {
  return vreinterpretq_p128_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x i32> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_s32(int32x4_t a) {
  return vreinterpretq_p128_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x i64> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_s64(int64x2_t a) {
  return vreinterpretq_p128_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <16 x i8> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_u8(uint8x16_t a) {
  return vreinterpretq_p128_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <8 x i16> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_u16(uint16x8_t a) {
  return vreinterpretq_p128_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x i32> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_u32(uint32x4_t a) {
  return vreinterpretq_p128_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x i64> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_u64(uint64x2_t a) {
  return vreinterpretq_p128_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_f32(float32x4_t a) {
  return vreinterpretq_p128_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x double> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_f64(float64x2_t a) {
  return vreinterpretq_p128_f64(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_p8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <16 x i8> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_p8(poly8x16_t a) {
  return vreinterpretq_p128_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_p16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <8 x i16> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_p16(poly16x8_t a) {
  return vreinterpretq_p128_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p128_p64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x i64> [[A:%.*]] to i128
// CHECK-NEXT:    ret i128 [[TMP0]]
//
poly128_t test_vreinterpretq_p128_p64(poly64x2_t a) {
  return vreinterpretq_p128_p64(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vreinterpretq_s8_p128(poly128_t a) {
  return vreinterpretq_s8_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vreinterpretq_s16_p128(poly128_t  a) {
  return vreinterpretq_s16_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vreinterpretq_s32_p128(poly128_t a) {
  return vreinterpretq_s32_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <2 x i64>
// CHECK-NEXT:    ret <2 x i64> [[TMP0]]
//
int64x2_t test_vreinterpretq_s64_p128(poly128_t  a) {
  return vreinterpretq_s64_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
uint8x16_t test_vreinterpretq_u8_p128(poly128_t  a) {
  return vreinterpretq_u8_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
uint16x8_t test_vreinterpretq_u16_p128(poly128_t  a) {
  return vreinterpretq_u16_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
uint32x4_t test_vreinterpretq_u32_p128(poly128_t  a) {
  return vreinterpretq_u32_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <2 x i64>
// CHECK-NEXT:    ret <2 x i64> [[TMP0]]
//
uint64x2_t test_vreinterpretq_u64_p128(poly128_t  a) {
  return vreinterpretq_u64_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <4 x float>
// CHECK-NEXT:    ret <4 x float> [[TMP0]]
//
float32x4_t test_vreinterpretq_f32_p128(poly128_t  a) {
  return vreinterpretq_f32_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_f64_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <2 x double>
// CHECK-NEXT:    ret <2 x double> [[TMP0]]
//
float64x2_t test_vreinterpretq_f64_p128(poly128_t  a) {
  return vreinterpretq_f64_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <16 x i8>
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
poly8x16_t test_vreinterpretq_p8_p128(poly128_t  a) {
  return vreinterpretq_p8_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
poly16x8_t test_vreinterpretq_p16_p128(poly128_t  a) {
  return vreinterpretq_p16_p128(a);
}

// CHECK-LABEL: @test_vreinterpretq_p64_p128(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i128 [[A:%.*]] to <2 x i64>
// CHECK-NEXT:    ret <2 x i64> [[TMP0]]
//
poly64x2_t test_vreinterpretq_p64_p128(poly128_t  a) {
  return vreinterpretq_p64_p128(a);
}


