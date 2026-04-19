#pragma once

namespace MC3DSPluginFramework::glm
{
    constexpr inline bool isPowerOfTwo(int x)
    {
        return (x & x - 1) == 0;
    }

}    // namespace MC3DSPluginFramework::glm