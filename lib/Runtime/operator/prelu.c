#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/assign.h"
#include "generic/size.h"
#include <math.h>

void ONNC_RUNTIME_prelu_float(void* restrict context,
    const float* restrict X, int32_t ndim, const int32_t* restrict shape,
    const float* restrict slope, int32_t slope_ndim, const int32_t* restrict slope_shape,
    float* restrict Y, int32_t Yndim, const int32_t* restrict Yshape)
{
    int32_t size = onnc_size(shape, ndim);

    ONNC_ASSIGN(float, Y, shape, ndim, slope, slope_shape, slope_ndim);

    for (int32_t i = 0; i < size; ++i)
        Y[i] = signbit(X[i]) ? Y[i] * X[i] : X[i];
}
