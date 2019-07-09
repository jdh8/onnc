#ifndef ONNC_COMPARE

#include "size.h"
#include "strides.h"

#define ONNC_COMPARE(BOOLEAN, SCALAR, bits, shape, order,                  \
    x, xshape, xorder, y, yshape, yorder, compare)                         \
do {                                                                       \
    typedef BOOLEAN Boolean;                                               \
    typedef SCALAR Scalar;                                                 \
    typedef ONNC_INDEX_TYPE Index;                                         \
                                                                           \
    Boolean* restrict _bits = bits;                                        \
    const Scalar* restrict _x = x;                                         \
    const Scalar* restrict _y = y;                                         \
    const Index* restrict _shape = shape;                                  \
    const Index* restrict _xshape = xshape;                                \
    const Index* restrict _yshape = yshape;                                \
    Index _xorder = xorder;                                                \
    Index _yorder = yorder;                                                \
    Index _order = order;                                                  \
                                                                           \
    Index _size = onnc_size(_shape, _order);                               \
    Index _index[_order];                                                  \
    Index _xstrides[_xorder];                                              \
    Index _ystrides[_yorder];                                              \
                                                                           \
    onnc_strides(_xstrides, _xshape, _xorder);                             \
    onnc_strides(_ystrides, _yshape, _yorder);                             \
                                                                           \
    for (Index _i = 0; _i < _order; ++_i)                                  \
       _index[_i] = 0;                                                     \
                                                                           \
    for (Index _i = 0; _i < _size; ++_i) {                                 \
        _bits[_i] = compare(                                               \
            _x[onnc_idot(_order - _xorder + _index, _xstrides, _xorder)],  \
            _y[onnc_idot(_order - _yorder + _index, _ystrides, _yorder)]); \
                                                                           \
        onnc_increment(_index, _shape, _order);                            \
    }                                                                      \
} while (0)

#endif
// vim: ft=c
