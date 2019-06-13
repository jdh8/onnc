#include <onnc/Runtime/operator/transpose.h>

#include <stdint.h>
#include <stdio.h>

void ONNC_RUNTIME_transpose_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_transposed
  ,int output_transposed_ndim, const int * restrict output_transposed_dims
  ,int * restrict perm
  ,int number_of_perm
) {
  // Prepare
  int elemCount = 1;
  int coordSize[input_data_ndim];
  for (int i = 0; i < input_data_ndim; i++){
    coordSize[input_data_ndim - 1 - i] = elemCount;
    elemCount *= input_data_dims[i];
  }
  // TODO: Check if perm duplicate or not;
  for (int rawIndex = 0; rawIndex < elemCount; ++rawIndex){
    int coord[input_data_ndim];
    // Coordinate
    for(int i = 0, tmpRaw = rawIndex; i < input_data_ndim; ++i){
      coord[i] = tmpRaw / coordSize[i];
      tmpRaw %= coordSize[i];
    }
    // Assign to destination
    int destIndex = 0;
    for(int i = 0; i < input_data_ndim; ++i){
      destIndex += coord[perm[i]] * coordSize[i];
    }
    output_transposed[rawIndex] = input_data[destIndex];
  }
}
