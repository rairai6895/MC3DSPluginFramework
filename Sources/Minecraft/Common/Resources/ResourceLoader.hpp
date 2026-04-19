#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class ResourceLoader
    {
    public:
        ResourceLoader(const char *path);
        virtual ~ResourceLoader();

        virtual void        Unknown1() = delete;    // +0x8
        virtual const char *getPath();
        virtual void        Unknown2() = 0;    // +0x10
        virtual void        Unknown3() = 0;    // +0x14
        virtual void        Unknown4() = 0;    // +0x18
        virtual void        Unknown5() = 0;    // +0x1C
        virtual void        Unknown6() = 0;    // +0x20

    private:
        // 0x9ACB3C

        char *mPath;    // "rom:/images/", "rom:/"
    };
}    // namespace MC3DSPluginFramework