void ONNC_RUNTIME_loop_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_M
  ,int input_M_ndim, const int * restrict input_M_dims
  ,const float * restrict input_cond
  ,int input_cond_ndim, const int * restrict input_cond_dims
  ,const float * const * restrict input_v_initial
  ,int input_v_initial_ntensor
  ,const int * input_v_initial_ndim, const int * const * restrict input_v_initial_dims
  ,float * const * restrict output_v_final_and_scan_outputs
  ,int output_v_final_and_scan_outputs_ntensor
  ,const int * output_v_final_and_scan_outputs_ndim, const int * const * restrict output_v_final_and_scan_outputs_dims
  ,const void * restrict body
);
