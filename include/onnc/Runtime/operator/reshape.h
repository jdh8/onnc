void ONNC_RUNTIME_reshape_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,const float * restrict input_shape
  ,int input_shape_ndim, const int * restrict input_shape_dims
  ,float * restrict output_reshaped
  ,int output_reshaped_ndim, const int * restrict output_reshaped_dims
  
);
