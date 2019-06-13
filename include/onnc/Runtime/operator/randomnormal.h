void ONNC_RUNTIME_randomnormal_float(
  void * restrict onnc_runtime_context
  
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int dtype
  ,float mean
  ,float scale
  ,float seed
  ,int * restrict shape
  ,int number_of_shape
);
