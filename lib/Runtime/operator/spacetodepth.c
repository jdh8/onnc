#include <onnc/Runtime/operator/spacetodepth.h>

#include <stdint.h>
#include <stdbool.h>

static void calculateAxisDistance(int ndim, const int * restrict dims, int * restrict axis_dis){
  int base = axis_dis[ndim - 1] = 1;
  for(int dim = ndim-2 ; dim >= 0 ; dim--){
    axis_dis[dim] = base * dims[dim+1];
    base = axis_dis[dim];
  }
}

static int dim_to_offset(int N, int C, int H, int W, int * restrict axis_dis){
  return N * axis_dis[0] + C * axis_dis[1] + H * axis_dis[2] + W * axis_dis[3];
}

void ONNC_RUNTIME_spacetodepth_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_input
  ,int input_input_ndim, const int * restrict input_input_dims
  ,float * restrict output_output
  ,int output_output_ndim, const int * restrict output_output_dims
  ,int blocksize
) {
    /* calculate axis distance */
    int axis_dis[input_input_ndim];
    calculateAxisDistance(input_input_ndim, input_input_dims, axis_dis);
    int insertIndex = 0;
    int H_num = input_input_dims[2] / blocksize;
    int W_num = input_input_dims[3] / blocksize;
    for(int N = 0 ; N < input_input_dims[0] ; ++N){
      for(int C = 0 ; C < input_input_dims[1] ; ++C){
        for(int block_H = 0 ; block_H < H_num ; ++block_H){
          for(int block_W = 0 ; block_W < W_num ; ++block_W){
            for(int fill_H = block_H * blocksize ; fill_H < (block_H + 1) * blocksize ; ++fill_H){
              for(int fill_W = block_W * blocksize; fill_W < (block_W + 1) * blocksize ; ++fill_W){
                output_output[insertIndex++] = input_input[dim_to_offset(N, C, fill_H, fill_W, axis_dis)];
              }
            }
          }
        }
      }
    }
}
