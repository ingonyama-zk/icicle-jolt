#pragma once

#include "icicle/backend/msm_backend.h"

#include <cooperative_groups.h>
#include <cub/device/device_radix_sort.cuh>
#include <cub/device/device_run_length_encode.cuh>
#include <cub/device/device_scan.cuh>
#include <cuda.h>

#include <iostream>
#include <stdexcept>
#include <vector>
#include <future>

#include "icicle/curves/affine.h"
#include "icicle/curves/projective.h"
#include "icicle/fields/field.h"
#include "gpu-utils/error_handler.h"
#include "cuda_mont.cuh"
#include "msm/cuda_msm_config.cuh"
#include "error_translation.h"

#include "icicle/curves/params/bn254.h"
#include "icicle/fields/snark_fields/bn254_scalar.h"

#define MAX_TH                   256
#define MAX_C_FOR_PRECOMPUTATION 22

namespace msm {
  static cudaError_t
  cuda_precompute_msm_points(const bn254::affine_t* points, int msm_size, const MSMConfig& config, bn254::affine_t* output_points);

  cudaError_t msm_cuda(const bn254::scalar_t* scalars, const bn254::affine_t* points, int msm_size, const MSMConfig& config, bn254::projective_t* results);
}