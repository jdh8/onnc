#include <onnc/Runtime/operator/dropout.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_dropout_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,float * restrict output_mask
  ,int output_mask_ndim, const int * restrict output_mask_dims
  ,float ratio
) {
}
