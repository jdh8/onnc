void ONNC_RUNTIME_pad_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,const char * restrict mode
  ,int * restrict pads
  ,int number_of_pads
  ,float value
);
