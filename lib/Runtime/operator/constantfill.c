#include <onnc/Runtime/operator/constantfill.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_constantfill_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int dtype
  ,int * restrict extra_shape
  ,int number_of_extra_shape
  ,int input_as_shape
  ,int * restrict shape
  ,int number_of_shape
  ,float value
) {
}
