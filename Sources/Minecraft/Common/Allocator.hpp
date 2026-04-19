#pragma once

#include "Minecraft/gctr/gctr.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x1055CC内で初期化されている。FUN_0x1055CCは起動後すぐに呼ばれる

    class Allocator
    {
    public:
        Allocator() :
            mMutex()
        {
            mUnk1        = 0;
            mUnk2        = 0;
            mUnk3        = 0;
            mUnk4        = 0;
            mUnk5        = 0;
            mUnk6        = 0;
            mUnk7        = 0;
            *(u32 *)this = 0x9D91A0;
            reinterpret_cast<void (*)(Allocator *)>(0x1087C0)(this);
        }

        virtual ~Allocator();

    private:
        u32                 mUnk1;
        u32                 mUnk2;
        u32                 mUnk3;
        u32                 mUnk4;
        u32                 mUnk5;
        u32                 mUnk6;
        u32                 mUnk7;
        gctr::RecursiveLock mMutex;
    };
}    // namespace MC3DSPluginFramework