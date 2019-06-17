#ifndef ONNCRT_GENERIC_TRANSPOSE_H
#define ONNCRT_GENERIC_TRANSPOSE_H

#include "size.h"
#include "strides.h"

/*!
 * \brief Permutation of index vector
 *
 * The permutation specifier is the same as described by ONNX `Transpose`
 * operator, which is an array of indices.  For example, when
 * `permutation = { 1, 0, 2 }` and `index = { a, b, c }`, this function writes
 * the permuted index `{ b, a, c }` to `result`.
 */
static void permute_(Index* restrict result, const Index* restrict permutation, const Index* restrict index, Index order)
{
    for (Index i = 0; i < order; ++i)
        result[i] = index[permutation[i]];
}

/*!
 * \brief Tensor transpose
 *
 * This is generalization of matrix transpose to multidimensional space.
 * As there is more than one non-trivial transpose in 3+ ordered tensors,
 * transpose is described as permutation of indices.  See permute_() for
 * details of index permutation.
 */
static void transpose_(Scalar* restrict y, const Scalar* restrict x,
    const Index* restrict permutation, const Index* restrict shape, Index order)
{
    Index size = size_(shape, order);
    Index index[order], permuted[order], strides[order];

    for (Index i = 0; i < order; ++i)
        index[i] = 0;

    strides_(permuted, shape, order);
    permute_(strides, permutation, permuted, order);
    permute_(permuted, permutation, shape, order);

    for (Index i = 0; i < size; ++i) {
        y[i] = x[idot_(index, strides, order)];
        increment_(index, permuted, order);
    }
}

#endif
// vim: ft=c
