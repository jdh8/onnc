#define restrict __restrict__
extern "C"{
    #include <onnc/Runtime/operator/add.h>
}
#undef restrict

#include <skypat/skypat.h>
#include <random>
#include <cstring>

SKYPAT_F(Operator_Add, matrix)
{
    const int rows = 56;
    const int cols = 38;

    const int ashape[] = { rows, 1 };
    const int bshape[] = { 1, cols };
    const int cshape[] = { rows, cols };

    float a[rows], b[cols], c[rows * cols];
    std::mt19937 rng;

    for (int i = 0; i < rows; ++i)
        a[i] = rng();

    for (int j = 0; j < cols; ++j)
        b[j] = rng();

    ONNC_RUNTIME_add_float(nullptr, a, 2, ashape, b, 2, bshape, c, 2, cshape);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            EXPECT_EQ(a[i] + b[j], c[i * cols + j]);

    ONNC_RUNTIME_add_float(nullptr, a, 2, ashape, b, 1, &cols, c, 2, cshape);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            EXPECT_EQ(a[i] + b[j], c[i * cols + j]);
}
