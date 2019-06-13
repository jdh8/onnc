#include <onnc/Runtime/operator/crop.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_crop_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int * restrict border
  ,int number_of_border
  ,int * restrict scale
  ,int number_of_scale
) {
}
