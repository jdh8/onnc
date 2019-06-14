#include <stdint.h>

typedef float Scalar;
typedef int32_t Index;

#include "generic/assign.h"
#include "generic/binary.h"

static float _mul(float a, float b)
{
    return a * b;
}

void ONNC_RUNTIME_mul_float(void* restrict context,
    const float* restrict A, int32_t Adim, const int32_t* restrict Ashape,
    const float* restrict B, int32_t Bdim, const int32_t* restrict Bshape,
    float* restrict C, int32_t Cdim, const int32_t* restrict Cshape)
{
    _assign(C, Cshape, Cdim, A, Ashape, Adim);
    _binary(C, Cshape, Cdim, B, Bshape, Bdim, _mul);
}
