#include <onnc/Runtime/operator/clip.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_clip_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,float max
  ,float min
) {
	int size = 1;
	for(int i = 0 ; i < input_input_ndim ; ++i){
		size *= input_input_dims[i];
	}

	for(int i = 0 ; i < size ; ++i){
    float tmp_val = input_input[i];
    tmp_val = tmp_val > max ? max : tmp_val;
    tmp_val = tmp_val < min ? min : tmp_val;
		output_output[i] = tmp_val;
	}
}
