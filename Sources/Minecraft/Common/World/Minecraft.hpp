#pragma once

#include "GameSession.hpp"
#include "Minecraft/Common/World/Phys/Vec2.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class ClientInstance;
    class SoundEngine;
    class ResourcePackManager;
    class GameSession;
    class Level;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\Minecraft.cpp"
    class Minecraft
    {
    public:
        // FUN_0x124DD0
        Level *getLevel()
        {
            return mGameSession ? mGameSession->getLevel() : nullptr;
        }

    private:
        ClientInstance                        *mClient;    // +0x0
        SoundEngine                           *mSoundEngine;    // +0x4
        void                                  *mUnk1;    // +0x8
        void                                  *mUnk2;    // +0xC
        gstd::unique_ptr<ResourcePackManager>  mResourcePackManager;    // +0x10
        gstd::unique_ptr<gstd::type_unknown<>> mUnk3;    // +0x14
        void                                  *mUnk4;    // +0x18
        void                                  *mUnk5;    // +0x1C
        void                                  *mUnk6;    // +0x20
        void                                  *mUnk7;    // +0x24
        void                                  *mLoopbackPacketSender;    // +0x28
        void                                  *mServerKeys;    // +0x2C
        void                                  *mUnk8;    // +0x30
        gstd::string                           mUnk9;    // +0x34
        void                                  *mUnk10;    // +0x38
        u8                                     mUnk11;    // +0x3C

        // doubleの可能性があるけど、もしそうならpackしてる
        Vec2<float> mUnk12;    // +0x40
        Vec2<float> mUnk13;    // +0x48
        Vec2<float> mUnk14;    // +0x50

        gstd::unique_ptr<gstd::type_unknown<>> mUnk15;    // +0x58
        gstd::unique_ptr<GameSession>          mGameSession;    // +0x5C
        gstd::unique_ptr<gstd::type_unknown<>> mUnk16;    // +0x60
        gstd::unique_ptr<gstd::type_unknown<>> mUnk17;    // +0x64
        void                                  *mUnk18;    // +0x68
        void                                  *mUnk19;    // +0x6C
    };
}    // namespace MC3DSPluginFramework