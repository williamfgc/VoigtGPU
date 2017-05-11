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

template <class T>
void SetComplexInputs(const thrust::device_vector<T> &temperature,
                      const thrust::device_vector<T> &wavenumbers,
                      const T wavenumberStart, thrust::device_vector<T> &inputs)
{
}

} // end namespace

#endif /* SOURCE_VOIGTFUNCTIONS_H_ */
