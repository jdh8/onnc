#include <onnc/Runtime/operator/topk.h>

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <float.h>

/* node */
struct node{
    float value;
    int index;
};

static void init(struct node * restrict heap, int input_index, float value, int index){
    heap[input_index].value = value;
    heap[input_index].index = index;
}

static void swap(struct node * a, struct node * b){
    struct node tmp = *a;
    *a = *b;
    *b = tmp;
}

/* node comparison */
static bool smaller(struct node a, struct node b){
	if(a.value < b.value) return true;
	if(a.value > b.value) return false;
	if(a.index > b.index) return true;
	return false;
}

/* up_heap */
static void up_heap(struct node * restrict heap, int index){
    if(index == 1) return;
    if(smaller(heap[index], heap[index/2])){
        swap(&heap[index/2], &heap[index]);
        up_heap(heap, index/2);
        return;
    }
}

/* down_heap */
static void down_heap(struct node * restrict heap, int index, int inside_num){
    if(index >= inside_num) return;

    int right_index = 2 * index + 1;
    int left_index = 2 * index;
    int value = heap[index].value;

    if(left_index > inside_num) return;
	if(right_index > inside_num && smaller(heap[left_index], heap[index])){
        swap(&heap[left_index], &heap[index]);
        down_heap(heap, left_index, inside_num);
		return;
	}

	if(right_index <= inside_num && smaller(heap[left_index], heap[index]) && smaller(heap[left_index], heap[right_index])){
        swap(&heap[left_index], &heap[index]);
        down_heap(heap, left_index, inside_num);
		return;
    }

    if(right_index <= inside_num && smaller(heap[right_index], heap[index])){
        swap(&heap[right_index], &heap[index]);
        down_heap(heap, right_index, inside_num);
		return;
    }
    return;
}

/* insert a node */
static void insert_node(struct node * restrict heap, int inside_num, int value, int index){
    init(heap, inside_num + 1, value, index);
    up_heap(heap, inside_num + 1);
}

static void delete_node(struct node * restrict heap, int inside_num){
    init(heap, 1, FLT_MAX, 0);
    swap(&heap[1], &heap[inside_num]);
    down_heap(heap, 1, inside_num - 1);
}

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

void ONNC_RUNTIME_topk_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_X
  ,int input_X_ndim, const int * restrict input_X_dims
  ,float * restrict output_Values
  ,int output_Values_ndim, const int * restrict output_Values_dims
  ,float * restrict output_Indices
  ,int output_Indices_ndim, const int * restrict output_Indices_dims
  ,int axis
  ,int k
) {
  int axis_dis[input_X_ndim];
  memset(axis_dis, 0, sizeof(int) * input_X_ndim);

  /* calculate_axis_dis */
  calculate_axis_dis(input_X_ndim, input_X_dims, axis_dis);

  /* initialize iter context */
  int iter_ndim = input_X_ndim - 1;
  int iter_max[iter_ndim];
  int iter_axis_dis[iter_ndim];
  int iter_index = 0;
  for(int axis_index = 0 ; axis_index < input_X_ndim ; ++axis_index){
      if(axis_index == axis) continue;
      iter_max[iter_index] = input_X_dims[axis_index];
      iter_axis_dis[iter_index] = axis_dis[axis_index];
      iter_index += 1;
  }
  int iter_base[iter_ndim];
  memset(iter_base, 0, sizeof(int) * iter_ndim);

  int insertIndex = 0;

  /* traverse */
  do{
      int base_offset = dim_to_offset(iter_ndim, iter_base, iter_axis_dis);
      struct node heap[k];
      memset(heap, 0, sizeof(struct node) * k);
      int inside_num = 0;
      for(int axis_index = 0 ; axis_index < input_X_dims[axis]; ++axis_index){
          int offset = base_offset + axis_dis[axis] * axis_index;
          int value = input_X[offset];
          if(inside_num < k){
              insert_node(heap, inside_num, value, axis_index);
              inside_num ++;
          }
          else{
              if(value <= heap[1].value) continue;
              init(heap, 1, value, axis_index);
              down_heap(heap, 1, k);
          }
      }
      struct node output_temp[k];
      memset(output_temp, 0, sizeof(struct node) * k);
      for(int index = k - 1; index >= 0 ; --index){
          output_temp[index] = heap[1];
          delete_node(heap, index + 1);
      }

      for(int index = 0 ; index < k ; ++index){
        output_Values[insertIndex] = output_temp[index].value;
        output_Indices[insertIndex] = output_temp[index].index;
        insertIndex++;
      }
  }while(next_dim(iter_ndim, iter_base, iter_max));
}
