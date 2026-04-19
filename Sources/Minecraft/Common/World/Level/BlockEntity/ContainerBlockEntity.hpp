#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // 仮
    class ContainerBlockEntity
    {
        USE_GAME_ALLOCATOR
    public:
        virtual ~ContainerBlockEntity();

    private:
        // チェスト 0
        // かまど 2
        // 醸造台 4
        // ディスペンサー 6
        // ドロッパー 7
        // ホッパー 8
        // 大釜 9
        // ビーコン 0xD
        u8                  mUnk11;    // コンテナタイプ
        gstd::map<u32, u32> mUnk12;
        gstd::map<u32, u32> mUnk13;
        gstd::string        mUnk14;
        bool                mUnk15;
    };
}    // namespace MC3DSPluginFramework