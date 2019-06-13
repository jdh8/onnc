void ONNC_RUNTIME_conv_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,const float * restrict input_W
  ,int input_W_ndim, const int * restrict input_W_dims
  ,const float * restrict input_B
  ,int input_B_ndim, const int * restrict input_B_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,const char * restrict auto_pad
  ,int * restrict dilations
  ,int number_of_dilations
  ,int group
  ,int * restrict kernel_shape
  ,int number_of_kernel_shape
  ,int * restrict pads
  ,int number_of_pads
  ,int * restrict strides
  ,int number_of_strides
);
