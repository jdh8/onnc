#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/size.h"
#include <string.h>

void ONNC_RUNTIME_dropout_float(void* context,
    const float* restrict x, int32_t ndim, const int32_t* restrict shape,
    float* restrict y, int32_t yndim, const int32_t* restrict yshape,
    float* restrict mask, int32_t mask_ndim, const int32_t* restrict mask_shape,
    float ratio)
{
    memcpy(y, x, onnc_size(shape, ndim) * sizeof(float));
}
