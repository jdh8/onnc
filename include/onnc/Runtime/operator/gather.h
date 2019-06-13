void ONNC_RUNTIME_gather_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,const float * restrict input_indices
  ,int input_indices_ndim, const int * restrict input_indices_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int axis
);
