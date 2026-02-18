#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/Common/Client/Game/MinecraftGame.hpp"
#include "Minecraft/Common/Util/BoxedPtr.hpp"
#include "Minecraft/gctr/gctr.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftGame;
    class ClientInstance;

    class BaseScreen
    {
    public:
        virtual ~BaseScreen();

        gstd::string getName(void)
        {
            return reinterpret_cast<gstd::string (*)(BaseScreen *)>(*(u32 *)(*(u32 *)this + 0xF4))(this);
        }

    private:
        MinecraftGame *mMinecraftGame;
        u32 mVtable1;
        u32 mVtable2;
        u32 mScreenSize_X;
        u32 mScreenSize_Y;
        ClientInstance *mClientInstance;
        gstd::vector<Util::BoxedPtr::Shared<u32>> mUnk1;
        u32 mUnk2;
        u32 mUnk3;
        u32 mUnk4;
        u32 mUnk5;
        u32 mUnk6;
        u32 mUnk7;
        u32 mUnk8;
        u32 mUnk9;
        u32 mUnk10;
        u32 mUnk11;
        u32 mUnk12;
        u32 mUnk13;

        u32 mUnk14;    // 0xFFFFFFFF
        u32 mUnk15;    // 0xFFFFFFFF
        void *mUnk16;
        void *mUnk17;    // Fonts?
        u32 mUnk18;
        u32 mUnk19;
        u32 mUnk20;
        gstd::map<u32, u32> mUnk21;
        gctr::RecursiveLock mMutex;
    };

}    // namespace MC3DSPluginFramework