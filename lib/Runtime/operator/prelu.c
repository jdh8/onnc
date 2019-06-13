#include <onnc/Runtime/operator/prelu.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_prelu_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,const float * restrict input_slope
  ,int input_slope_ndim, const int * restrict input_slope_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  
) {
	int size = 1;

	for(int i = 0 ; i < input_X_ndim ; ++i){
		size *= input_X_dims[i];
	}
	for(int i = 0 ; i < size ; ++i){
		output_Y[i] = (input_X[i] >= 0.0f) ? input_X[i] : input_X[i] * input_slope[i];
	}
}
