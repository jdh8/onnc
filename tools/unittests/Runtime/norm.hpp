#ifndef ONNCRT_TEST_NORM_HPP
#define ONNCRT_TEST_NORM_HPP

#include <cstddef>
#include <cmath>

namespace onnc {
namespace test {

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

    static float compute(const float* x, std::size_t n)
    {
        double accumulator = -0.0;

        for (std::size_t i = 0; i < n; ++i)
            accumulator += x[i] * x[i];

        return std::sqrt(accumulator);
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

} // namespace test
} // namespace onnc
#endif

