#include "assign.h"
#include "copy.h"
#include "size.h"

static void _expand(
    Scalar* restrict y, const Index* restrict yshape, Index yorder,
    const Scalar* restrict x, const Index* restrict xshape, Index xorder)
{
    Index diff = yorder - xorder;
    Index strides[xorder];

    if (xorder > 0)
        strides[xorder - 1] = 1;

    for (Index i = xorder - 1; i > 0; --i)
        strides[i - 1] = xshape[i] * strides[i];

    _assign(y, x, yshape + diff, strides, xorder);

    Index size = _size(yshape + diff, xorder);
    Index count = _expand_size(yshape, diff);

    for (Index i = 1; i < count; ++i)
        _copy(y + i * size, y, size);
}

// vim: ft=c
