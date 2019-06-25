#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/size.h"
#include <math.h>

void ONNC_RUNTIME_selu_float(void* restrict context,
    const float* restrict X, int32_t ndim, const int32_t* restrict shape,
    float* restrict Y, int32_t Yndim, const int32_t* restrict Yshape,
    float alpha, float gamma)
{
    int32_t size = onnc_size(shape, ndim);

    for (int32_t i = 0; i < size; ++i)
        Y[i] = gamma * (signbit(X[i]) ? alpha * expm1f(X[i]) : X[i]);
}
