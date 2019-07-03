#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/size.h"
#include <string.h>

void ONNC_RUNTIME_cast_float(void* restrict context,
    const float* X, int32_t Xorder, const int32_t* restrict Xshape,
    float* Y, int32_t Yorder, const int32_t* restrict Yshape,
    int32_t to)
{
    memcpy(Y, X, onnc_size(Xshape, Xorder) * sizeof(float));
}
