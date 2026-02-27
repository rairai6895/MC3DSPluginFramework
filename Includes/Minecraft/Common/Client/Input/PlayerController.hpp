#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class ClientInstance;
    class InputHandler;
    class MinecraftInputHandler;
    class MinecraftInputMappingFactory;

    class PlayerController
    {
    public:
        void *operator new(size_t s)
        {
            return gstd::malloc(s);
        }

        void operator delete(void *m)
        {
            gstd::free(m);
        }

    public:
        void changeState(int i);

    public:
        virtual ~PlayerController() = default;

    public:
        // 0x9C0B64

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
        gstd::unique_ptr<InputHandler> mInputHandler;
        gstd::unique_ptr<void *> mUnk2;
        gstd::unique_ptr<MinecraftInputHandler> mMinecraftInputHandler;
        gstd::unique_ptr<MinecraftInputMappingFactory> mMinecraftInputMappingFactory;
        bool mFlying;
        bool mUnk6;
        bool mSneaking;
        bool mCanFly;
        bool mTouchingBottomScreen;
        bool mUnk10;
        bool mUnk11;
        bool mUnk12;
        void *mUnk13;
    };
}    // namespace MC3DSPluginFramework