#ifndef ONNC_OPERATOR_GENERIC_SIZE
#define ONNC_OPERATOR_GENERIC_SIZE

static Index _size(const Index* shape, Index order)
{
    Index result = 1;

    for (Index i = 0; i < order; ++i)
        result *= shape[i];

    return result;
}

#endif
// vim: ft=c
