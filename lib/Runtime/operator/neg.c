#include <onnc/Runtime/operator/neg.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_neg_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  
) {
  int dataSize = 1;
  for (int i = 0; i < input_X_ndim; i++){
    dataSize *= input_X_dims[i];
  }
  for(int i = 0; i < dataSize; i++){
    output_Y[i] = -input_X[i];
  }
}
