// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.


#include <benchmark/benchmark.h>
#include "bgemm.h"
#include "packw-benchmark.h"
#include "utils.h"
#include "xnnpack/common.h"
#include "xnnpack/hardware-config.h"
#include "xnnpack/packw.h"

static void x8_packw(benchmark::State& state, const char* net,
                     xnn_x8_packw_gemm_goi_ukernel_fn ukernel,
                     uint64_t arch_flags, size_t nr, size_t kr, size_t sr) {
  benchmark::utils::CheckArchFlags(state, arch_flags);
  x8_packw(state, ukernel, nr, kr, sr);
}

#define XNN_UKERNEL(arch_flags, ukernel, nr, kr, sr, kblock, nr_scale)       \
BENCHMARK_CAPTURE_BGEMM(x8_packw, ukernel##_, ukernel, arch_flags, nr, kr, sr);

#include "x8-packw/x8-packw.h"
#undef XNN_UKERNEL

#ifndef XNNPACK_BENCHMARK_NO_MAIN
BENCHMARK_MAIN();
#endif

