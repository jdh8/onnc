#include <onnc/Runtime/operator/shape.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_shape_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_shape
  ,int output_shape_ndim, const int * restrict output_shape_dims
  
) {
  for(int dim = 0 ; dim < input_data_ndim ; dim++){
    output_shape[dim] = input_data_dims[dim];
  }
}
