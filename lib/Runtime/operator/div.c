#include <stdint.h>

typedef float Scalar;
typedef int32_t Index;

#include "generic/assign.h"
#include "generic/binary.h"

static float div_(float a, float b)
{
    return a / b;
}

void ONNC_RUNTIME_div_float(void* restrict context,
    const float* restrict A, int32_t Adim, const int32_t* restrict Ashape,
    const float* restrict B, int32_t Bdim, const int32_t* restrict Bshape,
    float* restrict C, int32_t Cdim, const int32_t* restrict Cshape)
{
    assign_(C, Cshape, Cdim, A, Ashape, Adim);
    binary_(C, Cshape, Cdim, B, Bshape, Bdim, div_);
}
