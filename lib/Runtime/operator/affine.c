#include <onnc/Runtime/operator/affine.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_affine_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,float alpha
  ,float beta
) {
	int size = 1;
	for(int i = 0 ; i < input_X_ndim ; ++i){
		size *= input_X_dims[i];
	}
  // y = alpha * x + beta
	for(int i = 0 ; i < size ; ++i){
		output_Y[i] = alpha * input_X[i] + beta;
	}
}
