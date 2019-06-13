void ONNC_RUNTIME_concat_float(
  void * restrict onnc_runtime_context
  ,const float * const * restrict input_inputs
  ,int input_inputs_ntensor
  ,const int * input_inputs_ndim, const int * const * restrict input_inputs_dims
  ,float * restrict output_concat_result
  ,int output_concat_result_ndim, const int * restrict output_concat_result_dims
  ,int axis
);
