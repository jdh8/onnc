#define restrict __restrict__
extern "C"{
    #include <onnc/Runtime/operator/gemm.h>
}
#undef restrict

#include <skypat/skypat.h>
#include <cstring>
#include <cstdint>

SKYPAT_F(Operator_Gemm, pure_gemm)
{
    const float A[] = { 1, 2, 3, 4 };
    const float B[] = { 5, 6, 7, 8 };
    const float AB[]   = { 19, 22, 43, 50 };
    const float ATB[]  = { 26, 30, 38, 44 };
    const float ABT[]  = { 17, 23, 39, 53 };
    const float ATBT[] = { 23, 31, 34, 46 };
    const float O = -0.0f;
    const std::int32_t shape[] = { 2, 2 };
    float Y[4];

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, &O, 0, nullptr, Y, 2, shape, 1, 0, 0, 0);
    EXPECT_FALSE(std::memcmp(Y, AB, sizeof(A)));

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, &O, 0, nullptr, Y, 2, shape, 1, 0, 1, 0);
    EXPECT_FALSE(std::memcmp(Y, ATB, sizeof(A)));

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, &O, 0, nullptr, Y, 2, shape, 1, 0, 0, 1);
    EXPECT_FALSE(std::memcmp(Y, ABT, sizeof(A)));

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, &O, 0, nullptr, Y, 2, shape, 1, 0, 1, 1);
    EXPECT_FALSE(std::memcmp(Y, ATBT, sizeof(A)));
}

SKYPAT_F(Operator_Gemm, pure_broadcasting)
{
    const float x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const float broadcasted[] = { 1, 1, 1, 2, 2, 2, 3, 3, 3 };
    const float repeated[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3 };
    const float filled[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    const std::int32_t square[] = { 3, 3 };
    const std::int32_t colvec[] = { 3, 1 };
    const std::int32_t rowvec[] = { 1, 3 };
    const std::int32_t length = 3;
    float y[9];

    ONNC_RUNTIME_gemm_float(nullptr, x, 2, square, x, 2, square, x, 2, square, y, 2, square, -0.0f, 1, 0, 0);
    EXPECT_FALSE(std::memcmp(y, x, sizeof(x)));

    ONNC_RUNTIME_gemm_float(nullptr, x, 2, square, x, 2, square, x, 2, colvec, y, 2, square, -0.0f, 1, 0, 0);
    EXPECT_FALSE(std::memcmp(y, broadcasted, sizeof(x)));

    ONNC_RUNTIME_gemm_float(nullptr, x, 2, square, x, 2, square, x, 2, rowvec, y, 2, square, -0.0f, 1, 0, 0);
    EXPECT_FALSE(std::memcmp(y, repeated, sizeof(x)));

    ONNC_RUNTIME_gemm_float(nullptr, x, 2, square, x, 2, square, x, 1, &length, y, 2, square, -0.0f, 1, 0, 0);
    EXPECT_FALSE(std::memcmp(y, repeated, sizeof(x)));

    ONNC_RUNTIME_gemm_float(nullptr, x, 2, square, x, 2, square, x, 0, nullptr, y, 2, square, -0.0f, 1, 0, 0);
    EXPECT_FALSE(std::memcmp(y, filled, sizeof(x)));
}

SKYPAT_F(Operator_Gemm, combined)
{
    const float A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const float B[] = { 6, 5, 4, 3, 2, 1 };
    const float C[] = { 1, 2, 3, 4, 5, 6 };
    const float AB[] = { 20, 14, 56, 41, 92, 68 };
    const float O = -0.0f;
    const std::int32_t square[] = { 3, 3 };
    const std::int32_t thin[] = { 3, 2 };
    const std::int32_t vector[] = { 3, 1 };
    float Y[6];

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, square, B, 2, thin, &O, 0, nullptr, Y, 2, thin, 1, 0, 0, 0);
    EXPECT_FALSE(std::memcmp(Y, AB, sizeof(C)));

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, square, B, 2, thin, AB, 2, thin, Y, 2, thin, 0.75f, 0.25f, 0, 0);
    EXPECT_FALSE(std::memcmp(Y, AB, sizeof(C)));

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, square, B, 2, thin, C, 2, thin, Y, 2, thin, 1, 1, 0, 0);

    for (std::int32_t i = 0; i < 6; ++i)
        EXPECT_EQ(Y[i], AB[i] + C[i]);

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, square, B, 2, thin, C, 2, thin, Y, 2, thin, 1, -1, 0, 0);

    for (std::int32_t i = 0; i < 6; ++i)
        EXPECT_EQ(Y[i], AB[i] - C[i]);

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, square, B, 2, thin, C, 1, thin + 1, Y, 2, thin, -3, 2, 0, 0);

    for (std::int32_t i = 0; i < 6; ++i)
        EXPECT_EQ(Y[i], -3 * AB[i] + 2 * C[i & 1]);

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, square, B, 2, thin, C, 2, vector, Y, 2, thin, -1, -4, 0, 0);

    for (std::int32_t i = 0; i < 6; ++i)
        EXPECT_EQ(Y[i], -AB[i] - 4 * C[i >> 1]);
}
