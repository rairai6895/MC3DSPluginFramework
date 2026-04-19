#pragma once

#include "Minecraft/gstd/gstd.hpp"
#include "SkinPack.hpp"

namespace MC3DSPluginFramework
{
    class Options;
    class SkinGeometryGroup;
    class TextureGroup;
    class Skin;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\player\\SkinRepository.cpp"
    class SkinRepository
    {
        USE_GAME_ALLOCATOR
    public:
        SkinRepository(Options *options, SkinGeometryGroup *skinGeometryGroup, TextureGroup *textures, gstd::string p4 /*custom.png*/);
        virtual ~SkinRepository() = default;

        Skin *getSkin(gstd::string skinName);
        Skin *getStandardSkin(int idx);
        Skin *getCurrentSkin();

    private:
        // 0x9AD044

        Options                                                 *mOptions;    // +0x4
        TextureGroup                                            *mTextures;    // +0x8
        int                                                      mUnk1;    // +0xC
        int                                                      mUnk2;    // +0x10
        int                                                      mUnk3;    // +0x14
        SkinGeometryGroup                                       *mSkinGeometryGroup;    // +0x18
        gstd::map<int, gstd::vector<gstd::unique_ptr<SkinPack>>> mUnk4;    // +0x1C
        gstd::vector<SkinPack *>                                 mUnk5;    // +0x38
        //...
    };
}    // namespace MC3DSPluginFramework