#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class ListTag : public Tag
    {
    public:
        using List = gstd::vector<gstd::unique_ptr<Tag>>;

        ListTag(gstd::vector<gstd::unique_ptr<Tag>> &&list) :
            mList(std::move(list))
        {
            *(u32 *)this = 0x9CE454;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        List mList;
    };
}    // namespace MC3DSPluginFramework