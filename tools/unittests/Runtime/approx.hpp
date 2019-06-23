#ifndef ONNCRT_TEST_APPROX_HPP
#define ONNCRT_TEST_APPROX_HPP

#include <type_traits>
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace onnc {
namespace test {

template<typename To, typename From>
To bitcast(From from)
{
    static_assert(std::is_trivially_copyable<To>::value);
    static_assert(std::is_trivially_copyable<From>::value);

    To to;
    std::memcpy(&to, &from, sizeof(To));
    return to;
}

// Test if |x - y| <= tolerance
template<typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type
approx(T x, T y, T tolerance)
{
    return x - y + tolerance <= 2 * tolerance;
}

// Test if |x - y| <= tolerance ulp
inline bool approx(float x, float y, std::uint32_t tolerance)
{
    return approx(bitcast<std::uint32_t>(x), bitcast<std::uint32_t>(y), tolerance);
}

template<typename T, typename Integer>
bool approx(const T* x, const T* y, std::size_t count, Integer tolerance)
{
    for (std::size_t i = 0; i < count; ++i)
        if (!approx(x[i], y[i], tolerance))
            return false;
    return true;
}

} // namespace test
} // namespace onnc
#endif
