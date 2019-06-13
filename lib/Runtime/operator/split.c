#include <onnc/Runtime/operator/split.h>

#include <stdint.h>
#include <stdbool.h>

static void forLoop(
    const float * restrict input_input, int input_index,
    int input_input_ndim, const int * restrict input_input_dims,
    int dimIndex, int * restrict axisDistance,
    int axis, int axisLower, int axisHigher,
    float * const * restrict output, int output_row, int * restrict output_col
){
  if(dimIndex == input_input_ndim){
    int col = *output_col;
    output[output_row][col] = input_input[input_index];
    *output_col = col + 1;
    return;
  }
  /* set loop lower and uper when encountering speicific axis */
  int loopLower = 0, loopUper = input_input_dims[dimIndex];
  if(dimIndex == axis){
    loopLower = axisLower;
    loopUper = axisHigher;
  }
  for(int dim = loopLower ; dim < loopUper ; dim++){
      forLoop(input_input, input_index + dim * axisDistance[dimIndex],
              input_input_ndim, input_input_dims,
              dimIndex + 1, axisDistance,
              axis, axisLower, axisHigher,
              output, output_row, output_col);
  }
}

void ONNC_RUNTIME_split_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * const * restrict output_outputs
  ,int output_outputs_ntensor
  ,const int * output_outputs_ndim, const int * const * restrict output_outputs_dims
  ,int axis
  ,int * restrict split
  ,int number_of_split
) {
  /* initialize parameter following the spec */
  int output_split_number = output_outputs_ntensor;
  int output_split[output_split_number];
  if(number_of_split){
    for(int index = 0 ; index < output_split_number ; index++){
        output_split[index] = split[index];
    }
  }
  else{
    int avg_split = input_input_dims[axis] / output_split_number;
    for(int index = 0 ; index < output_split_number ; index++){
      output_split[index] = avg_split;
    }
  }

  /* acculate index */
  int base = 0;
  for(int index = 0 ; index < output_split_number ; index++){
    output_split[index] = base + output_split[index];
    base = output_split[index];
  }

  /* calculate axisDistance */
  int axisDistance[input_input_ndim];
  int axis_base = axisDistance[input_input_ndim-1] = 1;
  for(int dim = input_input_ndim - 2  ; dim >= 0 ; dim--){
    axisDistance[dim] = axis_base * input_input_dims[dim+1];
    axis_base *= input_input_dims[dim];
  }

  int split_base = 0;
  for(int splitIndex = 0 ; splitIndex < output_split_number ; splitIndex++){
    int output_col = 0;
    forLoop(input_input, 0,
            input_input_ndim, input_input_dims,
            0, axisDistance,
            axis, split_base, output_split[splitIndex],
            output_outputs, splitIndex, &output_col);
    split_base = output_split[splitIndex];
  }
}
