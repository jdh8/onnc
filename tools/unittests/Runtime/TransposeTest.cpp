#define restrict __restrict__
extern "C" {
#include <onnc/Runtime/operator/transpose.h>
}
#undef restrict

#include <skypat/skypat.h>
#include <algorithm>
#include <functional>
#include <numeric>
#include <array>
#include <valarray>
#include <cstring>

template<std::size_t order>
static std::array<std::int32_t, order> compute_strides(const std::array<std::int32_t, order>& shape)
{
    std::array<std::int32_t, order> result;

    if (order > 0)
        result[order - 1] = 1;

    for (std::size_t i = order - 1; i > 0; --i)
        result[i - 1] = shape[i] * result[i];

    for (std::size_t i = 0; i < order; ++i)
        result[i] *= shape[i] > 1;

    return result;
}

template<typename T>
static std::valarray<T> range(std::size_t end)
{
    std::valarray<T> result(end);

    for (std::size_t i = 0; i < end; ++i)
        result[i] = i;

    return result;
}

template<typename T, typename Container>
static std::valarray<T> make_valarray(const Container& x)
{
    std::valarray<T> result(x.size());
    std::copy(std::begin(x), std::end(x), std::begin(result));
    return result;
}

template<typename T>
static bool equal(const std::valarray<T>& x, const std::valarray<T>& y)
{
    return x.size() == y.size() && !std::memcmp(&x[0], &y[0], x.size() * sizeof(T));
}

/* FIXME We pass `permutation` by value because `ONNC_RUNTIME_transpose_float`
 * takes (non-const) `int32_t*` as permutation list.  Discuss if changing to
 * `const int32_t*` is possible.
 */
static void test_permutedims(
    const std::valarray<float>& tensor,
    std::valarray<std::int32_t> permutation,
    const std::valarray<std::int32_t>& shape,
    const std::valarray<std::size_t>& strides)
{
    using std::size_t;
    using std::int32_t;

    const std::valarray<size_t> permute = make_valarray<size_t>(permutation);
    const std::valarray<int32_t> permuted_shape = shape[permute];
    const std::valarray<size_t> permuted_strides = strides[permute];
    const std::gslice transpose = { 0, make_valarray<size_t>(permuted_shape), permuted_strides };
    const std::valarray<float> reference = tensor[transpose];

    std::valarray<float> candidate(tensor.size());

    ONNC_RUNTIME_transpose_float(nullptr,
        &tensor[0], shape.size(), &shape[0],
        &candidate[0], permuted_shape.size(), &permuted_shape[0],
        &permutation[0], permutation.size()
    );

    EXPECT_TRUE(equal(reference, candidate));
}

template<typename... Args>
static void test(Args... args)
{
    using std::size_t;
    using std::int32_t;

    const size_t order = sizeof...(Args);
    std::array<int32_t, order> shape = { static_cast<int32_t>(args)... };
    std::array<int32_t, order> strides = compute_strides(shape);
    size_t size = std::accumulate(shape.begin(), shape.end(), static_cast<size_t>(1), std::multiplies<size_t>());

    const std::gslice identity = { 0, make_valarray<size_t>(shape), make_valarray<size_t>(strides) };
    const std::valarray<float> tensor = range<float>(size);
    const std::valarray<float> candidate = tensor[identity];

    EXPECT_TRUE(equal(tensor, candidate));

    std::valarray<int32_t> permutation = range<int32_t>(order);

    while (std::next_permutation(std::begin(permutation), std::end(permutation)))
        test_permutedims(tensor, permutation, make_valarray<int32_t>(shape), make_valarray<size_t>(strides));
}

SKYPAT_F(Operator_Transpose, non_broadcast)
{
    test(4);
    test(2, 5);
    test(3, 1);
    test(1, 2, 3);
    test(4, 2, 3);
    test(2, 3, 1, 2);
    test(3, 1, 3, 3, 7);
}
