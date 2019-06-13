#include <onnc/Runtime/operator/slice.h>

#include <stdint.h>
#include <stdbool.h>

static void forLoop(
    int axisIndex, int ndim
    , const int * restrict lowerBound, const int *  restrict uperBound
    , const float * input, int inputIndex
    , float * output, int* outputIndex
    ,int * axisDistance
){
  if(axisIndex == ndim){
      int outIndex = *outputIndex;
      output[outIndex] = input[inputIndex];
      *outputIndex = outIndex + 1;
      return;
  }
  for(int dimIndex = lowerBound[axisIndex] ; dimIndex < uperBound[axisIndex]; dimIndex++){
    forLoop(axisIndex + 1, ndim, lowerBound, uperBound,
            input, inputIndex + dimIndex * axisDistance[axisIndex],
            output, outputIndex, axisDistance);
  }
}

void ONNC_RUNTIME_slice_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int * restrict axes
  ,int number_of_axes
  ,int * restrict ends
  ,int number_of_ends
  ,int * restrict starts
  ,int number_of_starts
) {
  int output_dim_lower[input_data_ndim];
  int output_dim_higher[input_data_ndim];
  int output_axes[input_data_ndim];

  /* initialize */
  for(int index = 0 ; index < input_data_ndim ; index++){
    output_dim_lower[index] = -1;
    output_dim_higher[index] = -1;
  }

  /* process axes info */
  if(number_of_axes == 0){
    number_of_axes = input_data_ndim;
    for(int axis = 0 ; axis < number_of_axes ; axis++){
      output_axes[axis] = axis;
    }
  }else{
    for(int axis = 0 ; axis < number_of_axes ; axis++){
      output_axes[axis] = axes[axis];
    }
  }

  /* process start and endIndex */
  for(int axis = 0 ; axis < number_of_axes ; axis++){
    int dimIndex = output_axes[axis];

    /* for lower */
    int n = input_data_dims[axis];
    if(starts[axis] > n) output_dim_lower[dimIndex] = n;
    else if(starts[axis] < 0) output_dim_lower[dimIndex] = starts[axis] + n;
    else output_dim_lower[dimIndex] = starts[axis];

    /* for higher */
    if(ends[axis] > n) output_dim_higher[dimIndex] = n;
    else if(ends[axis] < 0) output_dim_higher[dimIndex] = ends[axis] + n;
    else output_dim_higher[dimIndex] = ends[axis];
  }

  /* fill the empty axis*/
  for(int index = 0 ; index < input_data_ndim ; index++){
    if(output_dim_lower[index] == -1) output_dim_lower[index] = 0;
    if(output_dim_higher[index] == -1) output_dim_higher[index] = input_data_dims[index];
  }

  /* compute axisDistance */
  int axisDistance[input_data_ndim];
  int base = axisDistance[input_data_ndim-1] = 1;
  for(int dim = input_data_ndim - 2  ; dim >= 0 ; dim--){
    axisDistance[dim] = base * input_data_dims[dim+1];
    base *= input_data_dims[dim];
  }

  /* for loop */
  int outputIndex = 0;
  forLoop(0, input_data_ndim, output_dim_lower, output_dim_higher,
          input_data, 0, output_output, &outputIndex, axisDistance);
}
