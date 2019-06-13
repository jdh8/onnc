void ONNC_RUNTIME_loopindextensor_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_T
  ,int input_T_ndim, const int * restrict input_T_dims
  ,const float * restrict input_loop_idx
  ,int input_loop_idx_ndim, const int * restrict input_loop_idx_dims
  ,float * restrict output_O
  ,int output_O_ndim, const int * restrict output_O_dims
  ,int axis
);
