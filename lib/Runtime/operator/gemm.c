typedef float Scalar;
typedef int Index;

#include "generic/assign.h"
#include "generic/gemm.h"
#include "generic/size.h"

void ONNC_RUNTIME_gemm_float(void* restrict context,
    const float* restrict A, int Adim, const int* restrict Ashape,
    const float* restrict B, int Bdim, const int* restrict Bshape,
    const float* restrict C, int Cdim, const int* restrict Cshape,
    float* restrict Y, int Ydim, const int* restrict Yshape,
    float alpha, float beta, int transA, int transB)
{
    int rows = Yshape[0];
    int cols = Yshape[1];
    int depth = Ashape[!transA];

    _assign(Y, Yshape, 2, C, Cshape, Cdim);

    for (int i = 0; i < rows * cols; ++i)
        Y[i] *= beta;

    _gemm(Y, A, B, alpha, rows, cols, depth, transA, transB);
}
