#ifndef ONNCRT_BINARY_H
#define ONNCRT_BINARY_H

#include "size.h"
#include "strides.h"
/*!
 * \brief Inplace binary operator
 *
 * This function performs `y = f.(y, x)` where `x` is broadcastable to `y`.
 * For example, if `f = +`, then `y .+= x` is performed.
 */
static void _binary(Scalar* restrict y, const Index* restrict yshape, Index yorder,
    const Scalar* restrict x, const Index* restrict xshape, Index xorder, Scalar f(Scalar, Scalar))
{
    Index diff = yorder - xorder;
    Index size = _size(yshape, yorder);
    Index index[yorder];
    Index strides[xorder];

    _strides(strides, xshape, xorder);

    for (Index i = 0; i < yorder; ++i)
        index[i] = 0;

    for (Index i = 0; i < size; ++i) {
        y[i] = f(y[i], x[_idot(index + diff, strides, xorder)]);
        _increment(index, yshape, yorder);
    }
}

#endif
// vim: ft=c
