#include <onnc/Runtime/operator/reshape.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_reshape_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,const float * restrict input_shape
  ,int input_shape_ndim, const int * restrict input_shape_dims
  ,float * restrict output_reshaped
  ,int output_reshaped_ndim, const int * restrict output_reshaped_dims
  
) {
    int size = 1;
    for(int dim = 0 ; dim < input_data_ndim ; dim++){
        size *= input_data_dims[dim];
    }

    for(int index = 0 ; index < size ; index++){
        output_reshaped[index] = input_data[index];
    }
}
