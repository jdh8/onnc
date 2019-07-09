#ifndef DRAGONITE_NORM_HPP
#define DRAGONITE_NORM_HPP

#include <numeric>
#include <functional>
#include <cstddef>
#include <cmath>

namespace dragonite {

inline double norm(const float* x, std::size_t size)
{
    return std::sqrt(std::inner_product(x, x + size, x, -0.0));
}

inline double norm(const float* x, const float* y, std::size_t size)
{
    return std::sqrt(std::inner_product(x, x + size, y, -0.0, std::plus<double>(), [](float a, float b) -> double
    {
        double diff = a - b;
        return diff * diff;
    }));
}

} // namespace dragonite

#endif

