void ONNC_RUNTIME_upsample_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,const char * restrict mode
  ,float * restrict scales
  ,int number_of_scales
);
