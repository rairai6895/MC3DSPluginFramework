#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"

namespace MC3DSPluginFramework
{
    class ClientInstance;

    class PlayerController
    {
    public:
        u32 mVtable;

        /**
         *  "gamePlayNormal"
         *  "gamePlayFlying"
         *  "gamePlayBoating"
         *  "gamePlayMinecart"
         *  "gamePlayRiding"
         *  "screenBed"
         */
        gstd::string mState;
        gstd::string mScreenGazeController;    // "screenGazeController"
        ClientInstance *mClientInstance;
        void *mUnk1;
        void *mUnk2;
        void *mUnk3;
        void *mUnk4;
        bool mFlying;
        bool mUnk6;
        bool mSneaking;
        bool mCanFly;
        bool mTouchingBottomScreen;
        bool mUnk10;
        bool mUnk11;
        bool mUnk12;
        void *mIUnk13;
    };
}    // namespace MC3DSPluginFramework