#ifndef ONNCRT_GENERIC_ASSIGN_H
#define ONNCRT_GENERIC_ASSIGN_H

#include "copy.h"
#include "size.h"
#include "strides.h"
/*!
 * \brief Tensor assignment
 *
 * This function performs `y .= x` where `x` is broadcastable to `y`.
 *
 * For example, if `y` is a 3x4 matrix and `x = [a b c d]`, resulting `y`
 * would be
 *
 *     [a  b  c  d;
 *      a  b  c  d;
 *      a  b  c  d]
 */
static void assign_(Scalar* restrict y, const Index* restrict yshape, Index yorder,
    const Scalar* restrict x, const Index* restrict xshape, Index xorder)
{
    Index diff = yorder - xorder;
    Index size = size_(yshape + diff, xorder);
    Index count = size_(yshape, diff);
    Index strides[xorder];
    Index index[xorder];

    strides_(strides, xshape, xorder);

    for (Index i = 0; i < xorder; ++i)
        index[i] = 0;

    for (Index i = 0; i < size; ++i) {
        y[i] = x[idot_(index, strides, xorder)];
        increment_(index, yshape + diff, xorder);
    }

    for (Index i = 1; i < count; ++i)
        copy_(y + i * size, y, size);
}

#endif
// vim: ft=c
