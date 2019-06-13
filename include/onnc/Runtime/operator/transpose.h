void ONNC_RUNTIME_transpose_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_transposed
  ,int output_transposed_ndim, const int * restrict output_transposed_dims
  ,int * restrict perm
  ,int number_of_perm
);
