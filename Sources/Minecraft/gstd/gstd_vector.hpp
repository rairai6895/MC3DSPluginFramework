#pragma once

#include "gstd_allocator.hpp"
#include <vector>

namespace MC3DSPluginFramework::gstd
{
    template <typename T>
    using vector = ::std::vector<T, gstd::allocator<T>>;

}    // namespace MC3DSPluginFramework::gstd