#pragma once

#include "Minecraft/Common/Resources/ResourceLocation.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class TextureGroup;
    class ResourceLoader;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Renderer\\TexturePtr.cpp"
    class TexturePtr
    {
    public:
        // FUN_0x4F0750
        TexturePtr()
        {
            mTextures = nullptr;
            mPtr      = nullptr;
            mUnk3     = -1;
        }

        // FUN_0x4F06F4
        TexturePtr(TextureGroup &textures, const ResourceLocation &resourceLocation)
        {
            mResourceLocation = resourceLocation;

            if (mTextures != &textures)
            {
                mPtr      = nullptr;
                mTextures = &textures;
            }
        }

        // FUN_0x4F068C
        TexturePtr(const TexturePtr &other)
        {
            mResourceLocation = other.mResourceLocation;

            if (this->mTextures != other.mTextures)
            {
                this->mPtr      = nullptr;
                this->mTextures = other.mTextures;
            }
        }

        // FUN_0x4F0780
        ~TexturePtr()
        {
            if (mTextures)
            {
                mPtr      = nullptr;
                mTextures = nullptr;
            }
        }

        // FUN_0x4F079C
        TexturePtr &operator=(const TexturePtr &other)
        {
            mResourceLocation = other.mResourceLocation;

            if (this->mTextures != other.mTextures)
            {
                this->mPtr      = nullptr;
                this->mTextures = other.mTextures;
            }

            return *this;
        }

    private:
        TextureGroup    *mTextures;    // +0x0
        void            *mPtr;    // +0x4
        int              mUnk3;    // +0x8 state?
        ResourceLocation mResourceLocation;    // +0xC
    };
}    // namespace MC3DSPluginFramework