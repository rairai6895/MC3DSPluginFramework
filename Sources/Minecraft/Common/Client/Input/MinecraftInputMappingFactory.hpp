#pragma once

#include "GamePadLayout.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\input\\MinecraftInputMappingFactory.cpp"
    class MinecraftInputMappingFactory
    {
        USE_GAME_ALLOCATOR
    public:
        MinecraftInputMappingFactory()
        {
            reinterpret_cast<MinecraftInputMappingFactory *(*)(MinecraftInputMappingFactory *)>(0x4A5AE4)(this);
        }

    public:
        virtual ~MinecraftInputMappingFactory();

    private:
        // 0x9C5A60

        gstd::map<u32, u32> mUnk1;
        gstd::map<u32, u32> mUnk2;
        void               *mUnk3;
        void               *mUnk4;
        void               *mUnk5;
        GamePadLayout       mGamePadLayout;
    };
}    // namespace MC3DSPluginFramework