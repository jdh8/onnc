void ONNC_RUNTIME_reduceprod_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_reduced
  ,int output_reduced_ndim, const int * restrict output_reduced_dims
  ,int * restrict axes
  ,int number_of_axes
  ,int keepdims
);
