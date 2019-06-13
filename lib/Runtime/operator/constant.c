#include <onnc/Runtime/operator/constant.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_constant_float(
  void * restrict onnc_runtime_context
  
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,const void * restrict value
) {
  int size = 1;
  for(int dim = 0 ; dim < output_output_ndim ; dim++){
    size *= output_output_dims[dim];
  }

  float fill = *((float*)value);
  for(int index = 0 ; index < size ; index++){
    output_output[index] = fill;
  }
}
