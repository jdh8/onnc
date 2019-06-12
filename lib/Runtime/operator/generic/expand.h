#include "copy.h"

static Index _expand_dot(const Index* x, const Index* y, Index count)
{
    Index result = 0;

    for (Index i = 0; i < count; ++i)
        result += x[i] * y[i];

    return result;
}

static int _expand_increment_overflow(Index* restrict index, const Index* restrict shape, Index order)
{
    Index end = order - 1;

    if (order < 1)
        return 1;

    if (index[end] + 1 < shape[end]) {
        index[end]++;
        return 0;
    }

    index[end] = 0;
    return _expand_increment_overflow(index, shape, end);
}

static void _expand_assign(Scalar* restrict y, const Scalar* restrict x,
    const Index* restrict shape, const Index* restrict strides, Index order)
{
    Index index[order];

    for (Index i = 0; i < order; ++i)
        index[i] = 0;

    for (Index i = 0; ; ++i) {
        y[i] = x[_expand_dot(index, strides, order)];

        if (_expand_increment_overflow(index, shape, order))
            break;
    }
}

static Index _expand_size(const Index* shape, Index order)
{
    Index result = 1;

    for (Index i = 0; i < order; ++i)
        result *= shape[i];

    return result;
}

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

    _expand_assign(y, x, yshape + diff, strides, xorder);

    Index size = _expand_size(yshape + diff, xorder);
    Index count = _expand_size(yshape, diff);

    for (Index i = 1; i < count; ++i)
        _copy(y + i * size, y, size);
}

// vim: ft=c
