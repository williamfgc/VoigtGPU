#------------------------------------------------------------------------------#
# Distributed under the OSI-approved Apache License, Version 2.0.  See
# accompanying file Copyright.txt for details.
#------------------------------------------------------------------------------#


cuda_add_executable(VoigtKernelsTest.exe VoigtKernelsTest.cu 
                                         VoigtFunctions.h 
                                         VoigtKernels.h)
