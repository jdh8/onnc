static Index _size(const Index* shape, Index order)
{
    Index result = 1;

    for (Index i = 0; i < order; ++i)
        result *= shape[i];

    return result;
}

// vim: ft=c
