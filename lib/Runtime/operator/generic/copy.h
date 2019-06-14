#ifndef ONNCRT_GENERIC_COPY_H
#define ONNCRT_GENERIC_COPY_H
/*!
 * \brief Vectorized copy
 *
 * This function copies `count` elements from `x` to `y`,
 * like `memcpy(y, x, count * sizeof(Scalar))`.
 */
static void copy_(Scalar* restrict y, const Scalar* restrict x, Index count)
{
    for (Index i = 0; i < count; ++i)
        y[i] = x[i];
}

#endif
// vim: ft=c
