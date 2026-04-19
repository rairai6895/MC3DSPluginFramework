#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class ResourcePackManager;
    class ResourceLoader;

    class ResourceLocation
    {
    public:
        // FUN_0x33C630
        void init(const char *texturePath, u8 loaderId)
        {
            mLoaderId       = loaderId;
            mResourceLoader = nullptr;
            mUnk3           = 0;

            FUN_006e2de0(texturePath);

            ResourceLoader *loader = reinterpret_cast<ResourceLoader **>(0xB2E5B0)[loaderId];

            if (!loader)
                return;

            mResourceLoader = loader;
            mUnk3           = 1;
        }

        ResourceLocation(const char *texturePath, u8 loaderId)
        {
            init(texturePath, loaderId);
        }

        // 本当にデフォルトコンストラクタなのかは不明
        ResourceLocation()
        {
            mPath           = nullptr;
            mPathHash       = 0;
            mLoaderId       = 9;
            mResourceLoader = nullptr;
            mUnk3           = 0;
        }

        ResourceLocation &operator=(const ResourceLocation &other)
        {
            gstd::memcpy(this, &other, sizeof(ResourceLocation) /*ゲーム内では0x11*/);
            return *this;
        }

        void FUN_006e2de0(const char *texturePath)
        {
            reinterpret_cast<void (*)(ResourceLocation *, const char *)>(0x6E2DE0)(this, texturePath);
        }

        char           *mPath;    // +0x0
        int             mPathHash;    // +0x4
        u8              mLoaderId;    // +0x8
        ResourceLoader *mResourceLoader;    // +0xC
        u8              mUnk3;    // +0x10

    private:
    };
}    // namespace MC3DSPluginFramework