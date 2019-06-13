#include <onnc/Runtime/operator/sigmoid.h>

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

void ONNC_RUNTIME_sigmoid_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  
) {
	int size = 1;

	for(int i = 0 ; i < input_X_ndim ; ++i){
		size *= input_X_dims[i];
	}

	for(int i = 0 ; i < size ; ++i){
		output_Y[i] = 1.0f / (1.0f + expf(input_X[i] * -1.0f));
	}
}
