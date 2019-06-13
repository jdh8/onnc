void ONNC_RUNTIME_expand_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,const float * restrict input_shape
  ,int input_shape_ndim, const int * restrict input_shape_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  
);
