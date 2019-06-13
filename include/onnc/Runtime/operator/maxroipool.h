void ONNC_RUNTIME_maxroipool_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,const float * restrict input_rois
  ,int input_rois_ndim, const int * restrict input_rois_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,int * restrict pooled_shape
  ,int number_of_pooled_shape
  ,float spatial_scale
);
