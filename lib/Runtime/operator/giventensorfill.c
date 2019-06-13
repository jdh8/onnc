#include <onnc/Runtime/operator/giventensorfill.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_giventensorfill_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_shape
  ,int input_shape_ndim, const int * restrict input_shape_dims
  ,float * restrict output_X
  ,int output_X_ndim, const int * restrict output_X_dims
  ,int * restrict extra_shape
  ,int number_of_extra_shape
  ,int input_as_shape
  ,int * restrict shape
  ,int number_of_shape
  ,float * restrict values
  ,int number_of_values
) {
}
