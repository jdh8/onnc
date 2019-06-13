#include <onnc/Runtime/operator/reducemax.h>

#include <stdint.h>
#include <stdbool.h>
#include <float.h>

void ONNC_RUNTIME_reducemax_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_reduced
  ,int output_reduced_ndim, const int * restrict output_reduced_dims
  ,int * restrict axes
  ,int number_of_axes
  ,int keepdims
) {
  int ndim = input_data_ndim;
  int nk_ndim = input_data_ndim - number_of_axes;
  
  //output elements
  int nk_output_elem = 1;
  int input_elem = 1;

  int nk_output_dims[nk_ndim];
  int ip = 0;
  int counter;
  bool axisSave;
  for(int i = 0; i < ndim; i++){
    counter = 0;
    for(int j = 0; j < number_of_axes; j++){
      if(i != axes[j]) counter++;
    }
    if(counter == number_of_axes){
      nk_output_dims[ip] = input_data_dims[i];
      nk_output_elem *= nk_output_dims[ip];
      ip++;
    }
    input_elem *= input_data_dims[i];
  }

  //Result array
  float result[nk_output_elem];

  //input stride, for reference
  int InDimStride[ndim];
  InDimStride[ndim-1] = 1;
  for(int i = (ndim - 1) - 1; i >= 0; i--){
    InDimStride[i] = InDimStride[i+1] * input_data_dims[i+1];
  }

  int OutDimStride[nk_ndim];
  OutDimStride[nk_ndim-1] = 1;
  for(int i = (nk_ndim - 1) - 1; i >= 0; i--){
    OutDimStride[i] = OutDimStride[i+1] * nk_output_dims[i+1];
  }

  //reduce process keepdim = false
  //To locate coordinates, count the strides!

  //iteration setup
  int inDimCounter = 0;
  int outDimCounter= 0;
  int inIndexCounter = 0;
  int outIndexCounter = 0;

  int index = 0;
  float max_temp[nk_output_elem];
  for(int i = 0; i < nk_output_elem; i++){
    max_temp[i] = FLT_MIN;
  }

  //This 3 loop using top down algorithm to reduce the max 
  //locate index , transform to constiguous array index
  //ommit the AXES DIMENTION in order to obtain MAX in certain vector
  for(int i = 0; i < input_elem; i++){
    inIndexCounter = i;
    outIndexCounter = 0;
    inDimCounter = 0;
    outDimCounter = 0;
    while(inDimCounter < ndim){
      counter = 0;
      index = inIndexCounter / InDimStride[inDimCounter];
      inIndexCounter %= InDimStride[inDimCounter];
      for(int j = 0; j < number_of_axes; j++){
        if(inDimCounter != axes[j]) counter++;
      }
      if(counter == number_of_axes){
          outIndexCounter += (index * OutDimStride[outDimCounter]);
          outDimCounter++;
      }
      inDimCounter++;
    }
    if(input_data[i] >= max_temp[outIndexCounter]){
      //SOLUTION
      max_temp[outIndexCounter] = input_data[i];
      result[outIndexCounter] = max_temp[outIndexCounter];
    }
  }

  //keep dimension
  if(keepdims == 1){
    for(int i = 0; i < input_elem; i++){
      inIndexCounter = i;
      outIndexCounter = 0;
      inDimCounter = 0;
      outDimCounter = 0;
      while(inDimCounter < ndim){
        counter = 0;
        index = inIndexCounter / InDimStride[inDimCounter];
        inIndexCounter %= InDimStride[inDimCounter];
        for(int j = 0; j < number_of_axes; j++){
          if(inDimCounter != axes[j]) counter++;
        }
        if(counter == number_of_axes){
          outIndexCounter += (index * OutDimStride[outDimCounter]);
          outDimCounter++;
        }
        inDimCounter++;
      }
      output_reduced[i] = result[outIndexCounter];
    }
  }else if(keepdims == 0){
    for(int i = 0; i < nk_output_elem; i++){
      output_reduced[i] = result[i];
    }
  }
}
