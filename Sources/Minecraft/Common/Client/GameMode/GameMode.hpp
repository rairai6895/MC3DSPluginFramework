#pragma once

#include "Minecraft/Common/World/Level/BlockPos.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Level;

    class GameMode
    {
    public:
        virtual ~GameMode();

        // FUN_0x1C99C0
        static gstd::string toString(GameModes mode)
        {
            switch (mode)
            {
                default: return "Survival";
                case GameModes::Survival: return "Survival";
                case GameModes::Creative: return "Creative";
                case GameModes::Adventure: return "Adventure";
            }
        }

    private:
        //  恐らくCreativeModeにはメンバ変数やオーバーライドがないから最適化で純粋なGameModeオブジェクトとして作成されている
        //  0x9D04A4

        void    *mLoopbackPacketSender;    // +0x4
        Level   *mLevel;    // +0x8
        BlockPos mCurrentDestroyBlockPos;    // +0xC
        float    mPrevDestroyProgress;    // +0x18
        float    mDestroyProgress;    // +0x1C
        double   m0x20;
        u8       m0x28;
        double   m0x30;
        double   m0x38;
        double   m0x40;
        double   m0x48;
        double   m0x50;
        double   m0x58;
    };
}    // namespace MC3DSPluginFramework