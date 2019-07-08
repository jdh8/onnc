#ifndef ONNC_RELATIVE_ERROR_HPP
#define ONNC_RELATIVE_ERROR_HPP

#include <functional>
#include <numeric>
#include <cstddef>
#include <cmath>
#include <cassert>

static double relative_error(const float* estimate, const float* answer, std::size_t size)
{
    assert(std::any_of(answer, answer + size, [](float x){ return !!x; }));

    const double ess = std::inner_product(answer, answer + size, answer, 0.0);

    const double rss = std::inner_product(answer, answer + size, estimate, -0.0, std::plus<double>(),
        [](float x, float y) -> double
        {
            const double difference = x - y;
            return difference * difference;
        });

    return std::sqrt(rss / ess);
}

#endif
