#ifndef ONNC_DRAGONITE_HPP
#define ONNC_DRAGONITE_HPP

#ifdef __GNUC__
#define restrict __restrict
#else
#define restrict
#endif

extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}

#undef restrict

#include <skypat/skypat.h>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <cstring>

namespace dragonite {

template<int Power>
struct LpNorm;

template<>
struct LpNorm<1>
{
    template<typename T>
    static T compute(const T* x, std::size_t n)
    {
        using std::abs;
        T accumulator = -0.0;

        for (std::size_t i = 0; i < n; ++i)
            accumulator += abs(x[i]);

        return accumulator;
    }
};

template<>
struct LpNorm<2>
{
    template<typename T>
    static T compute(const T* x, std::size_t n)
    {
        using std::sqrt;
        T accumulator = -0.0;

        for (std::size_t i = 0; i < n; ++i)
            accumulator += x[i] * x[i];

        return sqrt(accumulator);
    }
};

template<>
struct LpNorm<-1>
{
    template<typename T>
    static T compute(const T* x, std::size_t n)
    {
        using std::abs;
        T accumulator = 0;

        for (std::size_t i = 0; i < n; ++i) {
            T candidate = abs(x[i]);

            if (candidate > accumulator)
                accumulator = candidate;
        }
        return accumulator;
    }
};

template<int Power, typename T>
T lpnorm(const T* x, std::size_t n)
{
    return LpNorm<Power>::compute(x, n);
}

template<typename>
struct Traits;

template<>
struct Traits<float>
{
    typedef std::uint32_t Bitset;

    static constexpr float tolerance = 1e-5f;
};

template<typename T>
void verify(T* buffer, const T* answer, std::size_t size, T tolerance, const char* message)
{
    std::transform(buffer, buffer + size, answer, buffer, std::minus<T>());

    ASSERT_TRUE_MSG(lpnorm<1>(buffer, size) < tolerance * lpnorm<1>(answer, size), message);
    ASSERT_TRUE_MSG(lpnorm<2>(buffer, size) < tolerance * lpnorm<2>(answer, size), message);
    ASSERT_TRUE_MSG(lpnorm<-1>(buffer, size) < tolerance * lpnorm<-1>(answer, size), message);
}

template<typename T>
void verify(T* buffer, const T* answer, std::size_t size, const char* message)
{
    verify(buffer, answer, size, Traits<T>::tolerance, message);
}

template<typename T>
void verify(T* buffer, const T* answer, std::size_t size, T tolerance = Traits<T>::tolerance)
{
    std::transform(buffer, buffer + size, answer, buffer, std::minus<T>());

    ASSERT_TRUE(lpnorm<1>(buffer, size) < tolerance * lpnorm<1>(answer, size));
    ASSERT_TRUE(lpnorm<2>(buffer, size) < tolerance * lpnorm<2>(answer, size));
    ASSERT_TRUE(lpnorm<-1>(buffer, size) < tolerance * lpnorm<-1>(answer, size));
}

template<typename To, typename From>
To reinterpret(From from)
{
    static_assert(std::is_trivially_copyable<To>::value, "");
    static_assert(sizeof(To) <= sizeof(From), "");

    unsigned char to[sizeof(To)];

    return *static_cast<To*>(std::memcpy(to, &from, sizeof(To)));
}

template<typename T>
bool approx(T x, T y, typename Traits<T>::Bitset tolerance = 1)
{
    typedef typename Traits<T>::Bitset Bitset;

    static_assert(std::is_unsigned<Bitset>::value, "");

    Bitset a = reinterpret<Bitset>(x);
    Bitset b = reinterpret<Bitset>(y);

    return a - b + tolerance <= 2 * tolerance;
}

template<typename T>
bool approx(const T* x, const T* y, std::size_t size, typename Traits<T>::Bitset tolerance = 1)
{
    typedef typename Traits<T>::Bitset Bitset;

    static_assert(std::is_unsigned<Bitset>::value, "");

    for (std::size_t i = 0; i < size; ++i)
        if (!approx(x[i], y[i], tolerance))
            return false;

    return true;
}

} // namespace dragonite
#endif
