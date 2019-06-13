void ONNC_RUNTIME_batchnormalization_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,const float * restrict input_scale
  ,int input_scale_ndim, const int * restrict input_scale_dims
  ,const float * restrict input_B
  ,int input_B_ndim, const int * restrict input_B_dims
  ,const float * restrict input_mean
  ,int input_mean_ndim, const int * restrict input_mean_dims
  ,const float * restrict input_var
  ,int input_var_ndim, const int * restrict input_var_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,float * restrict output_mean
  ,int output_mean_ndim, const int * restrict output_mean_dims
  ,float * restrict output_var
  ,int output_var_ndim, const int * restrict output_var_dims
  ,float * restrict output_saved_mean
  ,int output_saved_mean_ndim, const int * restrict output_saved_mean_dims
  ,float * restrict output_saved_var
  ,int output_saved_var_ndim, const int * restrict output_saved_var_dims
  ,float epsilon
  ,float momentum
  ,int spatial
);
