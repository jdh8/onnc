#include <onnc/Runtime/operator/randomuniform.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void ONNC_RUNTIME_randomuniform_float(
  void * restrict onnc_runtime_context
  
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int dtype
  ,float high
  ,float low
  ,float seed
  ,int * restrict shape
  ,int number_of_shape
) {
  srand(seed ? seed : time(NULL));
  int size = 1;
  for(int dim = 0; dim < output_output_ndim; dim++){
    size *= output_output_dims[dim];
  }
  for(int in = 0 ; in < size ; ++in ){
    output_output[in] = ((float)rand() / (float)RAND_MAX) * (high - low) + low;
  }
}
