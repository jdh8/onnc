#include <onnc/Runtime/operator/exp.h>

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

void ONNC_RUNTIME_exp_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  
) {
  int size = 1;
  for(int dim = 0 ; dim < input_input_ndim ; dim++){
    size *= input_input_dims[dim];
  }

  for(int index = 0 ; index < size ; index++){
    output_output[index] = expf(input_input[index]);
  }
}
