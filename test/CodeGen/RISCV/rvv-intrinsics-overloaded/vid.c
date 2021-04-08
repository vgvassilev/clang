// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv32 -target-feature +experimental-v -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV32 %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-v -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV64 %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +m -target-feature +experimental-v -Werror -Wall -o - %s -S >/dev/null 2>&1 | FileCheck --check-prefix=ASM --allow-empty %s

// ASM-NOT: warning
#include <riscv_vector.h>

// CHECK-RV32-LABEL: @test_vid_v_u8mf8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vid.mask.nxv1i8.i32(<vscale x 1 x i8> [[MASKEDOFF:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8:#.*]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x i8> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u8mf8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vid.mask.nxv1i8.i64(<vscale x 1 x i8> [[MASKEDOFF:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8:#.*]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP0]]
//
vuint8mf8_t test_vid_v_u8mf8_m(vbool64_t mask, vuint8mf8_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u8mf4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vid.mask.nxv2i8.i32(<vscale x 2 x i8> [[MASKEDOFF:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x i8> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u8mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vid.mask.nxv2i8.i64(<vscale x 2 x i8> [[MASKEDOFF:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP0]]
//
vuint8mf4_t test_vid_v_u8mf4_m(vbool32_t mask, vuint8mf4_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u8mf2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vid.mask.nxv4i8.i32(<vscale x 4 x i8> [[MASKEDOFF:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x i8> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u8mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vid.mask.nxv4i8.i64(<vscale x 4 x i8> [[MASKEDOFF:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP0]]
//
vuint8mf2_t test_vid_v_u8mf2_m(vbool16_t mask, vuint8mf2_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u8m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vid.mask.nxv8i8.i32(<vscale x 8 x i8> [[MASKEDOFF:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u8m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vid.mask.nxv8i8.i64(<vscale x 8 x i8> [[MASKEDOFF:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vuint8m1_t test_vid_v_u8m1_m(vbool8_t mask, vuint8m1_t maskedoff, size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u8m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vid.mask.nxv16i8.i32(<vscale x 16 x i8> [[MASKEDOFF:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u8m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vid.mask.nxv16i8.i64(<vscale x 16 x i8> [[MASKEDOFF:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vuint8m2_t test_vid_v_u8m2_m(vbool4_t mask, vuint8m2_t maskedoff, size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u8m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vid.mask.nxv32i8.i32(<vscale x 32 x i8> [[MASKEDOFF:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u8m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vid.mask.nxv32i8.i64(<vscale x 32 x i8> [[MASKEDOFF:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vuint8m4_t test_vid_v_u8m4_m(vbool2_t mask, vuint8m4_t maskedoff, size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u8m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vid.mask.nxv64i8.i32(<vscale x 64 x i8> [[MASKEDOFF:%.*]], <vscale x 64 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 64 x i8> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u8m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vid.mask.nxv64i8.i64(<vscale x 64 x i8> [[MASKEDOFF:%.*]], <vscale x 64 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP0]]
//
vuint8m8_t test_vid_v_u8m8_m(vbool1_t mask, vuint8m8_t maskedoff, size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u16mf4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vid.mask.nxv1i16.i32(<vscale x 1 x i16> [[MASKEDOFF:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vid.mask.nxv1i16.i64(<vscale x 1 x i16> [[MASKEDOFF:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vuint16mf4_t test_vid_v_u16mf4_m(vbool64_t mask, vuint16mf4_t maskedoff,
                                 size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u16mf2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vid.mask.nxv2i16.i32(<vscale x 2 x i16> [[MASKEDOFF:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vid.mask.nxv2i16.i64(<vscale x 2 x i16> [[MASKEDOFF:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vuint16mf2_t test_vid_v_u16mf2_m(vbool32_t mask, vuint16mf2_t maskedoff,
                                 size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u16m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vid.mask.nxv4i16.i32(<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vid.mask.nxv4i16.i64(<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vid_v_u16m1_m(vbool16_t mask, vuint16m1_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u16m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vid.mask.nxv8i16.i32(<vscale x 8 x i16> [[MASKEDOFF:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u16m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vid.mask.nxv8i16.i64(<vscale x 8 x i16> [[MASKEDOFF:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vuint16m2_t test_vid_v_u16m2_m(vbool8_t mask, vuint16m2_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u16m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vid.mask.nxv16i16.i32(<vscale x 16 x i16> [[MASKEDOFF:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u16m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vid.mask.nxv16i16.i64(<vscale x 16 x i16> [[MASKEDOFF:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vuint16m4_t test_vid_v_u16m4_m(vbool4_t mask, vuint16m4_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u16m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vid.mask.nxv32i16.i32(<vscale x 32 x i16> [[MASKEDOFF:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u16m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vid.mask.nxv32i16.i64(<vscale x 32 x i16> [[MASKEDOFF:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vuint16m8_t test_vid_v_u16m8_m(vbool2_t mask, vuint16m8_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u32mf2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vid.mask.nxv1i32.i32(<vscale x 1 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vid.mask.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vid_v_u32mf2_m(vbool64_t mask, vuint32mf2_t maskedoff,
                                 size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u32m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vid.mask.nxv2i32.i32(<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vid.mask.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vid_v_u32m1_m(vbool32_t mask, vuint32m1_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u32m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vid.mask.nxv4i32.i32(<vscale x 4 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vid.mask.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vid_v_u32m2_m(vbool16_t mask, vuint32m2_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u32m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vid.mask.nxv8i32.i32(<vscale x 8 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u32m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vid.mask.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vid_v_u32m4_m(vbool8_t mask, vuint32m4_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u32m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vid.mask.nxv16i32.i32(<vscale x 16 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u32m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vid.mask.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vid_v_u32m8_m(vbool4_t mask, vuint32m8_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u64m1_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vid.mask.nxv1i64.i32(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vid.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vid_v_u64m1_m(vbool64_t mask, vuint64m1_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u64m2_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vid.mask.nxv2i64.i32(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vid.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vid_v_u64m2_m(vbool32_t mask, vuint64m2_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u64m4_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vid.mask.nxv4i64.i32(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vid.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vid_v_u64m4_m(vbool16_t mask, vuint64m4_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}

// CHECK-RV32-LABEL: @test_vid_v_u64m8_m(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vid.mask.nxv8i64.i32(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i32 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV32-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
// CHECK-RV64-LABEL: @test_vid_v_u64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vid.mask.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) [[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vid_v_u64m8_m(vbool8_t mask, vuint64m8_t maskedoff,
                               size_t vl) {
  return vid(mask, maskedoff, vl);
}
