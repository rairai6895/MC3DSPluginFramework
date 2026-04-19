#pragma once

#include "Minecraft/gstd/gstd.hpp"
#include "ResourceLoader.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\resources\\ResourcePackManager.cpp"
    class ResourcePackManager : public ResourceLoader
    {
        USE_GAME_ALLOCATOR
    public:
        ResourcePackManager(gstd::string path) :
            // ResourceLoader(path.c_str())
            ResourceLoader(nullptr)
        {
            reinterpret_cast<ResourcePackManager *(*)(ResourcePackManager *, gstd::string)>(0x3D9EF0)(this, path);
        }

    private:
        char field[0x40];
    };
}    // namespace MC3DSPluginFramework