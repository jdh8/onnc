#include <onnc/Runtime/operator/globallppool.h>

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

void ONNC_RUNTIME_globallppool_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,int p
) {
  int mul = 1 ;
	for(int i = input_X_ndim - 1 ; i >= 2 ; --i){
		mul *= input_X_dims[i] ;
	}
	for(int i = 0 ; i < output_Y_dims[0] ; ++i){
		for(int j = 0 ; j < output_Y_dims[1] ; ++j){
			output_Y[ i * output_Y_dims[1] + j ] = 0;
			for(int k = 0 ; k < mul ; ++k){
				output_Y[ i * output_Y_dims[1] + j ] += powf(
					fabs( input_X[ ( i * input_X_dims[1] + j ) * mul + k] ), p
				);
			}
			output_Y[ i * output_Y_dims[1] + j ] = powf( output_Y[ i * output_Y_dims[1] + j ], 1.0 / p );
		}
	}
}
