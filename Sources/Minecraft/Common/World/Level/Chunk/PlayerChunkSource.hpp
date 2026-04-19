#pragma once

#include "UnknownChunkSource.hpp"

namespace MC3DSPluginFramework
{
    class Player;

    class PlayerChunkSource : public UnknownChunkSource
    {
        USE_GAME_ALLOCATOR
    public:
        // FUN_0x374178
        void setRadius(int newRadius) {}

    public:
        ~PlayerChunkSource() override;

    private:
        // 0x9B8008

        Player     *mPlayer;    // +0x98
        int         mUnk23;    // +0x9C
        u8          mUnk24;    // +0xA0
        Vec3<float> mUnk25;    // +0xA4
    };
}    // namespace MC3DSPluginFramework