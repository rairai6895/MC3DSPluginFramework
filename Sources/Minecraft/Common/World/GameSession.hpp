#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Level;
    class GameMode;
    class ServerNetworkHandler;
    class LegacyClientNetworkHandler;
    class ClientNetworkHandler;
    class LoopbackPacketSender;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\GameSession.cpp"
    class GameSession
    {
    public:
        Level *getLevel();

    private:
        void                                         *mUnk1;    // +0x0
        gstd::unique_ptr<Level>                       mLevel;    // +0x4
        gstd::unique_ptr<GameMode>                   *mGameMode;    // +0x8
        gstd::unique_ptr<ServerNetworkHandler>       *mServerNetworkHandler;    // +0xC
        gstd::unique_ptr<LegacyClientNetworkHandler> *mLegacyClientNetworkHandler;    // +0x10
        gstd::unique_ptr<ClientNetworkHandler>       *mClientNetworkHandler;    // +0x14
        LoopbackPacketSender                         *mLoopbackPacketSender;    // +0x18
    };
}    // namespace MC3DSPluginFramework