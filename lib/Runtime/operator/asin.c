#include <onnc/Runtime/operator/asin.h>

#include <stdint.h>
#include <math.h>
#include <stdbool.h>

void ONNC_RUNTIME_asin_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
) {
  int size = 1;
	for(int i = 0 ; i < input_input_ndim ; ++i){
		size *= input_input_dims[i];
	}
	for(int i = 0 ; i < size ; ++i){
		output_output[i] = asinf(input_input[i]);
	}
}
