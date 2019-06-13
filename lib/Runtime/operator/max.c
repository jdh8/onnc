#include <onnc/Runtime/operator/max.h>

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

void ONNC_RUNTIME_max_float(
  void * restrict onnc_runtime_context
  ,const float * const * restrict input_data_0
  ,int input_data_0_ntensor
  ,const int * input_data_0_ndim, const int * const * restrict input_data_0_dims
  ,float * restrict output_max
  ,int output_max_ndim, const int * restrict output_max_dims
  
) {
	int ten_len = 1;
	for(int i = 0 ; i < input_data_0_ndim[0] ; ++i){
		ten_len *= input_data_0_dims[0][i];
	}
	for(int j = 0 ; j < ten_len ; ++j){
		output_max[j] = input_data_0[0][j];
		for(int i = 0 ; i < input_data_0_ntensor ; ++i){
			output_max[j] = fmax(output_max[j], input_data_0[i][j]);
		}
	}
}
