#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    // 追加してワールド入りなおすとアイテム消える
    class EndTag : public Tag
    {
    public:
        EndTag() { *(u32 *)this = 0x9CB6D0; }

        void *operator new(size_t s) { return gstd::malloc(s); }
    };
}    // namespace MC3DSPluginFramework