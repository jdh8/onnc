#ifndef ONNCRT_STRIDES_H
#define ONNCRT_STRIDES_H
/*!
 * \brief Inner product of vectors of indices
 *
 * This function computes data offset from a multidimensional index.
 * See _strides() for details.
 */
static Index _idot(const Index* x, const Index* y, Index count)
{
    Index result = 0;

    for (Index i = 0; i < count; ++i)
        result += x[i] * y[i];

    return result;
}

/*!
 * \brief Increment 0-based multidimensional index in a tensor
 *
 * For example, in a 2x1x3 tensor, an index shall iterate through
 *
 *     { 0, 0, 0 }
 *     { 0, 0, 1 }
 *     { 0, 0, 2 }
 *     { 1, 0, 0 }
 *     { 1, 0, 1 }
 *     { 1, 0, 2 }
 */
static void _increment(Index* restrict index, const Index* restrict shape, Index order)
{
    Index end = order - 1;

    if (order > 0 && ++index[end] >= shape[end]) {
        index[end] = 0;
        _increment(index, shape, end);
    }
}

/*!
 * \brief Strides for each axis
 *
 * This function computes strides given shape of a tensor.
 *
 * For example, given a 3x1x3x3x7 tensor, its strides on each axis are
 *
 *     { 63, 0, 21, 7, 1 }
 *
 * In this case, we can access the element at `[a, b, c, d, e]` with
 *
 *     pointer[63*a + 21*c + 7*d + e]
 *
 * The stride on each 1-element-long axis is thought to be 0 to ease arbitrary
 * broadcasting.  For example, the example array of strides still works if the
 * tensor is read as a 3xnx3x3x7 tensor.
 */
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
