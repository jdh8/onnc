void ONNC_RUNTIME_split_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * const * restrict output_outputs
  ,int output_outputs_ntensor
  ,const int * output_outputs_ndim, const int * const * restrict output_outputs_dims
  ,int axis
  ,int * restrict split
  ,int number_of_split
);
