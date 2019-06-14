#ifndef ONNCRT_ASSIGN_H
#define ONNCRT_ASSIGN_H

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
static void _assign(Scalar* restrict y, const Index* restrict yshape, Index yorder,
    const Scalar* restrict x, const Index* restrict xshape, Index xorder)
{
    Index diff = yorder - xorder;
    Index size = _size(yshape + diff, xorder);
    Index count = _size(yshape, diff);
    Index strides[xorder];
    Index index[xorder];

    _strides(strides, xshape, xorder);

    for (Index i = 0; i < xorder; ++i)
        index[i] = 0;

    for (Index i = 0; i < size; ++i) {
        y[i] = x[_idot(index, strides, xorder)];
        _increment(index, yshape + diff, xorder);
    }

    for (Index i = 1; i < count; ++i)
        _copy(y + i * size, y, size);
}

#endif
// vim: ft=c
