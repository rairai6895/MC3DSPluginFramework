#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class ResourcePackRepository
    {
        USE_GAME_ALLOCATOR
    public:
        ResourcePackRepository()
        {
            reinterpret_cast<ResourcePackRepository *(*)(ResourcePackRepository *)>(0x451C88)(this);
        }

        ~ResourcePackRepository()
        {
            reinterpret_cast<void (*)(ResourcePackRepository *)>(0x452128)(this);
        }

    private:
        char field[0x48];
    };

}    // namespace MC3DSPluginFramework