#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/assign.h"

void ONNC_RUNTIME_expand_float(void* restrict context,
    const float* restrict X, int32_t Xndim, const int32_t* restrict Xshape,
    const float* restrict shape, int32_t shape_ndim, const int32_t* restrict shape_shape,
    float* restrict Y, int32_t Yndim, const int32_t* restrict Yshape)
{
    ONNC_ASSIGN(float, Y, Yshape, Yndim, X, Xshape, Xndim);
}
