/*
 * VoigtKernels.h
 *
 *  Created on: May 10, 2017
 *      Author: wgodoy
 */

#ifndef SOURCE_VOIGTKERNELS_H_
#define SOURCE_VOIGTKERNELS_H_

#include <cuComplex.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

namespace voigt
{

/**
 * Sets
 */
__global__ void SetComplexInputs(const int terms, const int grids,
                                 const float *temperatureReference,
                                 const float *temperatures,
                                 const float *wavenumberReference,
                                 const float *wavenumbers,
                                 cuFloatComplex *voigtXY)
{
    for (int gridIdx = 0; gridIdx < grids; ++gridIdx)
    {
        int i = gridIdx * max_threads + blockIdx.x * blockDim.x + threadIdx.x;
        if (i < terms)
        {
            const float bD =
                1.E8f / (6.f * wavenumbers[i] * sqrtf(temperatureReference));
            voigtXY[i].x = sqrtf(logf(2.f)) * fabs(eta[i] - eta_o[0]) * bD;
        }
    }
}

} // end namespace

#endif /* SOURCE_VOIGTKERNELS_H_ */
