#include <onnc/Runtime/operator/lpnormalization.h>

#include <stdint.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

void ONNC_RUNTIME_lpnormalization_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int axis
  ,int p
) {
  //calculate new dimension
  int ndim = input_input_ndim;

  //ndim corresponding to axis
  //axis accept neg value
  if(axis < 0){
    axis += ndim;
  } 

  //output elements
  int output_elem = 1;
  int input_elem = 1;
  int output_dims[ndim - 1];

  int ip = 0;
  for(int i = 0; i < ndim; i++){
    if(i != axis){
      output_elem *= input_input_dims[i];
      output_dims[ip] = input_input_dims[i];
      ip++;
    }
    input_elem *= input_input_dims[i];
  }
  
  //input stride, for reference
  int InDimStride[ndim];
  InDimStride[ndim-1] = 1;
  for(int i = (ndim - 1) - 1; i >= 0; i--){
    InDimStride[i] = InDimStride[i+1] * input_input_dims[i+1];
  }

  int out_ndim = ndim -1;
  int OutDimStride[out_ndim];
  OutDimStride[out_ndim-1] = 1;
  for(int i = (out_ndim - 1) - 1; i >= 0; i--){
    OutDimStride[i] = OutDimStride[i+1] * output_dims[i+1];
  }

  //p-norm process
  //To locate coordinates, count the strides!
  int inDimCounter = 0;
  int outDimCounter= 0;

  int inIndexCounter = 0;
  int outIndexCounter = 0;

  float summation[output_elem];
  for(int i = 0; i < output_elem; i++){
    summation[i] = 0.0f;
  }

  //Forumala 
  int index = 0;
  for(int j = 0; j < input_elem; j++){
    inIndexCounter = j;
    outIndexCounter = 0;
    outDimCounter = 0;
    inDimCounter = 0;
    while(inDimCounter < ndim){
      index = inIndexCounter / InDimStride[inDimCounter];
      inIndexCounter %= InDimStride[inDimCounter];
      if(inDimCounter != axis){
        outIndexCounter += (index * OutDimStride[outDimCounter]);
        outDimCounter++;
      }
      inDimCounter++;
    }
    summation[outIndexCounter] += fabs(powf(input_input[j], p));
  }

  //Formula
  for(int i = 0; i < output_elem; i++){
    output_output[i] = powf(summation[i], (1.0f/(float)p)); 
  }
}
