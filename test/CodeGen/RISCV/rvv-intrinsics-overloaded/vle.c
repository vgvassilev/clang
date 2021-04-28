// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +f -target-feature +d -target-feature +experimental-v \
// RUN:   -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

//
// CHECK-RV64-LABEL: @test_vle8_v_i8mf8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 1 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vle.mask.nxv1i8.i64(<vscale x 1 x i8> [[MASKEDOFF:%.*]], <vscale x 1 x i8>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8:[0-9]+]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP1]]
//
vint8mf8_t test_vle8_v_i8mf8_m(vbool64_t mask, vint8mf8_t maskedoff, const int8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_i8mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 2 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vle.mask.nxv2i8.i64(<vscale x 2 x i8> [[MASKEDOFF:%.*]], <vscale x 2 x i8>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP1]]
//
vint8mf4_t test_vle8_v_i8mf4_m(vbool32_t mask, vint8mf4_t maskedoff, const int8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_i8mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 4 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vle.mask.nxv4i8.i64(<vscale x 4 x i8> [[MASKEDOFF:%.*]], <vscale x 4 x i8>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP1]]
//
vint8mf2_t test_vle8_v_i8mf2_m(vbool16_t mask, vint8mf2_t maskedoff, const int8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_i8m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 8 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vle.mask.nxv8i8.i64(<vscale x 8 x i8> [[MASKEDOFF:%.*]], <vscale x 8 x i8>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP1]]
//
vint8m1_t test_vle8_v_i8m1_m(vbool8_t mask, vint8m1_t maskedoff, const int8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_i8m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 16 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vle.mask.nxv16i8.i64(<vscale x 16 x i8> [[MASKEDOFF:%.*]], <vscale x 16 x i8>* [[TMP0]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP1]]
//
vint8m2_t test_vle8_v_i8m2_m(vbool4_t mask, vint8m2_t maskedoff, const int8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_i8m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 32 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vle.mask.nxv32i8.i64(<vscale x 32 x i8> [[MASKEDOFF:%.*]], <vscale x 32 x i8>* [[TMP0]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP1]]
//
vint8m4_t test_vle8_v_i8m4_m(vbool2_t mask, vint8m4_t maskedoff, const int8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_i8m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 64 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vle.mask.nxv64i8.i64(<vscale x 64 x i8> [[MASKEDOFF:%.*]], <vscale x 64 x i8>* [[TMP0]], <vscale x 64 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP1]]
//
vint8m8_t test_vle8_v_i8m8_m(vbool1_t mask, vint8m8_t maskedoff, const int8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_i16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 1 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vle.mask.nxv1i16.i64(<vscale x 1 x i16> [[MASKEDOFF:%.*]], <vscale x 1 x i16>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP1]]
//
vint16mf4_t test_vle16_v_i16mf4_m(vbool64_t mask, vint16mf4_t maskedoff, const int16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_i16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 2 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vle.mask.nxv2i16.i64(<vscale x 2 x i16> [[MASKEDOFF:%.*]], <vscale x 2 x i16>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP1]]
//
vint16mf2_t test_vle16_v_i16mf2_m(vbool32_t mask, vint16mf2_t maskedoff, const int16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_i16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 4 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vle.mask.nxv4i16.i64(<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 4 x i16>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP1]]
//
vint16m1_t test_vle16_v_i16m1_m(vbool16_t mask, vint16m1_t maskedoff, const int16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_i16m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 8 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vle.mask.nxv8i16.i64(<vscale x 8 x i16> [[MASKEDOFF:%.*]], <vscale x 8 x i16>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
vint16m2_t test_vle16_v_i16m2_m(vbool8_t mask, vint16m2_t maskedoff, const int16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_i16m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 16 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vle.mask.nxv16i16.i64(<vscale x 16 x i16> [[MASKEDOFF:%.*]], <vscale x 16 x i16>* [[TMP0]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP1]]
//
vint16m4_t test_vle16_v_i16m4_m(vbool4_t mask, vint16m4_t maskedoff, const int16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_i16m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 32 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vle.mask.nxv32i16.i64(<vscale x 32 x i16> [[MASKEDOFF:%.*]], <vscale x 32 x i16>* [[TMP0]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP1]]
//
vint16m8_t test_vle16_v_i16m8_m(vbool2_t mask, vint16m8_t maskedoff, const int16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_i32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 1 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vle.mask.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i32>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP1]]
//
vint32mf2_t test_vle32_v_i32mf2_m(vbool64_t mask, vint32mf2_t maskedoff, const int32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_i32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 2 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vle.mask.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i32>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP1]]
//
vint32m1_t test_vle32_v_i32m1_m(vbool32_t mask, vint32m1_t maskedoff, const int32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_i32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 4 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vle.mask.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i32>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
vint32m2_t test_vle32_v_i32m2_m(vbool16_t mask, vint32m2_t maskedoff, const int32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_i32m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 8 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vle.mask.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i32>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP1]]
//
vint32m4_t test_vle32_v_i32m4_m(vbool8_t mask, vint32m4_t maskedoff, const int32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_i32m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 16 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vle.mask.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i32>* [[TMP0]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP1]]
//
vint32m8_t test_vle32_v_i32m8_m(vbool4_t mask, vint32m8_t maskedoff, const int32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_i64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i64* [[BASE:%.*]] to <vscale x 1 x i64>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vle.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP1]]
//
vint64m1_t test_vle64_v_i64m1_m(vbool64_t mask, vint64m1_t maskedoff, const int64_t *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_i64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i64* [[BASE:%.*]] to <vscale x 2 x i64>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vle.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
vint64m2_t test_vle64_v_i64m2_m(vbool32_t mask, vint64m2_t maskedoff, const int64_t *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_i64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i64* [[BASE:%.*]] to <vscale x 4 x i64>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vle.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP1]]
//
vint64m4_t test_vle64_v_i64m4_m(vbool16_t mask, vint64m4_t maskedoff, const int64_t *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_i64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i64* [[BASE:%.*]] to <vscale x 8 x i64>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vle.mask.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP1]]
//
vint64m8_t test_vle64_v_i64m8_m(vbool8_t mask, vint64m8_t maskedoff, const int64_t *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_u8mf8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 1 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vle.mask.nxv1i8.i64(<vscale x 1 x i8> [[MASKEDOFF:%.*]], <vscale x 1 x i8>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP1]]
//
vuint8mf8_t test_vle8_v_u8mf8_m(vbool64_t mask, vuint8mf8_t maskedoff, const uint8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_u8mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 2 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vle.mask.nxv2i8.i64(<vscale x 2 x i8> [[MASKEDOFF:%.*]], <vscale x 2 x i8>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP1]]
//
vuint8mf4_t test_vle8_v_u8mf4_m(vbool32_t mask, vuint8mf4_t maskedoff, const uint8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_u8mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 4 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vle.mask.nxv4i8.i64(<vscale x 4 x i8> [[MASKEDOFF:%.*]], <vscale x 4 x i8>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP1]]
//
vuint8mf2_t test_vle8_v_u8mf2_m(vbool16_t mask, vuint8mf2_t maskedoff, const uint8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_u8m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 8 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vle.mask.nxv8i8.i64(<vscale x 8 x i8> [[MASKEDOFF:%.*]], <vscale x 8 x i8>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP1]]
//
vuint8m1_t test_vle8_v_u8m1_m(vbool8_t mask, vuint8m1_t maskedoff, const uint8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_u8m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 16 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vle.mask.nxv16i8.i64(<vscale x 16 x i8> [[MASKEDOFF:%.*]], <vscale x 16 x i8>* [[TMP0]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP1]]
//
vuint8m2_t test_vle8_v_u8m2_m(vbool4_t mask, vuint8m2_t maskedoff, const uint8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_u8m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 32 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vle.mask.nxv32i8.i64(<vscale x 32 x i8> [[MASKEDOFF:%.*]], <vscale x 32 x i8>* [[TMP0]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP1]]
//
vuint8m4_t test_vle8_v_u8m4_m(vbool2_t mask, vuint8m4_t maskedoff, const uint8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle8_v_u8m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i8* [[BASE:%.*]] to <vscale x 64 x i8>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vle.mask.nxv64i8.i64(<vscale x 64 x i8> [[MASKEDOFF:%.*]], <vscale x 64 x i8>* [[TMP0]], <vscale x 64 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP1]]
//
vuint8m8_t test_vle8_v_u8m8_m(vbool1_t mask, vuint8m8_t maskedoff, const uint8_t *base, size_t vl) {
  return vle8(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_u16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 1 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vle.mask.nxv1i16.i64(<vscale x 1 x i16> [[MASKEDOFF:%.*]], <vscale x 1 x i16>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP1]]
//
vuint16mf4_t test_vle16_v_u16mf4_m(vbool64_t mask, vuint16mf4_t maskedoff, const uint16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_u16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 2 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vle.mask.nxv2i16.i64(<vscale x 2 x i16> [[MASKEDOFF:%.*]], <vscale x 2 x i16>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP1]]
//
vuint16mf2_t test_vle16_v_u16mf2_m(vbool32_t mask, vuint16mf2_t maskedoff, const uint16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_u16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 4 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vle.mask.nxv4i16.i64(<vscale x 4 x i16> [[MASKEDOFF:%.*]], <vscale x 4 x i16>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP1]]
//
vuint16m1_t test_vle16_v_u16m1_m(vbool16_t mask, vuint16m1_t maskedoff, const uint16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_u16m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 8 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vle.mask.nxv8i16.i64(<vscale x 8 x i16> [[MASKEDOFF:%.*]], <vscale x 8 x i16>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP1]]
//
vuint16m2_t test_vle16_v_u16m2_m(vbool8_t mask, vuint16m2_t maskedoff, const uint16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_u16m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 16 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vle.mask.nxv16i16.i64(<vscale x 16 x i16> [[MASKEDOFF:%.*]], <vscale x 16 x i16>* [[TMP0]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP1]]
//
vuint16m4_t test_vle16_v_u16m4_m(vbool4_t mask, vuint16m4_t maskedoff, const uint16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle16_v_u16m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i16* [[BASE:%.*]] to <vscale x 32 x i16>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vle.mask.nxv32i16.i64(<vscale x 32 x i16> [[MASKEDOFF:%.*]], <vscale x 32 x i16>* [[TMP0]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP1]]
//
vuint16m8_t test_vle16_v_u16m8_m(vbool2_t mask, vuint16m8_t maskedoff, const uint16_t *base, size_t vl) {
  return vle16(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_u32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 1 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vle.mask.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i32>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP1]]
//
vuint32mf2_t test_vle32_v_u32mf2_m(vbool64_t mask, vuint32mf2_t maskedoff, const uint32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_u32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 2 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vle.mask.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i32>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP1]]
//
vuint32m1_t test_vle32_v_u32m1_m(vbool32_t mask, vuint32m1_t maskedoff, const uint32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_u32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 4 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vle.mask.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i32>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP1]]
//
vuint32m2_t test_vle32_v_u32m2_m(vbool16_t mask, vuint32m2_t maskedoff, const uint32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_u32m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 8 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vle.mask.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i32>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP1]]
//
vuint32m4_t test_vle32_v_u32m4_m(vbool8_t mask, vuint32m4_t maskedoff, const uint32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_u32m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i32* [[BASE:%.*]] to <vscale x 16 x i32>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vle.mask.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i32>* [[TMP0]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP1]]
//
vuint32m8_t test_vle32_v_u32m8_m(vbool4_t mask, vuint32m8_t maskedoff, const uint32_t *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_u64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i64* [[BASE:%.*]] to <vscale x 1 x i64>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vle.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i64>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP1]]
//
vuint64m1_t test_vle64_v_u64m1_m(vbool64_t mask, vuint64m1_t maskedoff, const uint64_t *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_u64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i64* [[BASE:%.*]] to <vscale x 2 x i64>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vle.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i64>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
vuint64m2_t test_vle64_v_u64m2_m(vbool32_t mask, vuint64m2_t maskedoff, const uint64_t *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_u64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i64* [[BASE:%.*]] to <vscale x 4 x i64>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vle.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i64>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP1]]
//
vuint64m4_t test_vle64_v_u64m4_m(vbool16_t mask, vuint64m4_t maskedoff, const uint64_t *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_u64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast i64* [[BASE:%.*]] to <vscale x 8 x i64>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vle.mask.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i64>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP1]]
//
vuint64m8_t test_vle64_v_u64m8_m(vbool8_t mask, vuint64m8_t maskedoff, const uint64_t *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_f32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast float* [[BASE:%.*]] to <vscale x 1 x float>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x float> @llvm.riscv.vle.mask.nxv1f32.i64(<vscale x 1 x float> [[MASKEDOFF:%.*]], <vscale x 1 x float>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP1]]
//
vfloat32mf2_t test_vle32_v_f32mf2_m(vbool64_t mask, vfloat32mf2_t maskedoff, const float *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_f32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast float* [[BASE:%.*]] to <vscale x 2 x float>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x float> @llvm.riscv.vle.mask.nxv2f32.i64(<vscale x 2 x float> [[MASKEDOFF:%.*]], <vscale x 2 x float>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP1]]
//
vfloat32m1_t test_vle32_v_f32m1_m(vbool32_t mask, vfloat32m1_t maskedoff, const float *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_f32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast float* [[BASE:%.*]] to <vscale x 4 x float>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x float> @llvm.riscv.vle.mask.nxv4f32.i64(<vscale x 4 x float> [[MASKEDOFF:%.*]], <vscale x 4 x float>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP1]]
//
vfloat32m2_t test_vle32_v_f32m2_m(vbool16_t mask, vfloat32m2_t maskedoff, const float *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_f32m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast float* [[BASE:%.*]] to <vscale x 8 x float>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x float> @llvm.riscv.vle.mask.nxv8f32.i64(<vscale x 8 x float> [[MASKEDOFF:%.*]], <vscale x 8 x float>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP1]]
//
vfloat32m4_t test_vle32_v_f32m4_m(vbool8_t mask, vfloat32m4_t maskedoff, const float *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle32_v_f32m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast float* [[BASE:%.*]] to <vscale x 16 x float>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 16 x float> @llvm.riscv.vle.mask.nxv16f32.i64(<vscale x 16 x float> [[MASKEDOFF:%.*]], <vscale x 16 x float>* [[TMP0]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP1]]
//
vfloat32m8_t test_vle32_v_f32m8_m(vbool4_t mask, vfloat32m8_t maskedoff, const float *base, size_t vl) {
  return vle32(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast double* [[BASE:%.*]] to <vscale x 1 x double>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 1 x double> @llvm.riscv.vle.mask.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x double>* [[TMP0]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP1]]
//
vfloat64m1_t test_vle64_v_f64m1_m(vbool64_t mask, vfloat64m1_t maskedoff, const double *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_f64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast double* [[BASE:%.*]] to <vscale x 2 x double>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 2 x double> @llvm.riscv.vle.mask.nxv2f64.i64(<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x double>* [[TMP0]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP1]]
//
vfloat64m2_t test_vle64_v_f64m2_m(vbool32_t mask, vfloat64m2_t maskedoff, const double *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_f64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast double* [[BASE:%.*]] to <vscale x 4 x double>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 4 x double> @llvm.riscv.vle.mask.nxv4f64.i64(<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x double>* [[TMP0]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP1]]
//
vfloat64m4_t test_vle64_v_f64m4_m(vbool16_t mask, vfloat64m4_t maskedoff, const double *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}

//
// CHECK-RV64-LABEL: @test_vle64_v_f64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = bitcast double* [[BASE:%.*]] to <vscale x 8 x double>*
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = call <vscale x 8 x double> @llvm.riscv.vle.mask.nxv8f64.i64(<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x double>* [[TMP0]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]]) #[[ATTR8]]
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP1]]
//
vfloat64m8_t test_vle64_v_f64m8_m(vbool8_t mask, vfloat64m8_t maskedoff, const double *base, size_t vl) {
  return vle64(mask, maskedoff, base, vl);
}
