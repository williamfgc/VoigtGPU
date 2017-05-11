/*
 * VoigtFunctions.h
 *
 *  Created on: May 10, 2017
 *      Author: wgodoy
 */

#ifndef SOURCE_VOIGTFUNCTIONS_H_
#define SOURCE_VOIGTFUNCTIONS_H_

#include <thrust/device_vector.h>

namespace voigt
{

template <class T, class U>
void SetComplexInputs(const thrust::device_vector<T> &temperatureReference,
                      const thrust::device_vector<T> &temperatures,
                      const thrust::device_vector<T> &wavenumberReference,
                      const thrust::device_vector<T> &wavenumbers,
                      thrust::device_vector<U> &voigtXY)
{
}

} // end namespace

#endif /* SOURCE_VOIGTFUNCTIONS_H_ */
