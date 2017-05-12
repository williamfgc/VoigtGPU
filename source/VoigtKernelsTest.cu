/*
 * VoigtKernelsTest.cpp
 *
 *  Created on: May 10, 2017
 *      Author: wgodoy
 */
#include <iostream>

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

#include "VoigtFunctions.h"

int main()
{

    const unsigned int size = 10;

    //    thrust::host_vector<float> bLW(size, 1.f);
    //    thrust::device_vector<float> bandLineWidths = bLW;

    thrust::device_vector<float> bandLineWidths(size, 1.f);
    //    thrust::device_vector<float> temperatureReference(1, 1.f);
    //    thrust::device_vector<float> temperatures(size, 1.f);
    //    thrust::device_vector<float> wavenumberReference(1, 1.f);
    //    thrust::device_vector<float> wavenumbers(size, 1.f);
    //    thrust::device_vector<float2> voigtXY(size);

    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << "bandLineWidths[" << i << "] = " << bandLineWidths[i]
                  << "\n";
    }

    //    voigt::SetComplexInputs(bandLineWidths, temperatureReference,
    //    temperatures,
    //                            wavenumberReference, wavenumbers, voigtXY);

    return 0;
}
