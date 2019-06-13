#include <onnc/Runtime/operator/squeeze.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_squeeze_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_squeezed
  ,int output_squeezed_ndim, const int * restrict output_squeezed_dims
  ,int * restrict axes
  ,int number_of_axes
) {
  int size_N = 1;

  // total counts of elements
  for(int i = 0; i < input_data_ndim; ++i) {
    size_N *= input_data_dims[i];
  }

  for(int i = 0; i < size_N; ++i) {
    output_squeezed[i] = input_data[i];
  }
}
