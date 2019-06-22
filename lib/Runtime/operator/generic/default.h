#ifndef ONNC_RUNTIME_DEFAULT_H
#define ONNC_RUNTIME_DEFAULT_H

static void onnc_default(
    ONNC_INDEX_TYPE* restrict destination, ONNC_INDEX_TYPE needed,
    const ONNC_INDEX_TYPE* restrict source, ONNC_INDEX_TYPE provided,
    ONNC_INDEX_TYPE fill)
{
    typedef ONNC_INDEX_TYPE Index;
    
    if (provided > needed)
        provided = needed;

    for (Index i = 0; i < provided; ++i)
        destination[i] = source[i];

    for (Index i = provided; i < needed; ++i)
        destination[i] = fill;
}

#endif
// vim: ft=c
