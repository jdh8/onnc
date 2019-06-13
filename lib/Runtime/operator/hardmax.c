#include <onnc/Runtime/operator/hardmax.h>

#include <stdint.h>
#include <stdbool.h>
#include <float.h>

void ONNC_RUNTIME_hardmax_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int axis
) {
  int size_N = 1;
  int size_D = 1;
  for(int i = 0; i < axis; ++i){
    size_N *= input_input_dims[i];
  }
  for(int i = axis; i < input_input_ndim; ++i){
    size_D *= input_input_dims[i];
  }

  for(int iN = 0; iN < size_N; ++iN){
    const float* pInput = input_input + iN * size_D;
    float* pOutput = output_output + iN * size_D;
    float maxData_val = -FLT_MAX;
    int maxData_index = 0;
    for(int i = 0; i < size_D; ++i) {
      float tmp_val = pInput[i];
      pOutput[i] = 0.0f;
      if(tmp_val > maxData_val) {
        pOutput[maxData_index] = 0.0f;
        maxData_index = i;
        pOutput[maxData_index] = 1.0f;
        maxData_val = tmp_val;
      }
    }
  }
}
