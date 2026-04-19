#pragma once

#include "Minecraft/gstd/gstd.hpp"
#include "Minecraft/src-deps/Input/InputHandler.hpp"
#include "MinecraftInputHandler.hpp"
#include "MinecraftInputMappingFactory.hpp"
#include "MoveInputHandler.hpp"

namespace MC3DSPluginFramework
{
    class ClientInstance;

    class ClientInputHandler
    {
        USE_GAME_ALLOCATOR
    public:
        ClientInputHandler(ClientInstance *client);

        void updateInputMode(int i);
        void setJumping(bool set);
        bool isJumping();
        void setSneaking(bool set);
        bool isSneaking();

        short FUN_0012d628(gstd::string str)
        {
            return reinterpret_cast<short (*)(ClientInputHandler *, gstd::string)>(0x12D628)(this, str);
        }

    public:
        virtual ~ClientInputHandler() = default;

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
        gstd::string mInputMode;    // +0x4

        /**
         *  "screenGazeController"
         *  "screen"
         *  "screenVRMouse"
         */
        gstd::string mUIInputMode;    // +0x8

        ClientInstance                                *mClientInstance;    // +0xC
        gstd::unique_ptr<InputHandler>                 mInputHandler;    // +0x10
        gstd::unique_ptr<MoveInputHandler>             mMoveInputHandler;    // +0x14
        gstd::unique_ptr<MinecraftInputHandler>        mMinecraftInputHandler;    // +0x18
        gstd::unique_ptr<MinecraftInputMappingFactory> mMinecraftInputMappingFactory;    // +0x1C
        bool                                           mFlying;    // +0x20
        bool                                           m0x21;    // +0x21
        bool                                           mSneaking;    // +0x22
        bool                                           mCanFly;    // +0x23
        bool                                           mTouchingBottomScreen;    // +0x24
        bool                                           m0x25;    // +0x25
        bool                                           m0x26;    // +0x26
        bool                                           m0x27;    // +0x27
        void                                          *m0x28;    // +0x28
    };
}    // namespace MC3DSPluginFramework