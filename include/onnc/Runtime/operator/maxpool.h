void ONNC_RUNTIME_maxpool_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,float * restrict output_Indices
  ,int output_Indices_ndim, const int * restrict output_Indices_dims
  ,const char * restrict auto_pad
  ,int * restrict kernel_shape
  ,int number_of_kernel_shape
  ,int * restrict pads
  ,int number_of_pads
  ,int storage_order
  ,int * restrict strides
  ,int number_of_strides
);
