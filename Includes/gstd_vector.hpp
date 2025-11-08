#ifndef GSTD_VECTOR_HPP
#define GSTD_VECTOR_HPP

#include "gstd_alloc.hpp"
#include <vector>

namespace MC3DSPluginFramework {
/**
 *  Game standard Functions.
 *  Do not use while the game thread is stopped.
 */
namespace gstd {

template <typename T>
class allocator {
  public:
    using value_type = T;

    T *allocate(std::size_t n) {
        return (T *)(gstd::malloc(sizeof(T) * n));
    }

    void deallocate(T *ptr, std::size_t n) {
        gstd::free((void *)ptr);
    }

    bool operator==(const allocator &) const { return true; }
    bool operator!=(const allocator &) const { return false; }
};

template <typename T>
using vector = std::vector<T, gstd::allocator<T>>;

}    // namespace gstd
}    // namespace MC3DSPluginFramework

#endif