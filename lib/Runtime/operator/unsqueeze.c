#include <onnc/Runtime/operator/unsqueeze.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_unsqueeze_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_expanded
  ,int output_expanded_ndim, const int * restrict output_expanded_dims
  ,int * restrict axes
  ,int number_of_axes
) {
  int size_N = 1;
  for(int i = 0; i < input_data_ndim; ++i) {
    size_N *= input_data_dims[i];
  }
  for(int i = 0; i < size_N; ++i) {
    output_expanded[i] = input_data[i];
  }
}
