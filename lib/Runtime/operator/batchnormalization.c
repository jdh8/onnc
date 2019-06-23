#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/size.h"
#include <math.h>

void ONNC_RUNTIME_batchnormalization_float(void* restrict context,
    const float* restrict X, int32_t Xndim, const int32_t* restrict Xshape,
    const float* restrict scale, int32_t scale_ndim, const int32_t* restrict scale_shape,
    const float* restrict B, int32_t Bndim, const int32_t* restrict Bshape,
    const float* restrict mean, int32_t mean_ndim, const int32_t* restrict mean_shape,
    const float* restrict var, int32_t var_ndim, const int32_t* restrict var_shape,
    float* restrict Y, int32_t Yndim, const int32_t* restrict Yshape,
    float* restrict running_mean, int32_t running_mean_ndim, const int32_t* restrict running_mean_shape,
    float* restrict running_var, int32_t running_var_ndim, const int32_t* restrict running_var_shape,
    float* restrict saved_mean, int32_t saved_mean_ndim, const int32_t* restrict saved_mean_shape,
    float* restrict saved_var, int32_t saved_var_ndim, const int32_t* restrict saved_var_shape,
    float epsilon, float momentum, int32_t spatial)
{
    int32_t batches = Xshape[0];
    int32_t channels = Xshape[1];
    int32_t pixels = onnc_size(Xshape + 2, Xndim - 2);

    float coeffs[channels];
    float shifts[channels];

    for (int32_t j = 0; j < channels; ++j) {
        coeffs[j] = scale[j] / sqrtf(var[j] + epsilon);
        shifts[j] = B[j] - mean[j] * coeffs[j];
    }

    for (int32_t i = 0; i < batches; ++i) {
        for (int32_t j = 0; j < channels; ++j) {
            for (int32_t k = 0; k < pixels; ++k) {
                int32_t offset = (i * channels + j) * pixels + k;
                Y[offset] = coeffs[j] * X[offset] + shifts[j];
            }
        }
    }
}
