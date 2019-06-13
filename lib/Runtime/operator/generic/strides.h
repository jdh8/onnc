#ifndef ONNC_OPERATOR_GENERIC_STRIDES
#define ONNC_OPERATOR_GENERIC_STRIDES

static Index _idot(const Index* x, const Index* y, Index count)
{
    Index result = 0;

    for (Index i = 0; i < count; ++i)
        result += x[i] * y[i];

    return result;
}

static void _increment(Index* restrict index, const Index* restrict shape, Index order)
{
    Index end = order - 1;

    if (order > 0 && ++index[end] >= shape[end]) {
        index[end] = 0;
        _increment(index, shape, end);
    }
}

static void _strides(Index* restrict result, const Index* restrict shape, Index order)
{
    if (order > 0)
        result[order - 1] = 1;

    for (Index i = order - 1; i > 0; --i)
        result[i - 1] = shape[i] * result[i];

    for (Index i = 0; i < order; ++i)
        result[i] *= shape[i] > 1;
}

#endif
// vim: ft=c
