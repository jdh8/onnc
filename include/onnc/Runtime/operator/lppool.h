void ONNC_RUNTIME_lppool_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,const char * restrict auto_pad
  ,int * restrict kernel_shape
  ,int number_of_kernel_shape
  ,int p
  ,int * restrict pads
  ,int number_of_pads
  ,int * restrict strides
  ,int number_of_strides
);
