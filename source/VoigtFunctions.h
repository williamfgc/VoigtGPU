/*
 * VoigtFunctions.h
 *
 *  Created on: May 10, 2017
 *      Author: wgodoy
 */

#ifndef SOURCE_VOIGTFUNCTIONS_H_
#define SOURCE_VOIGTFUNCTIONS_H_

#include <thrust/device_vector.h>

#include "VoigtKernels.h"

namespace voigt
{

void SetComplexInputs(const thrust::device_vector<float> &bandLineWidths,
                      const thrust::device_vector<float> &temperatureReference,
                      const thrust::device_vector<float> &temperatures,
                      const thrust::device_vector<float> &wavenumberReference,
                      const thrust::device_vector<float> &wavenumbers,
                      thrust::device_vector<float2> &voigtXY)
{
    const unsigned int size = voigtXY.size();
    const int blocks = GetBlocks(size);
    const int threads = GetThreads(size);

    KSetComplexInputs<<<blocks, threads>>>(
        size, 1, thrust::raw_pointer_cast(bandLineWidths.data()),
        thrust::raw_pointer_cast(temperatureReference.data()),
        thrust::raw_pointer_cast(temperatures.data()),
        thrust::raw_pointer_cast(wavenumberReference.data()),
        thrust::raw_pointer_cast(wavenumbers.data()),
        thrust::raw_pointer_cast(voigtXY.data()));
}

} // end namespace

#endif /* SOURCE_VOIGTFUNCTIONS_H_ */
