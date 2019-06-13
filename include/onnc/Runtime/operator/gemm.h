void ONNC_RUNTIME_gemm_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_A
  ,int input_A_ndim, const int * restrict input_A_dims
  ,const float * restrict input_B
  ,int input_B_ndim, const int * restrict input_B_dims
  ,const float * restrict input_C
  ,int input_C_ndim, const int * restrict input_C_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,float alpha
  ,float beta
  ,int transA
  ,int transB
);
