#ifndef ONNCRT_GENERIC_BINARY_H
#define ONNCRT_GENERIC_BINARY_H

#include "size.h"
#include "strides.h"
/*!
 * \brief Inplace binary operator
 *
 * This function performs `y = f.(y, x)` where `x` is broadcastable to `y`.
 * For example, if `f = +`, then `y .+= x` is performed.
 */
static void binary_(Scalar* restrict y, const Index* restrict yshape, Index yorder,
    const Scalar* restrict x, const Index* restrict xshape, Index xorder, Scalar f(Scalar, Scalar))
{
    Index diff = yorder - xorder;
    Index size = size_(yshape, yorder);
    Index index[yorder];
    Index strides[xorder];

    strides_(strides, xshape, xorder);

    for (Index i = 0; i < yorder; ++i)
        index[i] = 0;

    for (Index i = 0; i < size; ++i) {
        y[i] = f(y[i], x[idot_(index + diff, strides, xorder)]);
        increment_(index, yshape, yorder);
    }
}

#endif
// vim: ft=c
