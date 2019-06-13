void ONNC_RUNTIME_instancenormalization_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,const float * restrict input_scale
  ,int input_scale_ndim, const int * restrict input_scale_dims
  ,const float * restrict input_B
  ,int input_B_ndim, const int * restrict input_B_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,float epsilon
);
