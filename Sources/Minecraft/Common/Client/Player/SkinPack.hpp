#pragma once

#include "Minecraft/gstd/gstd.hpp"
#include "Skin.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\player\\SkinPack.cpp"
    class SkinPack
    {
    public:
        SkinPack(bool p1, gstd::string serializableName, gstd::string packHeader, gstd::type_unknown<0x4> p4)
        {
            reinterpret_cast<SkinPack *(*)(SkinPack *, bool, gstd::string, gstd::string, gstd::type_unknown<0x4>)>(0x660334)(this, p1, serializableName, packHeader, p4);
        }

    private:
        bool                    mUnk1;    // +0x0
        gstd::type_unknown<0x4> mUnk2;    // +0x4
        gstd::string            mSerializableName;    // +0x8 "Standard"
        gstd::string            mPackHeader;    // +0xC "skins.skinpackHeader.standard"
        gstd::vector<Skin>      mSkins;    // +0x10
        gstd::type_unknown<0x4> mUnk3;    // +0x1C
        gstd::type_unknown<0x4> mUnk4;    // +0x20
        gstd::type_unknown<0x4> mUnk5;    // +0x24
        gstd::type_unknown<0x4> mUnk6;    // +0x28
        gstd::type_unknown<0x4> mUnk7;    // +0x2C
        gstd::type_unknown<0x4> mUnk8;    // +0x30
        gstd::type_unknown<0x4> mUnk9;    // +0x34
    };
}    // namespace MC3DSPluginFramework