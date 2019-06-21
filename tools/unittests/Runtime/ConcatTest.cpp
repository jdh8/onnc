#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
#include <skypat/skypat.h>
#include <cstring>

SKYPAT_F(Operator_Concat, test_1d)
{
    const float input_0[] = { 1, 2 };
    const float input_1[] = { 3, 4, 5 };
    const float* inputs[] = { input_0, input_1 };

    const int32_t input_ndims[] = { 1, 1 };

    const int32_t input_0_shape[] = { 2 };
    const int32_t input_1_shape[] = { 3 };
    const int32_t* input_shapes[] = { input_0_shape, input_1_shape };

    const float output[] = { 1, 2, 3, 4, 5 };
    const int32_t output_ndim = 1;
    const int32_t output_shape[] = { 5 };

    float buffer[5];

    ONNC_RUNTIME_concat_float(nullptr,
        inputs, 2, input_ndims, input_shapes,
        buffer, output_ndim, output_shape,
        0);

    ASSERT_FALSE(std::memcmp(buffer, output, sizeof(buffer)));
}

SKYPAT_F(Operator_Concat, test_2d)
{
    const float input_0[] = { 1, 2, 3, 4 };
    const float input_1[] = { 5, 6, 7, 8 };
    const float* inputs[] = { input_0, input_1 };

    const int32_t input_ndims[] = { 2, 2 };

    const int32_t input_0_shape[] = { 2, 2 };
    const int32_t input_1_shape[] = { 2, 2 };
    const int32_t* input_shapes[] = { input_0_shape, input_1_shape };

    const float output_0[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    const int32_t output_0_ndim = 2;
    const int32_t output_0_shape[] = { 4, 2 };

    const float output_1[] = { 1, 2, 5, 6, 3, 4, 7, 8 };
    const int32_t output_1_ndim = 2;
    const int32_t output_1_shape[] = { 2, 4 };

    float buffer[8];

    ONNC_RUNTIME_concat_float(nullptr,
        inputs, 2, input_ndims, input_shapes,
        buffer, output_0_ndim, output_0_shape,
        0);

    ASSERT_FALSE(std::memcmp(buffer, output_0, sizeof(buffer)));

    ONNC_RUNTIME_concat_float(nullptr,
        inputs, 2, input_ndims, input_shapes,
        buffer, output_1_ndim, output_1_shape,
        1);

    ASSERT_FALSE(std::memcmp(buffer, output_1, sizeof(buffer)));
}

SKYPAT_F(Operator_Concat, test_3d)
{
    const float input_0[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    const float input_1[] = { 9, 10, 11, 12, 13, 14, 15, 16 };
    const float* inputs[] = { input_0, input_1 };

    const int32_t input_ndims[] = { 3, 3 };

    const int32_t input_0_shape[] = { 2, 2, 2 };
    const int32_t input_1_shape[] = { 2, 2, 2 };
    const int32_t* input_shapes[] = { input_0_shape, input_1_shape };

    const float output_0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    const int32_t output_0_ndim = 3;
    const int32_t output_0_shape[] = { 4, 2, 2 };

    const float output_1[] = { 1, 2, 3, 4, 9, 10, 11, 12, 5, 6, 7, 8, 13, 14, 15, 16 };
    const int32_t output_1_ndim = 3;
    const int32_t output_1_shape[] = { 2, 4, 2 };

    const float output_2[] = { 1, 2, 9, 10, 3, 4, 11, 12, 5, 6, 13, 14, 7, 8, 15, 16 };
    const int32_t output_2_ndim = 3;
    const int32_t output_2_shape[] = { 2, 2, 4 };

    float buffer[16];

    ONNC_RUNTIME_concat_float(nullptr,
        inputs, 2, input_ndims, input_shapes,
        buffer, output_0_ndim, output_0_shape,
        0);

    ASSERT_FALSE(std::memcmp(buffer, output_0, sizeof(buffer)));

    ONNC_RUNTIME_concat_float(nullptr,
        inputs, 2, input_ndims, input_shapes,
        buffer, output_1_ndim, output_1_shape,
        1);

    ASSERT_FALSE(std::memcmp(buffer, output_1, sizeof(buffer)));

    ONNC_RUNTIME_concat_float(nullptr,
        inputs, 2, input_ndims, input_shapes,
        buffer, output_2_ndim, output_2_shape,
        2);

    ASSERT_FALSE(std::memcmp(buffer, output_2, sizeof(buffer)));
}
