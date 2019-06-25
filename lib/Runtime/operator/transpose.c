#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/transpose.h"

void ONNC_RUNTIME_transpose_float(void* restrict context,
    const float* restrict X, int32_t Xdim, const int32_t* restrict Xshape,
    float* restrict Y, int32_t Ydim, const int32_t* restrict Yshape,
    const int32_t* restrict permute, int32_t given)
{
    int32_t reverse[Xdim];

    for (int32_t i = 0; i < Xdim; ++i)
        reverse[i] = Xdim - 1 - i;

    ONNC_TRANSPOSE(float, Y, X, given && permute ? permute : reverse, Xshape, Xdim);
}
