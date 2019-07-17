#include <stdint.h>
typedef int32_t ONNC_INDEX_TYPE;

#include "generic/size.h"
#include <string.h>

void ONNC_RUNTIME_split_float(void* restrict context,
    const float* restrict input, int32_t ndim, const int32_t* restrict shape,
    float* restrict* outputs, int32_t count, const int32_t* restrict ndims, const int32_t* restrict* shapes,
    int32_t axis, const int32_t* split, int32_t nsplit)
{
    int32_t slices = onnc_size(shape, axis);
    int32_t block = onnc_size(shape + axis + 1, ndim - axis - 1);

    int32_t offsets[count];

    offsets[0] = 0;

    for (int32_t i = 0; i < count - 1; ++i)
        offsets[i + 1] = offsets[i] + split[i];

    for (int32_t i = 0; i < count; ++i) {
        for (int32_t j = 0; j < slices; ++j) {
            int32_t length = split[i] * block;
            memcpy(outputs[i] + j * length, input + (offsets[i] + j * shape[axis]) * block, length * sizeof(float));
        }
    }
}
