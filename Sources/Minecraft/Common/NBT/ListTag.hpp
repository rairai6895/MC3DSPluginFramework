#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class ListTag : public Tag
    {
        USE_GAME_ALLOCATOR
    public:
        using List = gstd::vector<gstd::unique_ptr<Tag>>;

        ListTag()
        {
            *(u32 *)this = 0x9CE454;
        }

        ListTag(gstd::vector<gstd::unique_ptr<Tag>> &&list) :
            mList(std::move(list))
        {
            *(u32 *)this = 0x9CE454;
        }

        List mList;
    };
}    // namespace MC3DSPluginFramework