#pragma once

#include "Minecraft/src-deps/Input/InputHandler.hpp"

namespace MC3DSPluginFramework
{
    class ClientInstance;

    class MoveInputHandler
    {
    public:
        virtual ~MoveInputHandler();

        void setJumping(bool set)
        {
            mJump = set;
        }

        bool isJumping()
        {
            return mJump;
        }

        void setSneaking(bool set)
        {
            mSneak = set;
        }

        bool isSneaking()
        {
            return mSneak;
        }

    private:
        float           m0x4;
        float           m0x8;
        float           m0xC;
        float           m0x10;
        float           m0x14;
        float           m0x18;
        float           m0x1C;
        float           m0x20;
        float           m0x24;
        float           m0x28;
        float           m0x2C;
        float           m0x30;
        float           m0x34;
        float           m0x38;
        u8              m0x3C;
        u8              m0x3D;
        u8              m0x3E;
        u8              m0x3F;
        u8              mFlyDownSlow;    // +0x40
        u8              mFlyUpSlow;    // +0x41
        u8              m0x42;
        u8              m0x43;
        u8              m0x44;
        u8              mAscend;    // +0x45
        u8              mDescend;    // +0x46
        InputHandler   *mInputHandler;    // +0x48
        u8              m0x4C;
        bool            mJump;    // +0x4D
        bool            mSneak;    // +0x4E
        u8              mSprint;    // +0x4F
        u8              mChangeFlightHeight;    // +0x50
        u8              mUp;    // +0x51
        u8              mDown;    // +0x52
        u8              mLeft;    // +0x53
        u8              mRight;    // +0x54
        u8              mUpLeft;    // +0x55
        u8              mUpRight;    // +0x56
        int             m0x58;
        float           m0x5C;
        float           m0x60;
        ClientInstance *mClient;    // +0x64
    };
}    // namespace MC3DSPluginFramework