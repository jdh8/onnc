void ONNC_RUNTIME_squeeze_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_squeezed
  ,int output_squeezed_ndim, const int * restrict output_squeezed_dims
  ,int * restrict axes
  ,int number_of_axes
);
