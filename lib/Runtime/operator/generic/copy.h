#ifndef ONNC_OPERATOR_GENERIC_COPY
#define ONNC_OPERATOR_GENERIC_COPY

static void _copy(Scalar* restrict y, const Scalar* restrict x, Index count)
{
    for (Index i = 0; i < count; ++i)
        y[i] = x[i];
}

#endif
// vim: ft=c
