// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-rmax.yaml
//   Generator: tools/generate-reduce-test.py


#include <gtest/gtest.h>

#include <xnnpack/common.h>
#include <xnnpack/isa-checks.h>

#include <xnnpack/microparams-init.h>
#include <xnnpack/reduce.h>
#include "reduce-microkernel-tester.h"


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_RMAX__NEON_U4, batch_eq_4) {
    TEST_REQUIRES_ARM_NEON;
    ReduceMicrokernelTester()
      .batch_size(4)
      .Test(xnn_f32_rmax_ukernel__neon_u4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__NEON_U4, batch_div_4) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U4, batch_lt_4) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 4; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U4, batch_gt_4) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 5; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_RMAX__NEON_U8_ACC2, batch_eq_8) {
    TEST_REQUIRES_ARM_NEON;
    ReduceMicrokernelTester()
      .batch_size(8)
      .Test(xnn_f32_rmax_ukernel__neon_u8_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__NEON_U8_ACC2, batch_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U8_ACC2, batch_lt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U8_ACC2, batch_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_RMAX__NEON_U12_ACC3, batch_eq_12) {
    TEST_REQUIRES_ARM_NEON;
    ReduceMicrokernelTester()
      .batch_size(12)
      .Test(xnn_f32_rmax_ukernel__neon_u12_acc3, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__NEON_U12_ACC3, batch_div_12) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 24; batch_size < 120; batch_size += 12) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U12_ACC3, batch_lt_12) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 12; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U12_ACC3, batch_gt_12) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 13; batch_size < 24; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_RMAX__NEON_U16_ACC2, batch_eq_16) {
    TEST_REQUIRES_ARM_NEON;
    ReduceMicrokernelTester()
      .batch_size(16)
      .Test(xnn_f32_rmax_ukernel__neon_u16_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__NEON_U16_ACC2, batch_div_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U16_ACC2, batch_lt_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U16_ACC2, batch_gt_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  TEST(F32_RMAX__NEON_U16_ACC4, batch_eq_16) {
    TEST_REQUIRES_ARM_NEON;
    ReduceMicrokernelTester()
      .batch_size(16)
      .Test(xnn_f32_rmax_ukernel__neon_u16_acc4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__NEON_U16_ACC4, batch_div_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U16_ACC4, batch_lt_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__NEON_U16_ACC4, batch_gt_16) {
    TEST_REQUIRES_ARM_NEON;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__neon_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RMAX__SSE_U4, batch_eq_4) {
    TEST_REQUIRES_X86_SSE;
    ReduceMicrokernelTester()
      .batch_size(4)
      .Test(xnn_f32_rmax_ukernel__sse_u4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__SSE_U4, batch_div_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U4, batch_lt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 1; batch_size < 4; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U4, batch_gt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 5; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RMAX__SSE_U8_ACC2, batch_eq_8) {
    TEST_REQUIRES_X86_SSE;
    ReduceMicrokernelTester()
      .batch_size(8)
      .Test(xnn_f32_rmax_ukernel__sse_u8_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__SSE_U8_ACC2, batch_div_8) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U8_ACC2, batch_lt_8) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U8_ACC2, batch_gt_8) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RMAX__SSE_U12_ACC3, batch_eq_12) {
    TEST_REQUIRES_X86_SSE;
    ReduceMicrokernelTester()
      .batch_size(12)
      .Test(xnn_f32_rmax_ukernel__sse_u12_acc3, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__SSE_U12_ACC3, batch_div_12) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 24; batch_size < 120; batch_size += 12) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U12_ACC3, batch_lt_12) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 1; batch_size < 12; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U12_ACC3, batch_gt_12) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 13; batch_size < 24; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RMAX__SSE_U16_ACC2, batch_eq_16) {
    TEST_REQUIRES_X86_SSE;
    ReduceMicrokernelTester()
      .batch_size(16)
      .Test(xnn_f32_rmax_ukernel__sse_u16_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__SSE_U16_ACC2, batch_div_16) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U16_ACC2, batch_lt_16) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U16_ACC2, batch_gt_16) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_RMAX__SSE_U16_ACC4, batch_eq_16) {
    TEST_REQUIRES_X86_SSE;
    ReduceMicrokernelTester()
      .batch_size(16)
      .Test(xnn_f32_rmax_ukernel__sse_u16_acc4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__SSE_U16_ACC4, batch_div_16) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U16_ACC4, batch_lt_16) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__SSE_U16_ACC4, batch_gt_16) {
    TEST_REQUIRES_X86_SSE;
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__sse_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


TEST(F32_RMAX__SCALAR_U1, batch_eq_1) {
  ReduceMicrokernelTester()
    .batch_size(1)
    .Test(xnn_f32_rmax_ukernel__scalar_u1, ReduceMicrokernelTester::OpType::Max);
}

TEST(F32_RMAX__SCALAR_U1, batch_gt_1) {
  for (size_t batch_size = 2; batch_size < 10; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u1, ReduceMicrokernelTester::OpType::Max);
  }
}


TEST(F32_RMAX__SCALAR_U2_ACC2, batch_eq_2) {
  ReduceMicrokernelTester()
    .batch_size(2)
    .Test(xnn_f32_rmax_ukernel__scalar_u2_acc2, ReduceMicrokernelTester::OpType::Max);
}

TEST(F32_RMAX__SCALAR_U2_ACC2, batch_div_2) {
  for (size_t batch_size = 4; batch_size < 20; batch_size += 2) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u2_acc2, ReduceMicrokernelTester::OpType::Max);
  }
}

TEST(F32_RMAX__SCALAR_U2_ACC2, batch_lt_2) {
  for (size_t batch_size = 1; batch_size < 2; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u2_acc2, ReduceMicrokernelTester::OpType::Max);
  }
}

TEST(F32_RMAX__SCALAR_U2_ACC2, batch_gt_2) {
  for (size_t batch_size = 3; batch_size < 4; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u2_acc2, ReduceMicrokernelTester::OpType::Max);
  }
}


TEST(F32_RMAX__SCALAR_U3_ACC3, batch_eq_3) {
  ReduceMicrokernelTester()
    .batch_size(3)
    .Test(xnn_f32_rmax_ukernel__scalar_u3_acc3, ReduceMicrokernelTester::OpType::Max);
}

TEST(F32_RMAX__SCALAR_U3_ACC3, batch_div_3) {
  for (size_t batch_size = 6; batch_size < 30; batch_size += 3) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u3_acc3, ReduceMicrokernelTester::OpType::Max);
  }
}

TEST(F32_RMAX__SCALAR_U3_ACC3, batch_lt_3) {
  for (size_t batch_size = 1; batch_size < 3; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u3_acc3, ReduceMicrokernelTester::OpType::Max);
  }
}

TEST(F32_RMAX__SCALAR_U3_ACC3, batch_gt_3) {
  for (size_t batch_size = 4; batch_size < 6; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u3_acc3, ReduceMicrokernelTester::OpType::Max);
  }
}


TEST(F32_RMAX__SCALAR_U4_ACC2, batch_eq_4) {
  ReduceMicrokernelTester()
    .batch_size(4)
    .Test(xnn_f32_rmax_ukernel__scalar_u4_acc2, ReduceMicrokernelTester::OpType::Max);
}

TEST(F32_RMAX__SCALAR_U4_ACC2, batch_div_4) {
  for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u4_acc2, ReduceMicrokernelTester::OpType::Max);
  }
}

TEST(F32_RMAX__SCALAR_U4_ACC2, batch_lt_4) {
  for (size_t batch_size = 1; batch_size < 4; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u4_acc2, ReduceMicrokernelTester::OpType::Max);
  }
}

TEST(F32_RMAX__SCALAR_U4_ACC2, batch_gt_4) {
  for (size_t batch_size = 5; batch_size < 8; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u4_acc2, ReduceMicrokernelTester::OpType::Max);
  }
}


TEST(F32_RMAX__SCALAR_U4_ACC4, batch_eq_4) {
  ReduceMicrokernelTester()
    .batch_size(4)
    .Test(xnn_f32_rmax_ukernel__scalar_u4_acc4, ReduceMicrokernelTester::OpType::Max);
}

TEST(F32_RMAX__SCALAR_U4_ACC4, batch_div_4) {
  for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u4_acc4, ReduceMicrokernelTester::OpType::Max);
  }
}

TEST(F32_RMAX__SCALAR_U4_ACC4, batch_lt_4) {
  for (size_t batch_size = 1; batch_size < 4; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u4_acc4, ReduceMicrokernelTester::OpType::Max);
  }
}

TEST(F32_RMAX__SCALAR_U4_ACC4, batch_gt_4) {
  for (size_t batch_size = 5; batch_size < 8; batch_size++) {
    ReduceMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_rmax_ukernel__scalar_u4_acc4, ReduceMicrokernelTester::OpType::Max);
  }
}


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASM_U1, batch_eq_1) {
    ReduceMicrokernelTester()
      .batch_size(1)
      .Test(xnn_f32_rmax_ukernel__wasm_u1, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASM_U1, batch_gt_1) {
    for (size_t batch_size = 2; batch_size < 10; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u1, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASM_U2_ACC2, batch_eq_2) {
    ReduceMicrokernelTester()
      .batch_size(2)
      .Test(xnn_f32_rmax_ukernel__wasm_u2_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASM_U2_ACC2, batch_div_2) {
    for (size_t batch_size = 4; batch_size < 20; batch_size += 2) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u2_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASM_U2_ACC2, batch_lt_2) {
    for (size_t batch_size = 1; batch_size < 2; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u2_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASM_U2_ACC2, batch_gt_2) {
    for (size_t batch_size = 3; batch_size < 4; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u2_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASM_U3_ACC3, batch_eq_3) {
    ReduceMicrokernelTester()
      .batch_size(3)
      .Test(xnn_f32_rmax_ukernel__wasm_u3_acc3, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASM_U3_ACC3, batch_div_3) {
    for (size_t batch_size = 6; batch_size < 30; batch_size += 3) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u3_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASM_U3_ACC3, batch_lt_3) {
    for (size_t batch_size = 1; batch_size < 3; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u3_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASM_U3_ACC3, batch_gt_3) {
    for (size_t batch_size = 4; batch_size < 6; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u3_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASM_U4_ACC2, batch_eq_4) {
    ReduceMicrokernelTester()
      .batch_size(4)
      .Test(xnn_f32_rmax_ukernel__wasm_u4_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASM_U4_ACC2, batch_div_4) {
    for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u4_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASM_U4_ACC2, batch_lt_4) {
    for (size_t batch_size = 1; batch_size < 4; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u4_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASM_U4_ACC2, batch_gt_4) {
    for (size_t batch_size = 5; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u4_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASM_U4_ACC4, batch_eq_4) {
    ReduceMicrokernelTester()
      .batch_size(4)
      .Test(xnn_f32_rmax_ukernel__wasm_u4_acc4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASM_U4_ACC4, batch_div_4) {
    for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u4_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASM_U4_ACC4, batch_lt_4) {
    for (size_t batch_size = 1; batch_size < 4; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u4_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASM_U4_ACC4, batch_gt_4) {
    for (size_t batch_size = 5; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasm_u4_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_MINMAX_U4, batch_eq_4) {
    ReduceMicrokernelTester()
      .batch_size(4)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U4, batch_div_4) {
    for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U4, batch_lt_4) {
    for (size_t batch_size = 1; batch_size < 4; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U4, batch_gt_4) {
    for (size_t batch_size = 5; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_MINMAX_U8_ACC2, batch_eq_8) {
    ReduceMicrokernelTester()
      .batch_size(8)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u8_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U8_ACC2, batch_div_8) {
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U8_ACC2, batch_lt_8) {
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U8_ACC2, batch_gt_8) {
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_MINMAX_U12_ACC3, batch_eq_12) {
    ReduceMicrokernelTester()
      .batch_size(12)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u12_acc3, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U12_ACC3, batch_div_12) {
    for (size_t batch_size = 24; batch_size < 120; batch_size += 12) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U12_ACC3, batch_lt_12) {
    for (size_t batch_size = 1; batch_size < 12; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U12_ACC3, batch_gt_12) {
    for (size_t batch_size = 13; batch_size < 24; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_MINMAX_U16_ACC2, batch_eq_16) {
    ReduceMicrokernelTester()
      .batch_size(16)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u16_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U16_ACC2, batch_div_16) {
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U16_ACC2, batch_lt_16) {
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U16_ACC2, batch_gt_16) {
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_MINMAX_U16_ACC4, batch_eq_16) {
    ReduceMicrokernelTester()
      .batch_size(16)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u16_acc4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U16_ACC4, batch_div_16) {
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U16_ACC4, batch_lt_16) {
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_MINMAX_U16_ACC4, batch_gt_16) {
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_minmax_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_PMINMAX_U4, batch_eq_4) {
    ReduceMicrokernelTester()
      .batch_size(4)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U4, batch_div_4) {
    for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U4, batch_lt_4) {
    for (size_t batch_size = 1; batch_size < 4; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U4, batch_gt_4) {
    for (size_t batch_size = 5; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_PMINMAX_U8_ACC2, batch_eq_8) {
    ReduceMicrokernelTester()
      .batch_size(8)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u8_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U8_ACC2, batch_div_8) {
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U8_ACC2, batch_lt_8) {
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U8_ACC2, batch_gt_8) {
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u8_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_PMINMAX_U12_ACC3, batch_eq_12) {
    ReduceMicrokernelTester()
      .batch_size(12)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u12_acc3, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U12_ACC3, batch_div_12) {
    for (size_t batch_size = 24; batch_size < 120; batch_size += 12) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U12_ACC3, batch_lt_12) {
    for (size_t batch_size = 1; batch_size < 12; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U12_ACC3, batch_gt_12) {
    for (size_t batch_size = 13; batch_size < 24; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u12_acc3, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_PMINMAX_U16_ACC2, batch_eq_16) {
    ReduceMicrokernelTester()
      .batch_size(16)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u16_acc2, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U16_ACC2, batch_div_16) {
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U16_ACC2, batch_lt_16) {
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U16_ACC2, batch_gt_16) {
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u16_acc2, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  TEST(F32_RMAX__WASMSIMD_PMINMAX_U16_ACC4, batch_eq_16) {
    ReduceMicrokernelTester()
      .batch_size(16)
      .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u16_acc4, ReduceMicrokernelTester::OpType::Max);
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U16_ACC4, batch_div_16) {
    for (size_t batch_size = 32; batch_size < 160; batch_size += 16) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U16_ACC4, batch_lt_16) {
    for (size_t batch_size = 1; batch_size < 16; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }

  TEST(F32_RMAX__WASMSIMD_PMINMAX_U16_ACC4, batch_gt_16) {
    for (size_t batch_size = 17; batch_size < 32; batch_size++) {
      ReduceMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_rmax_ukernel__wasmsimd_pminmax_u16_acc4, ReduceMicrokernelTester::OpType::Max);
    }
  }
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
