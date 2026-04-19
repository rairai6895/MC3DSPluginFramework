#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    // 追加してワールド入りなおすとアイテム消える
    class EndTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        EndTag() { *(u32 *)this = 0x9CB6D0; }
    };
}    // namespace MC3DSPluginFramework