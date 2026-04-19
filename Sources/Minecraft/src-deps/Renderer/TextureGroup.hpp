#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Renderer\\TextureGroup.cpp"
    class TextureGroup
    {
    public:
    private:
        gstd::map<std::pair<gstd::string, int /*hash*/>, gstd::type_unknown<>> m_TexturePairMap;    // +0x0
        int                                                                    mUnk1;    // +0x1C
        gstd::vector<gstd::type_unknown<>>                                     mUnk2;    // +0x20
        gstd::vector<gstd::type_unknown<0x98> *>                               m_DynamicTextures;    // +0x2C
        gstd::vector<gstd::type_unknown<>>                                     mUnk4;    // +0x38
    };
}    // namespace MC3DSPluginFramework