#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftInputHandler;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Input\\InputHandler.cpp"
    class InputHandler
    {
    public:
        void *operator new(size_t s)
        {
            return gstd::malloc(s);
        }

        void operator delete(void *m)
        {
            gstd::free(m);
        }

    public:
        ~InputHandler()
        {
            reinterpret_cast<void (*)(InputHandler *)>(0x1CCED8)(this);
        }

        void popInputMapping()
        {
            reinterpret_cast<void (*)(InputHandler *)>(0x121D18)(this);
        }

        void updateInputMapping(gstd::string state)
        {
            reinterpret_cast<void (*)(InputHandler *, gstd::string)>(0x1268C8)(this, state);
        }

    private:
        MinecraftInputHandler *mMinecraftInputHandler;
        gstd::vector<void *> mUnk1;
        gstd::map<u32, u32> mUnk2;
        gstd::map<u32, u32> mUnk3;
        gstd::vector<void *> mUnk4;
        gstd::vector<void *> mUnk5;
        gstd::vector<void *> mUnk6;
        gstd::map<u32, u32> mUnk7;
        gstd::vector<void *> mUnk8;

        //...
    };
}    // namespace MC3DSPluginFramework