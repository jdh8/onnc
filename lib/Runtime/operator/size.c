#include <onnc/Runtime/operator/size.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_size_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_size
  ,int output_size_ndim, const int * restrict output_size_dims
  
) {
  int size = 1;
  for(int dim = 0 ; dim < input_data_ndim ; dim++){
    size *= input_data_dims[dim];
  }
  *output_size = size;
}
