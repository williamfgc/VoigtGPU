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

constexpr unsigned int maxThreads = 65536;
constexpr unsigned int maxBlocks = 64;
constexpr unsigned int maxThreadsPerBlock = 1024;
constexpr double pi = 3.14159265f;

int GetBlocks(const int size)
{
    int blocks = 0;
    if (size <= maxThreadsPerBlock)
    {
        blocks = 1;
    }
    else
    {
        if (size >= maxThreads)
        {
            blocks = maxBlocks;
        }
        else
        {
            if (size % maxThreadsPerBlock == 0)
            {
                blocks = size / maxThreadsPerBlock;
            }
            else
            {
                blocks = size / maxThreadsPerBlock + 1;
            }
        }
    }
    return blocks;
}

int GetThreads(const int size)
{
    int threads = 0;
    if (size > maxThreadsPerBlock)
    {
        threads = maxThreadsPerBlock;
    }
    else
    {
        threads = size;
    }
    return threads;
}

/**
 * Sets
 */
__global__ void KSetComplexInputs(const int terms, const int grids,
                                  const float *bandLineWidths,
                                  const float *temperatureReference,
                                  const float *temperatures,
                                  const float *wavenumberReference,
                                  const float *wavenumbers, float2 *voigtXY)
{
    for (int gridIdx = 0; gridIdx < grids; ++gridIdx)
    {
        int i = gridIdx * maxThreads + blockIdx.x * blockDim.x + threadIdx.x;
        if (i < terms)
        {
            const float bandX =
                1.E8f / (6.f * wavenumbers[i] * sqrtf(temperatureReference[0]));

            voigtXY[i].x = sqrtf(logf(2.f)) * bandX *
                           fabs(wavenumbers[i] - wavenumberReference[0]);

            const float bandY =
                6.f * wavenumbers[i] * sqrtf(temperatureReference[0]);

            voigtXY[i].y = 1E8f * sqrtf(logf(2.f)) * bandLineWidths[i] / bandY;
        }
    }
}

} // end namespace

#endif /* SOURCE_VOIGTKERNELS_H_ */
