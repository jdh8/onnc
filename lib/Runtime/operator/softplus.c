#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/size.h"
#include <math.h>

void ONNC_RUNTIME_softplus_float(void* restrict context,
    const float* restrict X, int32_t ndim, const int32_t* restrict shape,
    float* restrict Y, int32_t Yndim, const int32_t* restrict Yshape)
{
    int32_t size = onnc_size(shape, ndim);

    for (int32_t i = 0; i < size; ++i)
        Y[i] = log1pf(expf(X[i]));
}
