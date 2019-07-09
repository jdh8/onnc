#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/size.h"

void ONNC_RUNTIME_argmin_float(void* restrict context,
    const float* restrict x, int32_t order, const int32_t* shape,
    float* restrict y, int32_t ndim, const int32_t* reduced,
    int32_t axis, int32_t keepdims)
{
    if (!order) {
        *y = 0;
        return;
    }

    int32_t depth = shape[axis];
    int32_t rows = onnc_size(shape, axis);
    int32_t cols = onnc_size(shape + axis + 1, order - axis - 1);

    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < cols; ++j) {
            int32_t candidate = 0;
            int32_t offset = i * depth * cols + j;

            for (int32_t k = 1; k < depth; ++k)
                if (x[candidate * cols + offset] > x[k * cols + offset])
                    candidate = k;

            y[i * cols + j] = candidate;
        }
    }
}
