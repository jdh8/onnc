#ifndef ONNC_OPERATOR_GENERIC_BROADCAST
#define ONNC_OPERATOR_GENERIC_BROADCAST

#include "copy.h"
#include "size.h"
#include "strides.h"

static void _broadcast(
    Scalar* restrict y, const Index* restrict yshape, Index yorder,
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
