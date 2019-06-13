#include <onnc/Runtime/operator/argmax.h>

#include <stdint.h>
#include <float.h>
#include <stdbool.h>

static int findIndex(int index, int axisDim, int elementDistance){
  return (index / (axisDim * elementDistance)) * elementDistance + index % elementDistance;
}

void ONNC_RUNTIME_argmax_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_reduced
  ,int output_reduced_ndim, const int * restrict output_reduced_dims
  ,int axis
  ,int keepdims
) {
  int axisDim = input_data_dims[axis];
  int axisElementDistance = 1;
  for(int dim = axis + 1 ; dim < input_data_ndim ; dim++){
    axisElementDistance *= input_data_dims[dim];
  }

  int size = axisElementDistance;
  for(int dim = 0 ; dim <= axis ; dim++){
    size *= input_data_dims[dim];
  }

  int try = 0;
  while(try < size){
    /* Initialize try context */
    int index = try;
    float max = FLT_MIN;
    int axisIndex = 0, maxIndex = 0;
    while(axisIndex < axisDim){
      if(input_data[index] > max){
        max = input_data[index];
        maxIndex = axisIndex;
      }
      index += axisElementDistance;
      axisIndex += 1;
    }

    /* fill the data to output */
    int fillIndex = findIndex(try, axisDim, axisElementDistance);
    output_reduced[fillIndex] = maxIndex;

    /* update round context */
    if(try % axisElementDistance == axisElementDistance - 1){
      try = ((try + 1) - axisElementDistance) + axisElementDistance * axisDim;
    }
    else{
      try += 1;
    }
  }
}
