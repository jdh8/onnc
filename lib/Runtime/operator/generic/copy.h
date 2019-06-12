static void _copy(Scalar* restrict y, const Scalar* restrict x, Index count)
{
    for (Index i = 0; i < count; ++i)
        y[i] = x[i];
}
