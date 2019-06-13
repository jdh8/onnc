static Index _idot(const Index* x, const Index* y, Index count)
{
    Index result = 0;

    for (Index i = 0; i < count; ++i)
        result += x[i] * y[i];

    return result;
}

static int _increment(Index* restrict index, const Index* restrict shape, Index order)
{
    Index end = order - 1;

    if (order < 1)
        return 1;

    if (++(index[end]) < shape[end])
        return 0;

    index[end] = 0;
    return _increment(index, shape, end);
}

static void _assign(Scalar* restrict y, const Scalar* restrict x,
    const Index* restrict shape, const Index* restrict strides, Index order)
{
    Index index[order];

    for (Index i = 0; i < order; ++i)
        index[i] = 0;

    for (Index i = 0; ; ++i) {
        Index offset = _idot(index, strides, order);
        y[i] = x[offset];

        if (_increment(index, shape, order))
            break;
    }
}

// vim: ft=c
