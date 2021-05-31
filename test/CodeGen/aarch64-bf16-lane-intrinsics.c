// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64-arm-none-eabi -target-feature +neon -target-feature +bf16 \
// RUN:  -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg -instcombine | FileCheck --check-prefix=CHECK-LE %s
// RUN: %clang_cc1 -triple aarch64_be-arm-none-eabi -target-feature +neon -target-feature +bf16 \
// RUN:  -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg -instcombine | FileCheck --check-prefix=CHECK-BE %s

#include <arm_neon.h>

// CHECK-LE-LABEL: @test_vcopy_lane_bf16_v1(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <4 x bfloat> [[A:%.*]], <4 x bfloat> [[B:%.*]], <4 x i32> <i32 0, i32 7, i32 2, i32 3>
// CHECK-LE-NEXT:    ret <4 x bfloat> [[VSET_LANE]]
//
// CHECK-BE-LABEL: @test_vcopy_lane_bf16_v1(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[SHUFFLE:%.*]] = shufflevector <4 x bfloat> [[A:%.*]], <4 x bfloat> undef, <4 x i32> <i32 3, i32 undef, i32 1, i32 0>
// CHECK-BE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <4 x bfloat> [[SHUFFLE]], <4 x bfloat> [[B:%.*]], <4 x i32> <i32 0, i32 4, i32 2, i32 3>
// CHECK-BE-NEXT:    [[SHUFFLE5:%.*]] = shufflevector <4 x bfloat> [[VSET_LANE]], <4 x bfloat> undef, <4 x i32> <i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    ret <4 x bfloat> [[SHUFFLE5]]
//
bfloat16x4_t test_vcopy_lane_bf16_v1(bfloat16x4_t a, bfloat16x4_t b) {
  return vcopy_lane_bf16(a, 1, b, 3);
}

// CHECK-LE-LABEL: @test_vcopy_lane_bf16_v2(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <4 x bfloat> [[A:%.*]], <4 x bfloat> [[B:%.*]], <4 x i32> <i32 0, i32 1, i32 4, i32 3>
// CHECK-LE-NEXT:    ret <4 x bfloat> [[VSET_LANE]]
//
// CHECK-BE-LABEL: @test_vcopy_lane_bf16_v2(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[SHUFFLE:%.*]] = shufflevector <4 x bfloat> [[A:%.*]], <4 x bfloat> undef, <4 x i32> <i32 3, i32 2, i32 undef, i32 0>
// CHECK-BE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <4 x bfloat> [[SHUFFLE]], <4 x bfloat> [[B:%.*]], <4 x i32> <i32 0, i32 1, i32 7, i32 3>
// CHECK-BE-NEXT:    [[SHUFFLE5:%.*]] = shufflevector <4 x bfloat> [[VSET_LANE]], <4 x bfloat> undef, <4 x i32> <i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    ret <4 x bfloat> [[SHUFFLE5]]
//
bfloat16x4_t test_vcopy_lane_bf16_v2(bfloat16x4_t a, bfloat16x4_t b) {
  return vcopy_lane_bf16(a, 2, b, 0);
}

// CHECK-LE-LABEL: @test_vcopyq_lane_bf16_v1(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[TMP0:%.*]] = shufflevector <4 x bfloat> [[B:%.*]], <4 x bfloat> poison, <8 x i32> <i32 undef, i32 undef, i32 2, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
// CHECK-LE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <8 x bfloat> [[A:%.*]], <8 x bfloat> [[TMP0]], <8 x i32> <i32 10, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK-LE-NEXT:    ret <8 x bfloat> [[VSET_LANE]]
//
// CHECK-BE-LABEL: @test_vcopyq_lane_bf16_v1(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[TMP0:%.*]] = shufflevector <4 x bfloat> [[B:%.*]], <4 x bfloat> poison, <8 x i32> <i32 undef, i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
// CHECK-BE-NEXT:    [[SHUFFLE:%.*]] = shufflevector <8 x bfloat> [[A:%.*]], <8 x bfloat> undef, <8 x i32> <i32 undef, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <8 x bfloat> [[SHUFFLE]], <8 x bfloat> [[TMP0]], <8 x i32> <i32 9, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK-BE-NEXT:    [[SHUFFLE5:%.*]] = shufflevector <8 x bfloat> [[VSET_LANE]], <8 x bfloat> undef, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    ret <8 x bfloat> [[SHUFFLE5]]
//
bfloat16x8_t test_vcopyq_lane_bf16_v1(bfloat16x8_t a, bfloat16x4_t b) {
  return vcopyq_lane_bf16(a, 0, b, 2);
}

// CHECK-LE-LABEL: @test_vcopyq_lane_bf16_v2(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[TMP0:%.*]] = shufflevector <4 x bfloat> [[B:%.*]], <4 x bfloat> poison, <8 x i32> <i32 0, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
// CHECK-LE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <8 x bfloat> [[A:%.*]], <8 x bfloat> [[TMP0]], <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 8, i32 7>
// CHECK-LE-NEXT:    ret <8 x bfloat> [[VSET_LANE]]
//
// CHECK-BE-LABEL: @test_vcopyq_lane_bf16_v2(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[TMP0:%.*]] = shufflevector <4 x bfloat> [[B:%.*]], <4 x bfloat> poison, <8 x i32> <i32 undef, i32 undef, i32 undef, i32 3, i32 undef, i32 undef, i32 undef, i32 undef>
// CHECK-BE-NEXT:    [[SHUFFLE:%.*]] = shufflevector <8 x bfloat> [[A:%.*]], <8 x bfloat> undef, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 undef, i32 0>
// CHECK-BE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <8 x bfloat> [[SHUFFLE]], <8 x bfloat> [[TMP0]], <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 11, i32 7>
// CHECK-BE-NEXT:    [[SHUFFLE5:%.*]] = shufflevector <8 x bfloat> [[VSET_LANE]], <8 x bfloat> undef, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    ret <8 x bfloat> [[SHUFFLE5]]
//
bfloat16x8_t test_vcopyq_lane_bf16_v2(bfloat16x8_t a, bfloat16x4_t b) {
  return vcopyq_lane_bf16(a, 6, b, 0);
}

// CHECK-LE-LABEL: @test_vcopy_laneq_bf16_v1(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x bfloat> [[B:%.*]], i32 7
// CHECK-LE-NEXT:    [[VSET_LANE:%.*]] = insertelement <4 x bfloat> [[A:%.*]], bfloat [[VGETQ_LANE]], i32 0
// CHECK-LE-NEXT:    ret <4 x bfloat> [[VSET_LANE]]
//
// CHECK-BE-LABEL: @test_vcopy_laneq_bf16_v1(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[SHUFFLE:%.*]] = shufflevector <4 x bfloat> [[A:%.*]], <4 x bfloat> undef, <4 x i32> <i32 undef, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x bfloat> [[B:%.*]], i32 0
// CHECK-BE-NEXT:    [[VSET_LANE:%.*]] = insertelement <4 x bfloat> [[SHUFFLE]], bfloat [[VGETQ_LANE]], i32 0
// CHECK-BE-NEXT:    [[SHUFFLE5:%.*]] = shufflevector <4 x bfloat> [[VSET_LANE]], <4 x bfloat> undef, <4 x i32> <i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    ret <4 x bfloat> [[SHUFFLE5]]
//
bfloat16x4_t test_vcopy_laneq_bf16_v1(bfloat16x4_t a, bfloat16x8_t b) {
  return vcopy_laneq_bf16(a, 0, b, 7);
}

// CHECK-LE-LABEL: @test_vcopy_laneq_bf16_v2(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x bfloat> [[B:%.*]], i32 4
// CHECK-LE-NEXT:    [[VSET_LANE:%.*]] = insertelement <4 x bfloat> [[A:%.*]], bfloat [[VGETQ_LANE]], i32 3
// CHECK-LE-NEXT:    ret <4 x bfloat> [[VSET_LANE]]
//
// CHECK-BE-LABEL: @test_vcopy_laneq_bf16_v2(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[SHUFFLE:%.*]] = shufflevector <4 x bfloat> [[A:%.*]], <4 x bfloat> undef, <4 x i32> <i32 3, i32 2, i32 1, i32 undef>
// CHECK-BE-NEXT:    [[VGETQ_LANE:%.*]] = extractelement <8 x bfloat> [[B:%.*]], i32 3
// CHECK-BE-NEXT:    [[VSET_LANE:%.*]] = insertelement <4 x bfloat> [[SHUFFLE]], bfloat [[VGETQ_LANE]], i32 3
// CHECK-BE-NEXT:    [[SHUFFLE5:%.*]] = shufflevector <4 x bfloat> [[VSET_LANE]], <4 x bfloat> undef, <4 x i32> <i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    ret <4 x bfloat> [[SHUFFLE5]]
//
bfloat16x4_t test_vcopy_laneq_bf16_v2(bfloat16x4_t a, bfloat16x8_t b) {
  return vcopy_laneq_bf16(a, 3, b, 4);
}

// CHECK-LE-LABEL: @test_vcopyq_laneq_bf16_v1(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <8 x bfloat> [[A:%.*]], <8 x bfloat> [[B:%.*]], <8 x i32> <i32 0, i32 1, i32 2, i32 15, i32 4, i32 5, i32 6, i32 7>
// CHECK-LE-NEXT:    ret <8 x bfloat> [[VSET_LANE]]
//
// CHECK-BE-LABEL: @test_vcopyq_laneq_bf16_v1(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[SHUFFLE:%.*]] = shufflevector <8 x bfloat> [[A:%.*]], <8 x bfloat> undef, <8 x i32> <i32 7, i32 6, i32 5, i32 undef, i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <8 x bfloat> [[SHUFFLE]], <8 x bfloat> [[B:%.*]], <8 x i32> <i32 0, i32 1, i32 2, i32 8, i32 4, i32 5, i32 6, i32 7>
// CHECK-BE-NEXT:    [[SHUFFLE5:%.*]] = shufflevector <8 x bfloat> [[VSET_LANE]], <8 x bfloat> undef, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    ret <8 x bfloat> [[SHUFFLE5]]
//
bfloat16x8_t test_vcopyq_laneq_bf16_v1(bfloat16x8_t a, bfloat16x8_t b) {
  return vcopyq_laneq_bf16(a, 3, b, 7);

}

// CHECK-LE-LABEL: @test_vcopyq_laneq_bf16_v2(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <8 x bfloat> [[A:%.*]], <8 x bfloat> [[B:%.*]], <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 10, i32 7>
// CHECK-LE-NEXT:    ret <8 x bfloat> [[VSET_LANE]]
//
// CHECK-BE-LABEL: @test_vcopyq_laneq_bf16_v2(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[SHUFFLE:%.*]] = shufflevector <8 x bfloat> [[A:%.*]], <8 x bfloat> undef, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 undef, i32 0>
// CHECK-BE-NEXT:    [[VSET_LANE:%.*]] = shufflevector <8 x bfloat> [[SHUFFLE]], <8 x bfloat> [[B:%.*]], <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 13, i32 7>
// CHECK-BE-NEXT:    [[SHUFFLE5:%.*]] = shufflevector <8 x bfloat> [[VSET_LANE]], <8 x bfloat> undef, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
// CHECK-BE-NEXT:    ret <8 x bfloat> [[SHUFFLE5]]
//
bfloat16x8_t test_vcopyq_laneq_bf16_v2(bfloat16x8_t a, bfloat16x8_t b) {
  return vcopyq_laneq_bf16(a, 6, b, 2);
}

