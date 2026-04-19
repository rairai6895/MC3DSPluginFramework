#pragma once

#include "Minecraft/Helper/GameEnums.hpp"

namespace MC3DSPluginFramework
{
    namespace GameController
    {

        inline const gKey &convertKey(u32 hidkey)
        {
            return reinterpret_cast<gKey &(*)(u32, u32 *)>(0x118B88)(0x0FFFFAE4, &hidkey);
        }

        inline void press(gKey key)
        {
            reinterpret_cast<void (*)(u32, gKey, bool)>(0x1112FC)(0, key, true);
        }

        inline void release(gKey key)
        {
            reinterpret_cast<void (*)(u32, gKey, bool)>(0x1112FC)(0, key, false);
        }

    }    // namespace GameController
}    // namespace MC3DSPluginFramework