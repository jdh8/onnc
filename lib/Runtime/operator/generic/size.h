#ifndef ONNCRT_SIZE_H
#define ONNCRT_SIZE_H
/*!
 * \brief Count elements in a tensor
 *
 * This function returns count of elements given shape of a tensor.
 */
static Index _size(const Index* shape, Index order)
{
    Index result = 1;

    for (Index i = 0; i < order; ++i)
        result *= shape[i];

    return result;
}

#endif
// vim: ft=c
