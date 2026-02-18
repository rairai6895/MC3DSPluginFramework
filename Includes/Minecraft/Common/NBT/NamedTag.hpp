#pragma once

#include "Minecraft/Common/NBT/Tag.hpp"

namespace MC3DSPluginFramework
{
    class NamedTag : public Tag
    {
    public:
        NamedTag(gstd::string parent) :
            mParent(parent)
        {
            *(u32 *)this = 0x9D1250;
        }

    public:
        ~NamedTag() override = default;

        void setTag(gstd::string tag) override
        {
            mParent = tag;
        }

        gstd::string getTag() const override
        {
            return mParent;
        }

    private:
        gstd::string mParent;
    };
}    // namespace MC3DSPluginFramework