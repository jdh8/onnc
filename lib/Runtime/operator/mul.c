typedef float Scalar;
typedef int Index;

#include "generic/binary.h"

static float _mul(float a, float b)
{
    return a * b;
}

void ONNC_RUNTIME_mul_float(void* restrict context,
    const float* restrict A, int Adim, const int* restrict Ashape,
    const float* restrict B, int Bdim, const int* restrict Bshape,
    float* restrict C, int Cdim, const int* restrict Cshape)
{
    _binary(C, _mul, A, Ashape, Adim, B, Bshape, Bdim);
}
