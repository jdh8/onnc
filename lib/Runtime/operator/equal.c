#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/compare.h"

static float equal_(float x, float y)
{
    return x == y;
}

void ONNC_RUNTIME_equal_float(void* restrict context,
    const float* restrict A, int32_t Adim, const int32_t* restrict Ashape,
    const float* restrict B, int32_t Bdim, const int32_t* restrict Bshape,
    float* restrict C, int32_t Cdim, const int32_t* restrict Cshape)
{
    ONNC_COMPARE(float, float, C, Cshape, Cdim, A, Ashape, Adim, B, Bshape, Bdim, equal_);
}
