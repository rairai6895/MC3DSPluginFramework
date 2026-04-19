#include "SkinRepository.hpp"
#include "Minecraft/Common/Util/StringUtils.hpp"

namespace MC3DSPluginFramework
{
    SkinRepository::SkinRepository(Options *options, SkinGeometryGroup *skinGeometryGroup, TextureGroup *textures, gstd::string p4 /*custom.png*/)
    {
        // 関数が大きすぎて再実装は不可能だった

        using sig = SkinRepository *(*)(SkinRepository *, Options *, SkinGeometryGroup *, TextureGroup *, gstd::string);
        sig(0x28EDAC)(this, options, skinGeometryGroup, textures, p4);
    }

    Skin *SkinRepository::getSkin(gstd::string skinName)
    {
        return reinterpret_cast<Skin *(*)(SkinRepository *, gstd::string)>(0x6D0458)(this, skinName);
    }

    // FUN_0x6D0240
    Skin *SkinRepository::getStandardSkin(int idx)
    {
        switch (idx)
        {
            case 0:
                return getSkin("Standard_Custom");
            case 1:
                return getSkin("Standard_CustomSlim");
            case 2:
                return getSkin("Standard_Alex");
            case 3:
                return getSkin("Standard_Steve");
            case 4:
                return getSkin("Standard_Dummy");
            default:
                return getSkin("Standard_Steve");
        }
    }

    Skin *SkinRepository::getCurrentSkin()
    {
        return reinterpret_cast<Skin *(*)(SkinRepository *)>(0x28ED28)(this);
    }
}    // namespace MC3DSPluginFramework