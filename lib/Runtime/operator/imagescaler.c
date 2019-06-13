#include <onnc/Runtime/operator/imagescaler.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_imagescaler_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,float * restrict bias
  ,int number_of_bias
  ,float scale
) {
  int xN = input_input_dims[0];
  int xC = input_input_dims[1];
  int elemSize = 1;

  for(int i = 2; i < input_input_ndim; ++i){
    elemSize *= input_input_dims[i];
  }

  for(int iN = 0; iN < xN; ++iN){
    for(int iC = 0; iC < xC; ++iC){
      const float *pX = input_input   + iN * xC * elemSize + iC * elemSize;
            float *pY = output_output + iN * xC * elemSize + iC * elemSize;
      float cur_bias = bias[iC];
      for(int i = 0; i < elemSize; ++i){
        pY[i] = scale * pX[i] + cur_bias;
      }
    }
  }
}
