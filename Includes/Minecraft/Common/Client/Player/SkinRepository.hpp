#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\player\\SkinRepository.cpp"
    class SkinRepository
    {
    public:
        void *getSkin(const gstd::string &skinName)
        {
            return reinterpret_cast<void *(*)(SkinRepository *, const gstd::string &)>(0x6D0458)(this, skinName);
        }

    private:
    };
}    // namespace MC3DSPluginFramework