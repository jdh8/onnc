#include <onnc/Runtime/operator/lstm.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_lstm_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,const float * restrict input_W
  ,int input_W_ndim, const int * restrict input_W_dims
  ,const float * restrict input_R
  ,int input_R_ndim, const int * restrict input_R_dims
  ,const float * restrict input_B
  ,int input_B_ndim, const int * restrict input_B_dims
  ,const float * restrict input_sequence_lens
  ,int input_sequence_lens_ndim, const int * restrict input_sequence_lens_dims
  ,const float * restrict input_initial_h
  ,int input_initial_h_ndim, const int * restrict input_initial_h_dims
  ,const float * restrict input_initial_c
  ,int input_initial_c_ndim, const int * restrict input_initial_c_dims
  ,const float * restrict input_P
  ,int input_P_ndim, const int * restrict input_P_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,float * restrict output_Y_h
  ,int output_Y_h_ndim, const int * restrict output_Y_h_dims
  ,float * restrict output_Y_c
  ,int output_Y_c_ndim, const int * restrict output_Y_c_dims
  ,float * restrict activation_alpha
  ,int number_of_activation_alpha
  ,float * restrict activation_beta
  ,int number_of_activation_beta
  ,const char ** restrict activations
  ,int number_of_activations
  ,float clip
  ,const char * restrict direction
  ,int hidden_size
  ,int input_forget
) {
}
