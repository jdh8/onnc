#ifndef ONNCRT_REAL_GEMM_H
#define ONNCRT_REAL_GEMM_H

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

/*!
 * \brief Matrix multiplication
 *
 * This function performs `y += opa(a) * opb(b)` where `a` and `b` are matrices.
 * If `op` is nonzero, its operand is viewed as transposed.
 */
static void _gemm(
    Scalar* restrict y, const Scalar* restrict a, const Scalar* restrict b,
    Scalar alpha, Index rows, Index cols, Index depth, int opa, int opb)
{
    (opb ? _gemmABT : _gemmAB)(y, a, b, alpha, rows, cols, depth, opa);
}

#endif
// vim: ft=c
