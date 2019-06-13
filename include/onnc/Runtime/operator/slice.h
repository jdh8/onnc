void ONNC_RUNTIME_slice_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int * restrict axes
  ,int number_of_axes
  ,int * restrict ends
  ,int number_of_ends
  ,int * restrict starts
  ,int number_of_starts
);
