#ifndef ONNC_DEFAULT_FILL
/*!
 * \brief Filling default arguments
 *
 * The destination points to a `SCALAR[count]`.  It is copied from
 * non-null source or filled with a constant value.
 */
#define ONNC_DEFAULT_FILL(SCALAR, destination, source, count, fill) do { \
    typedef SCALAR Scalar;                                               \
    typedef ONNC_INDEX_TYPE Index;                                       \
                                                                         \
    Scalar* restrict _destination = destination;                         \
    const Scalar* restrict _source = source;                             \
    Scalar _fill = fill;                                                 \
    Index _count = count;                                                \
                                                                         \
    for (Index _i = 0; _i < _count; ++_i)                                \
        _destination[_i] = _source ? _source[_i] : _fill;                \
} while (0)

#endif
// vim: ft=c
