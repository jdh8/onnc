static void _gemmABT(
    Scalar* restrict y, const Scalar* restrict a, const Scalar* restrict b,
    Scalar alpha, Index rows, Index cols, Index depth, int op)
{
    Index istride = op ? 1 : depth;
    Index kstride = op ? rows : 1;

    for (Index i = 0; i < rows; ++i)
        for (Index j = 0; j < cols; ++j)
            for (Index k = 0; k < depth; ++k)
                y[i * cols + j] += alpha * a[i * istride + k * kstride] * b[j * depth + k];
}

static void _gemmAB(
    Scalar* restrict y, const Scalar* restrict a, const Scalar* restrict b,
    Scalar alpha, Index rows, Index cols, Index depth, int op)
{
    Index istride = op ? 1 : depth;
    Index kstride = op ? rows : 1;

    for (Index i = 0; i < rows; ++i)
        for (Index k = 0; k < depth; ++k)
            for (Index j = 0; j < cols; ++j)
                y[i * cols + j] += alpha * a[i * istride + k * kstride] * b[k * cols + j];
}

static void _gemm(
    Scalar* restrict y, const Scalar* restrict a, const Scalar* restrict b,
    Scalar alpha, Index rows, Index cols, Index depth, int opa, int opb)
{
    (opb ? _gemmABT : _gemmAB)(y, a, b, alpha, rows, cols, depth, opa);
}

// TODO: Consider conjugation when we have to support complex scalars
// vim: ft=c
