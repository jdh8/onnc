void ONNC_RUNTIME_topk_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Values
  ,int output_Values_ndim, const int * restrict output_Values_dims
  ,float * restrict output_Indices
  ,int output_Indices_ndim, const int * restrict output_Indices_dims
  ,int axis
  ,int k
);
