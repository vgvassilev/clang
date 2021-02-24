// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -target-cpu cyclone \
// RUN: -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s

// Test new aarch64 intrinsics and types

#include <arm_neon.h>


// CHECK-LABEL: @test_vmuls_lane_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <2 x float> [[B:%.*]], i32 1
// CHECK-NEXT:    [[MUL:%.*]] = fmul float [[A:%.*]], [[VGET_LANE]]
// CHECK-NEXT:    ret float [[MUL]]
//
float32_t test_vmuls_lane_f32(float32_t a, float32x2_t b) {
  return vmuls_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vmuld_lane_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <1 x double> [[B:%.*]], i32 0
// CHECK-NEXT:    [[MUL:%.*]] = fmul double [[A:%.*]], [[VGET_LANE]]
// CHECK-NEXT:    ret double [[MUL]]
//
float64_t test_vmuld_lane_f64(float64_t a, float64x1_t b) {
  return vmuld_lane_f64(a, b, 0);
}

// CHECK-LABEL: @test_vmuls_laneq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <4 x float> [[B:%.*]], i32 3
// CHECK-NEXT:    [[MUL:%.*]] = fmul float [[A:%.*]], [[VGETQ_LANE]]
// CHECK-NEXT:    ret float [[MUL]]
//
float32_t test_vmuls_laneq_f32(float32_t a, float32x4_t b) {
  return vmuls_laneq_f32(a, b, 3);
}

// CHECK-LABEL: @test_vmuld_laneq_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <2 x double> [[B:%.*]], i32 1
// CHECK-NEXT:    [[MUL:%.*]] = fmul double [[A:%.*]], [[VGETQ_LANE]]
// CHECK-NEXT:    ret double [[MUL]]
//
float64_t test_vmuld_laneq_f64(float64_t a, float64x2_t b) {
  return vmuld_laneq_f64(a, b, 1);
}

// CHECK-LABEL: @test_vmul_n_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <1 x double> [[A:%.*]] to double
// CHECK-NEXT:    [[TMP1:%.*]] = fmul double [[TMP0]], [[B:%.*]]
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast double [[TMP1]] to <1 x double>
// CHECK-NEXT:    ret <1 x double> [[TMP2]]
//
float64x1_t test_vmul_n_f64(float64x1_t a, float64_t b) {
  return vmul_n_f64(a, b);
}

// CHECK-LABEL: @test_vmulxs_lane_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <2 x float> [[B:%.*]], i32 1
// CHECK-NEXT:    [[VMULXS_F32_I:%.*]] = call float @llvm.aarch64.neon.fmulx.f32(float [[A:%.*]], float [[VGET_LANE]]) [[ATTR5:#.*]]
// CHECK-NEXT:    ret float [[VMULXS_F32_I]]
//
float32_t test_vmulxs_lane_f32(float32_t a, float32x2_t b) {
  return vmulxs_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vmulxs_laneq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <4 x float> [[B:%.*]], i32 3
// CHECK-NEXT:    [[VMULXS_F32_I:%.*]] = call float @llvm.aarch64.neon.fmulx.f32(float [[A:%.*]], float [[VGETQ_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret float [[VMULXS_F32_I]]
//
float32_t test_vmulxs_laneq_f32(float32_t a, float32x4_t b) {
  return vmulxs_laneq_f32(a, b, 3);
}

// CHECK-LABEL: @test_vmulxd_lane_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <1 x double> [[B:%.*]], i32 0
// CHECK-NEXT:    [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[A:%.*]], double [[VGET_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret double [[VMULXD_F64_I]]
//
float64_t test_vmulxd_lane_f64(float64_t a, float64x1_t b) {
  return vmulxd_lane_f64(a, b, 0);
}

// CHECK-LABEL: @test_vmulxd_laneq_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <2 x double> [[B:%.*]], i32 1
// CHECK-NEXT:    [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[A:%.*]], double [[VGETQ_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret double [[VMULXD_F64_I]]
//
float64_t test_vmulxd_laneq_f64(float64_t a, float64x2_t b) {
  return vmulxd_laneq_f64(a, b, 1);
}

// CHECK-LABEL: @test_vmulx_lane_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <1 x double> [[A:%.*]], i32 0
// CHECK-NEXT:    [[VGET_LANE3:%.*]] = extractelement <1 x double> [[B:%.*]], i32 0
// CHECK-NEXT:    [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGET_LANE3]]) [[ATTR5]]
// CHECK-NEXT:    [[VSET_LANE:%.*]] = insertelement <1 x double> [[A]], double [[VMULXD_F64_I]], i32 0
// CHECK-NEXT:    ret <1 x double> [[VSET_LANE]]
//
float64x1_t test_vmulx_lane_f64(float64x1_t a, float64x1_t b) {
  return vmulx_lane_f64(a, b, 0);
}


// CHECK-LABEL: @test_vmulx_laneq_f64_0(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <1 x double> [[A:%.*]], i32 0
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <2 x double> [[B:%.*]], i32 0
// CHECK-NEXT:    [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGETQ_LANE]]) [[ATTR5]]
// CHECK-NEXT:    [[VSET_LANE:%.*]] = insertelement <1 x double> [[A]], double [[VMULXD_F64_I]], i32 0
// CHECK-NEXT:    ret <1 x double> [[VSET_LANE]]
//
float64x1_t test_vmulx_laneq_f64_0(float64x1_t a, float64x2_t b) {
  return vmulx_laneq_f64(a, b, 0);
}

// CHECK-LABEL: @test_vmulx_laneq_f64_1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <1 x double> [[A:%.*]], i32 0
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <2 x double> [[B:%.*]], i32 1
// CHECK-NEXT:    [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGETQ_LANE]]) [[ATTR5]]
// CHECK-NEXT:    [[VSET_LANE:%.*]] = insertelement <1 x double> [[A]], double [[VMULXD_F64_I]], i32 0
// CHECK-NEXT:    ret <1 x double> [[VSET_LANE]]
//
float64x1_t test_vmulx_laneq_f64_1(float64x1_t a, float64x2_t b) {
  return vmulx_laneq_f64(a, b, 1);
}


// CHECK-LABEL: @test_vfmas_lane_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[EXTRACT:%.*]] = extractelement <2 x float> [[C:%.*]], i32 1
// CHECK-NEXT:    [[TMP0:%.*]] = call float @llvm.fma.f32(float [[B:%.*]], float [[EXTRACT]], float [[A:%.*]])
// CHECK-NEXT:    ret float [[TMP0]]
//
float32_t test_vfmas_lane_f32(float32_t a, float32_t b, float32x2_t c) {
  return vfmas_lane_f32(a, b, c, 1);
}

// CHECK-LABEL: @test_vfmad_lane_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[EXTRACT:%.*]] = extractelement <1 x double> [[C:%.*]], i32 0
// CHECK-NEXT:    [[TMP0:%.*]] = call double @llvm.fma.f64(double [[B:%.*]], double [[EXTRACT]], double [[A:%.*]])
// CHECK-NEXT:    ret double [[TMP0]]
//
float64_t test_vfmad_lane_f64(float64_t a, float64_t b, float64x1_t c) {
  return vfmad_lane_f64(a, b, c, 0);
}

// CHECK-LABEL: @test_vfmad_laneq_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[EXTRACT:%.*]] = extractelement <2 x double> [[C:%.*]], i32 1
// CHECK-NEXT:    [[TMP0:%.*]] = call double @llvm.fma.f64(double [[B:%.*]], double [[EXTRACT]], double [[A:%.*]])
// CHECK-NEXT:    ret double [[TMP0]]
//
float64_t test_vfmad_laneq_f64(float64_t a, float64_t b, float64x2_t c) {
  return vfmad_laneq_f64(a, b, c, 1);
}

// CHECK-LABEL: @test_vfmss_lane_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FNEG:%.*]] = fneg float [[B:%.*]]
// CHECK-NEXT:    [[EXTRACT:%.*]] = extractelement <2 x float> [[C:%.*]], i32 1
// CHECK-NEXT:    [[TMP0:%.*]] = call float @llvm.fma.f32(float [[FNEG]], float [[EXTRACT]], float [[A:%.*]])
// CHECK-NEXT:    ret float [[TMP0]]
//
float32_t test_vfmss_lane_f32(float32_t a, float32_t b, float32x2_t c) {
  return vfmss_lane_f32(a, b, c, 1);
}

// CHECK-LABEL: @test_vfma_lane_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <1 x double> [[A:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <1 x double> [[B:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <1 x double> [[V:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <8 x i8> [[TMP2]] to <1 x double>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <1 x double> [[TMP3]], <1 x double> [[TMP3]], <1 x i32> zeroinitializer
// CHECK-NEXT:    [[FMLA:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x double>
// CHECK-NEXT:    [[FMLA1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x double>
// CHECK-NEXT:    [[FMLA2:%.*]] = call <1 x double> @llvm.fma.v1f64(<1 x double> [[FMLA]], <1 x double> [[LANE]], <1 x double> [[FMLA1]])
// CHECK-NEXT:    ret <1 x double> [[FMLA2]]
//
float64x1_t test_vfma_lane_f64(float64x1_t a, float64x1_t b, float64x1_t v) {
  return vfma_lane_f64(a, b, v, 0);
}

// CHECK-LABEL: @test_vfms_lane_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FNEG:%.*]] = fneg <1 x double> [[B:%.*]]
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <1 x double> [[A:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <1 x double> [[FNEG]] to <8 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <1 x double> [[V:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <8 x i8> [[TMP2]] to <1 x double>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <1 x double> [[TMP3]], <1 x double> [[TMP3]], <1 x i32> zeroinitializer
// CHECK-NEXT:    [[FMLA:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x double>
// CHECK-NEXT:    [[FMLA1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x double>
// CHECK-NEXT:    [[FMLA2:%.*]] = call <1 x double> @llvm.fma.v1f64(<1 x double> [[FMLA]], <1 x double> [[LANE]], <1 x double> [[FMLA1]])
// CHECK-NEXT:    ret <1 x double> [[FMLA2]]
//
float64x1_t test_vfms_lane_f64(float64x1_t a, float64x1_t b, float64x1_t v) {
  return vfms_lane_f64(a, b, v, 0);
}

// CHECK-LABEL: @test_vfma_laneq_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <1 x double> [[A:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <1 x double> [[B:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <2 x double> [[V:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <8 x i8> [[TMP0]] to double
// CHECK-NEXT:    [[TMP4:%.*]] = bitcast <8 x i8> [[TMP1]] to double
// CHECK-NEXT:    [[TMP5:%.*]] = bitcast <16 x i8> [[TMP2]] to <2 x double>
// CHECK-NEXT:    [[EXTRACT:%.*]] = extractelement <2 x double> [[TMP5]], i32 0
// CHECK-NEXT:    [[TMP6:%.*]] = call double @llvm.fma.f64(double [[TMP4]], double [[EXTRACT]], double [[TMP3]])
// CHECK-NEXT:    [[TMP7:%.*]] = bitcast double [[TMP6]] to <1 x double>
// CHECK-NEXT:    ret <1 x double> [[TMP7]]
//
float64x1_t test_vfma_laneq_f64(float64x1_t a, float64x1_t b, float64x2_t v) {
  return vfma_laneq_f64(a, b, v, 0);
}

// CHECK-LABEL: @test_vfms_laneq_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FNEG:%.*]] = fneg <1 x double> [[B:%.*]]
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <1 x double> [[A:%.*]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <1 x double> [[FNEG]] to <8 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <2 x double> [[V:%.*]] to <16 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <8 x i8> [[TMP0]] to double
// CHECK-NEXT:    [[TMP4:%.*]] = bitcast <8 x i8> [[TMP1]] to double
// CHECK-NEXT:    [[TMP5:%.*]] = bitcast <16 x i8> [[TMP2]] to <2 x double>
// CHECK-NEXT:    [[EXTRACT:%.*]] = extractelement <2 x double> [[TMP5]], i32 0
// CHECK-NEXT:    [[TMP6:%.*]] = call double @llvm.fma.f64(double [[TMP4]], double [[EXTRACT]], double [[TMP3]])
// CHECK-NEXT:    [[TMP7:%.*]] = bitcast double [[TMP6]] to <1 x double>
// CHECK-NEXT:    ret <1 x double> [[TMP7]]
//
float64x1_t test_vfms_laneq_f64(float64x1_t a, float64x1_t b, float64x2_t v) {
  return vfms_laneq_f64(a, b, v, 0);
}

// CHECK-LABEL: @test_vqdmullh_lane_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <4 x i16> [[B:%.*]], i32 3
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[A:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[VGET_LANE]], i64 0
// CHECK-NEXT:    [[VQDMULLH_S16_I:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]]) [[ATTR5]]
// CHECK-NEXT:    [[TMP2:%.*]] = extractelement <4 x i32> [[VQDMULLH_S16_I]], i64 0
// CHECK-NEXT:    ret i32 [[TMP2]]
//
int32_t test_vqdmullh_lane_s16(int16_t a, int16x4_t b) {
  return vqdmullh_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vqdmulls_lane_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <2 x i32> [[B:%.*]], i32 1
// CHECK-NEXT:    [[VQDMULLS_S32_I:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 [[A:%.*]], i32 [[VGET_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret i64 [[VQDMULLS_S32_I]]
//
int64_t test_vqdmulls_lane_s32(int32_t a, int32x2_t b) {
  return vqdmulls_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vqdmullh_laneq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x i16> [[B:%.*]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[A:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[VGETQ_LANE]], i64 0
// CHECK-NEXT:    [[VQDMULLH_S16_I:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]]) [[ATTR5]]
// CHECK-NEXT:    [[TMP2:%.*]] = extractelement <4 x i32> [[VQDMULLH_S16_I]], i64 0
// CHECK-NEXT:    ret i32 [[TMP2]]
//
int32_t test_vqdmullh_laneq_s16(int16_t a, int16x8_t b) {
  return vqdmullh_laneq_s16(a, b, 7);
}

// CHECK-LABEL: @test_vqdmulls_laneq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <4 x i32> [[B:%.*]], i32 3
// CHECK-NEXT:    [[VQDMULLS_S32_I:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 [[A:%.*]], i32 [[VGETQ_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret i64 [[VQDMULLS_S32_I]]
//
int64_t test_vqdmulls_laneq_s32(int32_t a, int32x4_t b) {
  return vqdmulls_laneq_s32(a, b, 3);
}

// CHECK-LABEL: @test_vqdmulhh_lane_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <4 x i16> [[B:%.*]], i32 3
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[A:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[VGET_LANE]], i64 0
// CHECK-NEXT:    [[VQDMULHH_S16_I:%.*]] = call <4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]]) [[ATTR5]]
// CHECK-NEXT:    [[TMP2:%.*]] = extractelement <4 x i16> [[VQDMULHH_S16_I]], i64 0
// CHECK-NEXT:    ret i16 [[TMP2]]
//
int16_t test_vqdmulhh_lane_s16(int16_t a, int16x4_t b) {
  return vqdmulhh_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vqdmulhs_lane_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <2 x i32> [[B:%.*]], i32 1
// CHECK-NEXT:    [[VQDMULHS_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sqdmulh.i32(i32 [[A:%.*]], i32 [[VGET_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret i32 [[VQDMULHS_S32_I]]
//
int32_t test_vqdmulhs_lane_s32(int32_t a, int32x2_t b) {
  return vqdmulhs_lane_s32(a, b, 1);
}


// CHECK-LABEL: @test_vqdmulhh_laneq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x i16> [[B:%.*]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[A:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[VGETQ_LANE]], i64 0
// CHECK-NEXT:    [[VQDMULHH_S16_I:%.*]] = call <4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]]) [[ATTR5]]
// CHECK-NEXT:    [[TMP2:%.*]] = extractelement <4 x i16> [[VQDMULHH_S16_I]], i64 0
// CHECK-NEXT:    ret i16 [[TMP2]]
//
int16_t test_vqdmulhh_laneq_s16(int16_t a, int16x8_t b) {
  return vqdmulhh_laneq_s16(a, b, 7);
}


// CHECK-LABEL: @test_vqdmulhs_laneq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <4 x i32> [[B:%.*]], i32 3
// CHECK-NEXT:    [[VQDMULHS_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sqdmulh.i32(i32 [[A:%.*]], i32 [[VGETQ_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret i32 [[VQDMULHS_S32_I]]
//
int32_t test_vqdmulhs_laneq_s32(int32_t a, int32x4_t b) {
  return vqdmulhs_laneq_s32(a, b, 3);
}

// CHECK-LABEL: @test_vqrdmulhh_lane_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <4 x i16> [[B:%.*]], i32 3
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[A:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[VGET_LANE]], i64 0
// CHECK-NEXT:    [[VQRDMULHH_S16_I:%.*]] = call <4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]]) [[ATTR5]]
// CHECK-NEXT:    [[TMP2:%.*]] = extractelement <4 x i16> [[VQRDMULHH_S16_I]], i64 0
// CHECK-NEXT:    ret i16 [[TMP2]]
//
int16_t test_vqrdmulhh_lane_s16(int16_t a, int16x4_t b) {
  return vqrdmulhh_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vqrdmulhs_lane_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <2 x i32> [[B:%.*]], i32 1
// CHECK-NEXT:    [[VQRDMULHS_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sqrdmulh.i32(i32 [[A:%.*]], i32 [[VGET_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret i32 [[VQRDMULHS_S32_I]]
//
int32_t test_vqrdmulhs_lane_s32(int32_t a, int32x2_t b) {
  return vqrdmulhs_lane_s32(a, b, 1);
}


// CHECK-LABEL: @test_vqrdmulhh_laneq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x i16> [[B:%.*]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[A:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[VGETQ_LANE]], i64 0
// CHECK-NEXT:    [[VQRDMULHH_S16_I:%.*]] = call <4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]]) [[ATTR5]]
// CHECK-NEXT:    [[TMP2:%.*]] = extractelement <4 x i16> [[VQRDMULHH_S16_I]], i64 0
// CHECK-NEXT:    ret i16 [[TMP2]]
//
int16_t test_vqrdmulhh_laneq_s16(int16_t a, int16x8_t b) {
  return vqrdmulhh_laneq_s16(a, b, 7);
}


// CHECK-LABEL: @test_vqrdmulhs_laneq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <4 x i32> [[B:%.*]], i32 3
// CHECK-NEXT:    [[VQRDMULHS_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sqrdmulh.i32(i32 [[A:%.*]], i32 [[VGETQ_LANE]]) [[ATTR5]]
// CHECK-NEXT:    ret i32 [[VQRDMULHS_S32_I]]
//
int32_t test_vqrdmulhs_laneq_s32(int32_t a, int32x4_t b) {
  return vqrdmulhs_laneq_s32(a, b, 3);
}

// CHECK-LABEL: @test_vqdmlalh_lane_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LANE:%.*]] = extractelement <4 x i16> [[C:%.*]], i32 3
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[B:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[LANE]], i64 0
// CHECK-NEXT:    [[VQDMLXL:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]])
// CHECK-NEXT:    [[LANE0:%.*]] = extractelement <4 x i32> [[VQDMLXL]], i64 0
// CHECK-NEXT:    [[VQDMLXL1:%.*]] = call i32 @llvm.aarch64.neon.sqadd.i32(i32 [[A:%.*]], i32 [[LANE0]])
// CHECK-NEXT:    ret i32 [[VQDMLXL1]]
//
int32_t test_vqdmlalh_lane_s16(int32_t a, int16_t b, int16x4_t c) {
  return vqdmlalh_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vqdmlals_lane_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LANE:%.*]] = extractelement <2 x i32> [[C:%.*]], i32 1
// CHECK-NEXT:    [[VQDMLXL:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 [[B:%.*]], i32 [[LANE]])
// CHECK-NEXT:    [[VQDMLXL1:%.*]] = call i64 @llvm.aarch64.neon.sqadd.i64(i64 [[A:%.*]], i64 [[VQDMLXL]])
// CHECK-NEXT:    ret i64 [[VQDMLXL1]]
//
int64_t test_vqdmlals_lane_s32(int64_t a, int32_t b, int32x2_t c) {
  return vqdmlals_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vqdmlalh_laneq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LANE:%.*]] = extractelement <8 x i16> [[C:%.*]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[B:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[LANE]], i64 0
// CHECK-NEXT:    [[VQDMLXL:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]])
// CHECK-NEXT:    [[LANE0:%.*]] = extractelement <4 x i32> [[VQDMLXL]], i64 0
// CHECK-NEXT:    [[VQDMLXL1:%.*]] = call i32 @llvm.aarch64.neon.sqadd.i32(i32 [[A:%.*]], i32 [[LANE0]])
// CHECK-NEXT:    ret i32 [[VQDMLXL1]]
//
int32_t test_vqdmlalh_laneq_s16(int32_t a, int16_t b, int16x8_t c) {
  return vqdmlalh_laneq_s16(a, b, c, 7);
}

// CHECK-LABEL: @test_vqdmlals_laneq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LANE:%.*]] = extractelement <4 x i32> [[C:%.*]], i32 3
// CHECK-NEXT:    [[VQDMLXL:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 [[B:%.*]], i32 [[LANE]])
// CHECK-NEXT:    [[VQDMLXL1:%.*]] = call i64 @llvm.aarch64.neon.sqadd.i64(i64 [[A:%.*]], i64 [[VQDMLXL]])
// CHECK-NEXT:    ret i64 [[VQDMLXL1]]
//
int64_t test_vqdmlals_laneq_s32(int64_t a, int32_t b, int32x4_t c) {
  return vqdmlals_laneq_s32(a, b, c, 3);
}

// CHECK-LABEL: @test_vqdmlslh_lane_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LANE:%.*]] = extractelement <4 x i16> [[C:%.*]], i32 3
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[B:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[LANE]], i64 0
// CHECK-NEXT:    [[VQDMLXL:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]])
// CHECK-NEXT:    [[LANE0:%.*]] = extractelement <4 x i32> [[VQDMLXL]], i64 0
// CHECK-NEXT:    [[VQDMLXL1:%.*]] = call i32 @llvm.aarch64.neon.sqsub.i32(i32 [[A:%.*]], i32 [[LANE0]])
// CHECK-NEXT:    ret i32 [[VQDMLXL1]]
//
int32_t test_vqdmlslh_lane_s16(int32_t a, int16_t b, int16x4_t c) {
  return vqdmlslh_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vqdmlsls_lane_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LANE:%.*]] = extractelement <2 x i32> [[C:%.*]], i32 1
// CHECK-NEXT:    [[VQDMLXL:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 [[B:%.*]], i32 [[LANE]])
// CHECK-NEXT:    [[VQDMLXL1:%.*]] = call i64 @llvm.aarch64.neon.sqsub.i64(i64 [[A:%.*]], i64 [[VQDMLXL]])
// CHECK-NEXT:    ret i64 [[VQDMLXL1]]
//
int64_t test_vqdmlsls_lane_s32(int64_t a, int32_t b, int32x2_t c) {
  return vqdmlsls_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vqdmlslh_laneq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LANE:%.*]] = extractelement <8 x i16> [[C:%.*]], i32 7
// CHECK-NEXT:    [[TMP0:%.*]] = insertelement <4 x i16> undef, i16 [[B:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = insertelement <4 x i16> undef, i16 [[LANE]], i64 0
// CHECK-NEXT:    [[VQDMLXL:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP0]], <4 x i16> [[TMP1]])
// CHECK-NEXT:    [[LANE0:%.*]] = extractelement <4 x i32> [[VQDMLXL]], i64 0
// CHECK-NEXT:    [[VQDMLXL1:%.*]] = call i32 @llvm.aarch64.neon.sqsub.i32(i32 [[A:%.*]], i32 [[LANE0]])
// CHECK-NEXT:    ret i32 [[VQDMLXL1]]
//
int32_t test_vqdmlslh_laneq_s16(int32_t a, int16_t b, int16x8_t c) {
  return vqdmlslh_laneq_s16(a, b, c, 7);
}

// CHECK-LABEL: @test_vqdmlsls_laneq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LANE:%.*]] = extractelement <4 x i32> [[C:%.*]], i32 3
// CHECK-NEXT:    [[VQDMLXL:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 [[B:%.*]], i32 [[LANE]])
// CHECK-NEXT:    [[VQDMLXL1:%.*]] = call i64 @llvm.aarch64.neon.sqsub.i64(i64 [[A:%.*]], i64 [[VQDMLXL]])
// CHECK-NEXT:    ret i64 [[VQDMLXL1]]
//
int64_t test_vqdmlsls_laneq_s32(int64_t a, int32_t b, int32x4_t c) {
  return vqdmlsls_laneq_s32(a, b, c, 3);
}

// CHECK-LABEL: @test_vmulx_lane_f64_0(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i64 4599917171378402754 to <1 x double>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast i64 4606655882138939123 to <1 x double>
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <1 x double> [[TMP0]], i32 0
// CHECK-NEXT:    [[VGET_LANE8:%.*]] = extractelement <1 x double> [[TMP1]], i32 0
// CHECK-NEXT:    [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGET_LANE8]]) [[ATTR5]]
// CHECK-NEXT:    [[VSET_LANE:%.*]] = insertelement <1 x double> [[TMP0]], double [[VMULXD_F64_I]], i32 0
// CHECK-NEXT:    ret <1 x double> [[VSET_LANE]]
//
float64x1_t test_vmulx_lane_f64_0() {
      float64x1_t arg1;
      float64x1_t arg2;
      float64x1_t result;
      float64_t sarg1, sarg2, sres;
      arg1 = vcreate_f64(UINT64_C(0x3fd6304bc43ab5c2));
      arg2 = vcreate_f64(UINT64_C(0x3fee211e215aeef3));
      result = vmulx_lane_f64(arg1, arg2, 0);
      return result;
}

// CHECK-LABEL: @test_vmulx_laneq_f64_2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast i64 4599917171378402754 to <1 x double>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast i64 4606655882138939123 to <1 x double>
// CHECK-NEXT:    [[SHUFFLE_I:%.*]] = shufflevector <1 x double> [[TMP0]], <1 x double> [[TMP1]], <2 x i32> <i32 0, i32 1>
// CHECK-NEXT:    [[VGET_LANE:%.*]] = extractelement <1 x double> [[TMP0]], i32 0
// CHECK-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <2 x double> [[SHUFFLE_I]], i32 1
// CHECK-NEXT:    [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGETQ_LANE]]) [[ATTR5]]
// CHECK-NEXT:    [[VSET_LANE:%.*]] = insertelement <1 x double> [[TMP0]], double [[VMULXD_F64_I]], i32 0
// CHECK-NEXT:    ret <1 x double> [[VSET_LANE]]
//
float64x1_t test_vmulx_laneq_f64_2() {
      float64x1_t arg1;
      float64x1_t arg2;
      float64x2_t arg3;
      float64x1_t result;
      float64_t sarg1, sarg2, sres;
      arg1 = vcreate_f64(UINT64_C(0x3fd6304bc43ab5c2));
      arg2 = vcreate_f64(UINT64_C(0x3fee211e215aeef3));
      arg3 = vcombine_f64(arg1, arg2);
      result = vmulx_laneq_f64(arg1, arg3, 1);
      return result;
}

// CHECK: attributes #0 ={{.*}}"min-legal-vector-width"="64"
// CHECK: attributes #1 ={{.*}}"min-legal-vector-width"="128"
