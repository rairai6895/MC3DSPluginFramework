#pragma once

#include "gstd_alloc.hpp"
#include <vector>

namespace MC3DSPluginFramework::gstd
{
    template <typename T>
    class allocator
    {
    public:
        using value_type = T;

        T *allocate(size_t n) { return (T *)(gstd::malloc(sizeof(T) * n)); }
        void deallocate(T *ptr, size_t n) { gstd::free(ptr); }
        bool operator==(const allocator &) const { return true; }
        bool operator!=(const allocator &) const { return false; }
    };

    template <typename T>
    using vector = std::vector<T, gstd::allocator<T>>;

}    // namespace MC3DSPluginFramework::gstd