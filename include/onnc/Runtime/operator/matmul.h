void ONNC_RUNTIME_matmul_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_A
  ,int input_A_ndim, const int * restrict input_A_dims
  ,const float * restrict input_B
  ,int input_B_ndim, const int * restrict input_B_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  
);
