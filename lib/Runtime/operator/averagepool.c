#include <onnc/Runtime/operator/averagepool.h>

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

static inline bool next_dim(int ndim, int * restrict dim,
                            const int * restrict dim_max) {
  do {
    ndim = ndim - 1;
    dim[ndim] += 1;
    if (dim[ndim] < dim_max[ndim]) {
      return true;
    } else { // reach dimension max
      if (ndim == 0) { // all dimension done
        return false;
      }
      dim[ndim] = 0;
    }
  } while(true);
}

static inline int64_t dim_to_offset(int ndim, const int * restrict dim,
                                    const int * restrict dim_max) {
  int64_t offset = 0;
  int64_t step = 1;
  for (int i = ndim - 1; i >= 0; --i) {
    offset += dim[i] * step;
    step *= dim_max[i];
  }
  return offset;
}

// If it is outside the bounds of the input, use 0.
static inline float get_value_or_zero(int ndim, const int * restrict dim_max,
                                      const float * restrict value, const int * restrict dim, int * isPad) {
  for (int i = 0; i < ndim; ++i) {
    if (dim[i] < 0 || dim[i] >= dim_max[i]) {
      if(isPad){
        *isPad = 1;
      }
      return 0.f;
    }
  }
  if(isPad){
    *isPad = 0;
  }
  return value[dim_to_offset(ndim, dim, dim_max)];
}

void ONNC_RUNTIME_averagepool_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  ,const char * restrict auto_pad
  ,int count_include_pad
  ,int * restrict kernel_shape
  ,int number_of_kernel_shape
  ,int * restrict pads
  ,int number_of_pads
  ,int * restrict strides
  ,int number_of_strides
) {
  // TODO auto_pad
  int64_t size = 1;
  for (int i = 0; i < input_X_ndim - 2; ++i) {
    size *= kernel_shape[i];
  }

  int o_dim[input_X_ndim];
  memset(o_dim, 0, sizeof(o_dim));
  do { // while o_dim
    int base_dim[input_X_ndim];
    for (int i = 2; i < input_X_ndim; ++i) {
      base_dim[i] = o_dim[i] * strides[i - 2] - pads[i - 2];
    }

    float sum = 0.f;

    int k_dim[input_X_ndim - 2];
    memset(k_dim, 0, sizeof(k_dim));
    int padCount = 0;
    do { // while k_dim
      int i_dim[input_X_ndim];
      i_dim[0] = o_dim[0]; // N
      i_dim[1] = o_dim[1]; // C
      for (int i = 2; i < input_X_ndim; ++i) {
        i_dim[i] = base_dim[i] + k_dim[i - 2];
      }
      int isPad = 0;
      sum += get_value_or_zero(input_X_ndim, input_X_dims, input_X, i_dim, &isPad);
      if(isPad){
        ++padCount;
      }
    } while (next_dim(input_X_ndim - 2, k_dim, kernel_shape));
    if (count_include_pad) {
      sum /= size;
    } else {
      sum /= (size - padCount);
    }

    output_Y[dim_to_offset(input_X_ndim, o_dim, output_Y_dims)] = sum;
  } while (next_dim(input_X_ndim, o_dim, output_Y_dims));
}
