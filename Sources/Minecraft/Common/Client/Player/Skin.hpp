#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Resources/ResourceLocation.hpp"
#include "Minecraft/Common/Util/StringUtils.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class SkinPack;
    class ResourcePackManager;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\player\\Skin.cpp"
    class Skin
    {
    public:
        // FUN_0x58033C
        Skin(gstd::string serializableName, gstd::string p2, int hash /*多分コンパイル時に決まってる*/, const ResourceLocation &resourceLocation, bool p5, int p6, float p7)
        {
            mSkinPack         = nullptr;
            mUnk1             = -1;
            mUnk2             = -1;
            mSerializableName = serializableName;
            mUnk3             = p2;
            mHash             = hash;
            mUnk4             = p6;

            mPath           = resourceLocation.mPath;
            mPathHash       = resourceLocation.mPathHash;
            mLoaderId       = resourceLocation.mLoaderId;
            mResourceLoader = resourceLocation.mResourceLoader;
            mUnk7           = resourceLocation.mUnk3;

            mUnk8 = p5;
            mUnk9 = p7;

            if (Util::stringContains(serializableName, '_'))
                LOG("This character is used to separate skin pack and skin name", !Util::stringContains(serializableName, '_'), 0);
        }

        void setSkinPack(SkinPack *skinPack)
        {
            reinterpret_cast<void (*)(Skin *, SkinPack *)>(0x580044)(this, skinPack);
        }

        SkinPack    *mSkinPack;    // +0x0
        int          mUnk1;    // +0x4
        int          mUnk2;    // +0x8
        gstd::string mSerializableName;    // +0xC "Standard_Steve"
        gstd::string mUnk3;    // +0x10 "skin.name.steve"
        int          mHash;    // +0x14
        float        mUnk4;    // +0x18

        // ↓ ResourceLocation ?

        char            *mPath;    // +0x1C
        int              mPathHash;    // +0x20
        u8               mLoaderId;    // +0x24
        ResourceLoader  *mResourceLoader;    // +0x28
        u8               mUnk7;    // +0x2C
        gstd::padding<3> pad1;    // +0x2D

        bool  mUnk8;    // +0x30
        float mUnk9;    // +0x34
    };
}    // namespace MC3DSPluginFramework