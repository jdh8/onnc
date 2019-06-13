#include <onnc/Runtime/operator/reducesumsquare.h>

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

static inline void calculate_axis_dis(int ndim, const int * restrict dims, int * restrict axis_dis){
    int base = axis_dis[ndim-1] = 1;
    for(int dim = ndim - 2 ; dim >= 0 ; --dim){
        axis_dis[dim] = base * dims[dim+1];
        base = axis_dis[dim];
    }
}

static inline bool next_dim(int ndim, int * restrict dim, const int * restrict dim_max) {
  if(ndim == 0)
    return false;
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
                                    const int * restrict axisDistance) {
  if(ndim == 0) return 0;
  int64_t offset = 0;
  for (int i = ndim - 1; i >= 0; --i) {
    offset += dim[i] * axisDistance[i];
  }
  return offset;
}

void ONNC_RUNTIME_reducesumsquare_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_data
  ,int input_data_ndim, const int * restrict input_data_dims
  ,float * restrict output_reduced
  ,int output_reduced_ndim, const int * restrict output_reduced_dims
  ,int * restrict axes
  ,int number_of_axes
  ,int keepdims
) {
  /* initial axis */
  int mask = 0;

  /* on bit means in parameter axes */
  for(int axis = 0 ; axis < number_of_axes ; axis++){
    mask |= (1 << axes[axis]);
  }

  /* calculate axis_dis */
  int axis_dis[input_data_ndim];
  calculate_axis_dis(input_data_ndim, input_data_dims, axis_dis);

  /* initial iterative context */
  int not_in_axes_num = input_data_ndim - number_of_axes;
  int iter_not_in_axes_max[not_in_axes_num];
  int not_in_axes_axis_dis[input_data_ndim];
  int not_in_axes_axis_index = 0;

  int iter_in_axes_max[number_of_axes];
  int in_axes_axis_dis[number_of_axes];
  int in_axes_axis_index = 0;
  for(int axis = 0 ; axis < input_data_ndim; axis++){
    if(mask & (1 << axis)){
      in_axes_axis_dis[in_axes_axis_index] = axis_dis[axis];
      iter_in_axes_max[in_axes_axis_index] = input_data_dims[axis];
      in_axes_axis_index += 1;
      continue;
    }
    not_in_axes_axis_dis[not_in_axes_axis_index] = axis_dis[axis];
    iter_not_in_axes_max[not_in_axes_axis_index] = input_data_dims[axis];
    not_in_axes_axis_index += 1;
  }

  /* traverse all axis other than parameter axes */
  int insertIndex = 0;
  int iter_not_in_axes[not_in_axes_num];
  memset(iter_not_in_axes, 0, sizeof(int) * not_in_axes_num);
  do{
    int iter_in_axes[number_of_axes];
    memset(iter_in_axes, 0, sizeof(int) * number_of_axes);
    int base_offset = dim_to_offset(not_in_axes_num, iter_not_in_axes, not_in_axes_axis_dis);
    float sum = 0.f;

    /* traver all axes with fixed axis */
    do{
      int offset = base_offset + dim_to_offset(number_of_axes, iter_in_axes, in_axes_axis_dis);
      sum += (input_data[offset] * input_data[offset]);
    }while(next_dim(number_of_axes, iter_in_axes, iter_in_axes_max));
    output_reduced[insertIndex++] = sum;
  }while(next_dim(not_in_axes_num, iter_not_in_axes, iter_not_in_axes_max));
}
