#include <onnc/Runtime/operator/concat.h>

#include <stdint.h>
#include <stdbool.h>

void ONNC_RUNTIME_concat_float(
  void * restrict onnc_runtime_context
  ,const float * const * restrict input_inputs
  ,int input_inputs_ntensor
  ,const int * input_inputs_ndim, const int * const * restrict input_inputs_dims
  ,float * restrict output_concat_result
  ,int output_concat_result_ndim, const int * restrict output_concat_result_dims
  ,int axis
) {
  int elementDistance[input_inputs_ntensor];
  for(int ntensor = 0 ; ntensor < input_inputs_ntensor ; ntensor++){
    elementDistance[ntensor] = 1;
    for(int dim = axis ; dim < input_inputs_ndim[ntensor] ; dim++){
      elementDistance[ntensor] *= input_inputs_dims[ntensor][dim];
    }
  }

  int size[input_inputs_ntensor];
  for(int ntensor = 0 ; ntensor < input_inputs_ntensor ; ntensor++){
    size[ntensor] = elementDistance[ntensor];
    for(int dim = 0 ; dim < axis ; dim++){
      size[ntensor] *= input_inputs_dims[ntensor][dim];
    }
  }

  int axisDim = input_inputs_dims[0][axis];
  int axisIndex = 0;
  int insertIndex = 0;
  while(axisIndex < axisDim){
    for(int ntensor = 0; ntensor < input_inputs_ntensor ; ntensor++){
      int base = axisIndex * elementDistance[ntensor];
      int index = base;
      int nElementDistance = elementDistance[ntensor];
      while(index < size[ntensor]){
        output_concat_result[insertIndex] = input_inputs[ntensor][index];
        insertIndex++;
        if(index % nElementDistance == nElementDistance - 1){
          index = index + 1 - nElementDistance + nElementDistance * axisDim;
        }
        else{
          ++index;
        }
      }
    }
    ++axisIndex;
  }
}
