void ONNC_RUNTIME_scan_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_sequence_lens
  ,int input_sequence_lens_ndim, const int * restrict input_sequence_lens_dims
  ,const float * const * restrict input_initial_state_and_scan_inputs
  ,int input_initial_state_and_scan_inputs_ntensor
  ,const int * input_initial_state_and_scan_inputs_ndim, const int * const * restrict input_initial_state_and_scan_inputs_dims
  ,float * const * restrict output_final_state_and_scan_outputs
  ,int output_final_state_and_scan_outputs_ntensor
  ,const int * output_final_state_and_scan_outputs_ndim, const int * const * restrict output_final_state_and_scan_outputs_dims
  ,const void * restrict body
  ,int * restrict directions
  ,int number_of_directions
  ,int num_scan_inputs
);
