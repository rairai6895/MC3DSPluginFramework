#pragma once

#include "AppPlatformListener.hpp"

namespace MC3DSPluginFramework
{
    class App : public AppPlatformListener
    {
    public:
        // FUN_0x10C780
        App() :
            AppPlatformListener(0),
            mStart(false),
            mQuit(false),
            mUnk3(nullptr)
        {
        }

        ~App() override = default;

    private:
        // 0x9C64AC

        bool  mStart;    // +0x8
        bool  mQuit;    // +0x9
        void *mUnk3;    // +0xC
    };
}    // namespace MC3DSPluginFramework