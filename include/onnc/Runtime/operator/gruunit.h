void ONNC_RUNTIME_gruunit_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_hidden_prev
  ,int input_hidden_prev_ndim, const int * restrict input_hidden_prev_dims
  ,const float * restrict input_gates
  ,int input_gates_ndim, const int * restrict input_gates_dims
  ,const float * restrict input_seq_lengths
  ,int input_seq_lengths_ndim, const int * restrict input_seq_lengths_dims
  ,const float * restrict input_t
  ,int input_t_ndim, const int * restrict input_t_dims
  ,float * restrict output_hidden
  ,int output_hidden_ndim, const int * restrict output_hidden_dims
  ,int drop_states
);
