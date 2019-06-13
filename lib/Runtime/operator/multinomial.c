#include <onnc/Runtime/operator/multinomial.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

static int multinomial(int i, int classSize, const float * input_input){
  float cum_prb[classSize];
  cum_prb[0] = input_input[i * classSize];
  for(int j = 1; j < classSize; j++){
    cum_prb[j] = cum_prb[j-1] + input_input[i * classSize + j];
  }
  for (int j = 0; j <  classSize - 1; j++){
    if (rand() / (float)(RAND_MAX) < cum_prb[j]){
      return j;
    }
  }
  return classSize - 1;
}

void ONNC_RUNTIME_multinomial_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int dtype
  ,int sample_size
  ,float seed
) {
  srand(seed);
  int batchSize = input_input_dims[0];
  int classSize = input_input_dims[1];
  for(int i = 0; i < batchSize; i++){
    for(int j = 0; j < classSize; j++){
      output_output[i * classSize + j] = 0;
    }
  }
  int index;
  for(int i = 0; i < batchSize; i++){
    for(int j = 0; j < sample_size; j++){
      index = multinomial(i, classSize, input_input);
      output_output[i * classSize + index] ++;
    }
  }
}
