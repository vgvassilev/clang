// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv32 -target-feature +f -target-feature +d -target-feature +experimental-v \
// RUN:   -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV32 %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +f -target-feature +d -target-feature +experimental-v \
// RUN:   -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV32-LABEL: @test_vfwmsac_vv_f64m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwmsac.nxv1f64.nxv1f32.nxv1f32.i32(<vscale x 1 x double> [[ACC:%.*]], <vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i32 [[VL:%.*]]) [[ATTR5:#.*]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vv_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwmsac.nxv1f64.nxv1f32.nxv1f32.i64(<vscale x 1 x double> [[ACC:%.*]], <vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i64 [[VL:%.*]]) [[ATTR5:#.*]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwmsac_vv_f64m1(vfloat64m1_t acc, vfloat32mf2_t op1,
                                   vfloat32mf2_t op2, size_t vl) {
  return vfwmsac(acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vf_f64m1(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwmsac.nxv1f64.f32.nxv1f32.i32(<vscale x 1 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vf_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwmsac.nxv1f64.f32.nxv1f32.i64(<vscale x 1 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwmsac_vf_f64m1(vfloat64m1_t acc, float op1,
                                   vfloat32mf2_t op2, size_t vl) {
  return vfwmsac(acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vv_f64m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwmsac.nxv2f64.nxv2f32.nxv2f32.i32(<vscale x 2 x double> [[ACC:%.*]], <vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vv_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwmsac.nxv2f64.nxv2f32.nxv2f32.i64(<vscale x 2 x double> [[ACC:%.*]], <vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwmsac_vv_f64m2(vfloat64m2_t acc, vfloat32m1_t op1,
                                   vfloat32m1_t op2, size_t vl) {
  return vfwmsac(acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vf_f64m2(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwmsac.nxv2f64.f32.nxv2f32.i32(<vscale x 2 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vf_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwmsac.nxv2f64.f32.nxv2f32.i64(<vscale x 2 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwmsac_vf_f64m2(vfloat64m2_t acc, float op1,
                                   vfloat32m1_t op2, size_t vl) {
  return vfwmsac(acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vv_f64m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwmsac.nxv4f64.nxv4f32.nxv4f32.i32(<vscale x 4 x double> [[ACC:%.*]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vv_f64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwmsac.nxv4f64.nxv4f32.nxv4f32.i64(<vscale x 4 x double> [[ACC:%.*]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwmsac_vv_f64m4(vfloat64m4_t acc, vfloat32m2_t op1,
                                   vfloat32m2_t op2, size_t vl) {
  return vfwmsac(acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vf_f64m4(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwmsac.nxv4f64.f32.nxv4f32.i32(<vscale x 4 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vf_f64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwmsac.nxv4f64.f32.nxv4f32.i64(<vscale x 4 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwmsac_vf_f64m4(vfloat64m4_t acc, float op1,
                                   vfloat32m2_t op2, size_t vl) {
  return vfwmsac(acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vv_f64m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwmsac.nxv8f64.nxv8f32.nxv8f32.i32(<vscale x 8 x double> [[ACC:%.*]], <vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vv_f64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwmsac.nxv8f64.nxv8f32.nxv8f32.i64(<vscale x 8 x double> [[ACC:%.*]], <vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwmsac_vv_f64m8(vfloat64m8_t acc, vfloat32m4_t op1,
                                   vfloat32m4_t op2, size_t vl) {
  return vfwmsac(acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vf_f64m8(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwmsac.nxv8f64.f32.nxv8f32.i32(<vscale x 8 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vf_f64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwmsac.nxv8f64.f32.nxv8f32.i64(<vscale x 8 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwmsac_vf_f64m8(vfloat64m8_t acc, float op1,
                                   vfloat32m4_t op2, size_t vl) {
  return vfwmsac(acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vv_f64m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwmsac.mask.nxv1f64.nxv1f32.nxv1f32.i32(<vscale x 1 x double> [[ACC:%.*]], <vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vv_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwmsac.mask.nxv1f64.nxv1f32.nxv1f32.i64(<vscale x 1 x double> [[ACC:%.*]], <vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwmsac_vv_f64m1_m(vbool64_t mask, vfloat64m1_t acc,
                                     vfloat32mf2_t op1, vfloat32mf2_t op2,
                                     size_t vl) {
  return vfwmsac(mask, acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vf_f64m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwmsac.mask.nxv1f64.f32.nxv1f32.i32(<vscale x 1 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vf_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwmsac.mask.nxv1f64.f32.nxv1f32.i64(<vscale x 1 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwmsac_vf_f64m1_m(vbool64_t mask, vfloat64m1_t acc,
                                     float op1, vfloat32mf2_t op2, size_t vl) {
  return vfwmsac(mask, acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vv_f64m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwmsac.mask.nxv2f64.nxv2f32.nxv2f32.i32(<vscale x 2 x double> [[ACC:%.*]], <vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vv_f64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwmsac.mask.nxv2f64.nxv2f32.nxv2f32.i64(<vscale x 2 x double> [[ACC:%.*]], <vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwmsac_vv_f64m2_m(vbool32_t mask, vfloat64m2_t acc,
                                     vfloat32m1_t op1, vfloat32m1_t op2,
                                     size_t vl) {
  return vfwmsac(mask, acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vf_f64m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwmsac.mask.nxv2f64.f32.nxv2f32.i32(<vscale x 2 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vf_f64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwmsac.mask.nxv2f64.f32.nxv2f32.i64(<vscale x 2 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwmsac_vf_f64m2_m(vbool32_t mask, vfloat64m2_t acc,
                                     float op1, vfloat32m1_t op2, size_t vl) {
  return vfwmsac(mask, acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vv_f64m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwmsac.mask.nxv4f64.nxv4f32.nxv4f32.i32(<vscale x 4 x double> [[ACC:%.*]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vv_f64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwmsac.mask.nxv4f64.nxv4f32.nxv4f32.i64(<vscale x 4 x double> [[ACC:%.*]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwmsac_vv_f64m4_m(vbool16_t mask, vfloat64m4_t acc,
                                     vfloat32m2_t op1, vfloat32m2_t op2,
                                     size_t vl) {
  return vfwmsac(mask, acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vf_f64m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwmsac.mask.nxv4f64.f32.nxv4f32.i32(<vscale x 4 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vf_f64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwmsac.mask.nxv4f64.f32.nxv4f32.i64(<vscale x 4 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwmsac_vf_f64m4_m(vbool16_t mask, vfloat64m4_t acc,
                                     float op1, vfloat32m2_t op2, size_t vl) {
  return vfwmsac(mask, acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vv_f64m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwmsac.mask.nxv8f64.nxv8f32.nxv8f32.i32(<vscale x 8 x double> [[ACC:%.*]], <vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vv_f64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwmsac.mask.nxv8f64.nxv8f32.nxv8f32.i64(<vscale x 8 x double> [[ACC:%.*]], <vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwmsac_vv_f64m8_m(vbool8_t mask, vfloat64m8_t acc,
                                     vfloat32m4_t op1, vfloat32m4_t op2,
                                     size_t vl) {
  return vfwmsac(mask, acc, op1, op2, vl);
}

// CHECK-RV32-LABEL: @test_vfwmsac_vf_f64m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwmsac.mask.nxv8f64.f32.nxv8f32.i32(<vscale x 8 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vfwmsac_vf_f64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwmsac.mask.nxv8f64.f32.nxv8f32.i64(<vscale x 8 x double> [[ACC:%.*]], float [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR5]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwmsac_vf_f64m8_m(vbool8_t mask, vfloat64m8_t acc, float op1,
                                     vfloat32m4_t op2, size_t vl) {
  return vfwmsac(mask, acc, op1, op2, vl);
}
