#include <onnc/Runtime/operator/or.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_or_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_A
  ,int input_A_ndim, const int * restrict input_A_dims
  ,const float * restrict input_B
  ,int input_B_ndim, const int * restrict input_B_dims
  ,float * restrict output_C
  ,int output_C_ndim, const int * restrict output_C_dims
  
) {
  int size = 1;
  for(int i = 0; i < input_A_ndim; ++i){
    size *= input_A_dims[i];
  }
  for(int i = 0; i < size; ++i){
    if((bool)input_A[i] || (bool)input_B[i]){
      output_C[i] = (float)true;
    } else {
      output_C[i] = (float)false;
    }
  }
}
