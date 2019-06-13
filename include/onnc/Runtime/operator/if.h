void ONNC_RUNTIME_if_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_cond
  ,int input_cond_ndim, const int * restrict input_cond_dims
  ,float * const * restrict output_outputs
  ,int output_outputs_ntensor
  ,const int * output_outputs_ndim, const int * const * restrict output_outputs_dims
  ,const void * restrict else_branch
  ,const void * restrict then_branch
);
