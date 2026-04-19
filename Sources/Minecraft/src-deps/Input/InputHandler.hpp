#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftInputHandler;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Input\\InputHandler.cpp"
    class InputHandler
    {
        USE_GAME_ALLOCATOR
    public:
        ~InputHandler()
        {
            reinterpret_cast<InputHandler *(*)(InputHandler *)>(0x1CCED8)(this);
        }

        void popInputMapping()
        {
            reinterpret_cast<void (*)(InputHandler *)>(0x121D18)(this);
        }

        void updateInputMapping(gstd::string inputMode)
        {
            reinterpret_cast<void (*)(InputHandler *, gstd::string)>(0x1268C8)(this, inputMode);
        }

    private:
        MinecraftInputHandler                                *mMinecraftInputHandler;    // +0x4
        gstd::vector<gstd::type_unknown<>>                    mUnk1;    // +0x8
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk2;    // +0x10
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk3;    // +0x2C
        gstd::vector<gstd::type_unknown<>>                    mUnk4;    // +0x48
        gstd::vector<gstd::type_unknown<>>                    mUnk5;    // +0x54
        gstd::vector<gstd::type_unknown<>>                    mUnk6;    // +0x60
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> mUnk7;    // +0x6C
        gstd::vector<gstd::type_unknown<>>                    mUnk8;    // +0x88

        //...
    };
}    // namespace MC3DSPluginFramework