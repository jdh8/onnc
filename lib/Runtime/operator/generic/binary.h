#ifndef ONNC_OPERATOR_GENERIC_BINARY
#define ONNC_OPERATOR_GENERIC_BINARY

#include "size.h"
#include "strides.h"

static Index _imax(Index a, Index b)
{
    return a < b ? b : a;
}

static void _binary_sorted(Scalar* restrict y, Scalar f(Scalar, Scalar),
    const Scalar* restrict a, const Index* restrict ashape, Index order,
    const Scalar* restrict b, const Index* restrict bshape, Index lesser)
{
    Index diff = order - lesser;
    Index index[order];
    Index shape[order];
    Index astrides[order];
    Index bstrides[order];

    for (Index i = 0; i < order; ++i)
        index[i] = 0;

    for (Index i = 0; i < diff; ++i) {
        bstrides[i] = 0;
        shape[i] = ashape[i];
    }

    for (Index i = diff; i < order; ++i)
        shape[i] = _imax(ashape[i], bshape[i - diff]);

    _strides(bstrides + diff, bshape, lesser);
    _strides(astrides, ashape, order);

    Index size = _size(shape, order);

    for (Index i = 0; i < size; ++i) {
        y[i] = f(a[_idot(index, astrides, order)], b[_idot(index, bstrides, order)]);
        _increment(index, shape, order);
    }
}

static void _binary(Scalar* restrict y, Scalar f(Scalar, Scalar),
    const Scalar* restrict a, const Index* restrict ashape, Index aorder,
    const Scalar* restrict b, const Index* restrict bshape, Index border)
{
    if (aorder < border)
        _binary_sorted(y, f, b, bshape, border, a, ashape, aorder);
    else
        _binary_sorted(y, f, a, ashape, aorder, b, bshape, border);
}

#endif
// vim: ft=c
