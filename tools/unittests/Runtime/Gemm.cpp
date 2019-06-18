#define restrict __restrict__
extern "C"{
    #include <onnc/Runtime/operator/gemm.h>
}
#undef restrict

#include <skypat/skypat.h>
#include <cstring>

SKYPAT_F(Operator_GEMM, all)
{
    const float I[] = { 1, 0, 0, 1 };
    const float A[] = { 1, 2, 3, 4 };
    const float B[] = { 5, 6, 7, 8 };
    const float AB[]   = { 19, 22, 43, 50 };
    const float ATB[]  = { 26, 30, 38, 44 };
    const float ABT[]  = { 17, 23, 39, 53 };
    const float ATBT[] = { 23, 31, 34, 46 };
    const int shape[] = { 2, 2 };

    float Y[4];

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, A, 2, shape, Y, 2, shape, 1, 0, 0, 0);
    EXPECT_FALSE(std::memcmp(Y, AB, sizeof(A)));

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, A, 2, shape, Y, 2, shape, 1, 0, 1, 0);
    EXPECT_FALSE(std::memcmp(Y, ATB, sizeof(A)));

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, A, 2, shape, Y, 2, shape, 1, 0, 0, 1);
    EXPECT_FALSE(std::memcmp(Y, ABT, sizeof(A)));

    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, A, 2, shape, Y, 2, shape, 1, 0, 1, 1);
    EXPECT_FALSE(std::memcmp(Y, ATBT, sizeof(A)));

    // 0.75 * A * B + 0.25 * AB == AB
    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, B, 2, shape, AB, 2, shape, Y, 2, shape, 0.75, 0.25, 0, 0);
    EXPECT_FALSE(std::memcmp(Y, AB, sizeof(A)));

    // A * I .+ 4 == B
    ONNC_RUNTIME_gemm_float(nullptr, A, 2, shape, I, 2, shape, I, 0, shape, Y, 2, shape, 1, 4, 0, 0);
    EXPECT_FALSE(std::memcmp(Y, B, sizeof(A)));
}
