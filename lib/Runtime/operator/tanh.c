#include <onnc/Runtime/operator/tanh.h>

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

void ONNC_RUNTIME_tanh_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  
) {
  int dataSize = 1;
  for (int i = 0; i < input_input_ndim; i++){
    dataSize *= input_input_dims[i];
  }
  
  for(int j = 0; j < dataSize; j++){
    output_output[j] = tanhf(input_input[j]);
  }
}
