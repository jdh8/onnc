#include <onnc/Runtime/operator/mean.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_mean_float(
  void * restrict onnc_runtime_context
  ,const float * const * restrict input_data_0
  ,int input_data_0_ntensor
  ,const int * input_data_0_ndim, const int * const * restrict input_data_0_dims
  ,float * restrict output_mean
  ,int output_mean_ndim, const int * restrict output_mean_dims
  
) {
  int size = 1;
  for(int dim = 0 ; dim < input_data_0_ndim[0]; dim++){
    size *= input_data_0_dims[0][dim];
  }

  for(int index = 0 ; index < size ; index ++){
    output_mean[index] = 0;
    for(int tensorIndex = 0 ; tensorIndex < input_data_0_ntensor ; tensorIndex++){
        output_mean[index] += input_data_0[tensorIndex][index];
    }
    output_mean[index] /= input_data_0_ntensor;
  }
}
