#pragma once

#include "C_Screen.hpp"

namespace MC3DSPluginFramework
{
    class MainMenuScreen : public C_Screen
    {
    public:
    public:
        ~MainMenuScreen() override;

        void Unknown13() override
        {
            return;
        }

    private:
        gstd::unique_ptr<void *> mUnk22;    // +0x90
        C_Screen *mCubeMapScreen;    // +0x94
        u32 mUnk23;    // +0x98 unique?
        gstd::string mUnk24;    // +0x9C
        gstd::string mUnk25;    // +0xA0
        u16 mUnk26;    // +0xA4
        u32 mUnk27;    // +0xA8
        u32 mUnk28;    // +0xAC
        u32 mUnk29;    // +0xB0
        u32 mUnk30;    // +0xB4
        u32 mUnk31;    // +0xB8
        u32 mUnk32;    // +0xBC
        gstd::string mUnk33;    // +0xC0
        u32 mUnk34;    // +0xC4
        gstd::string mVersion;    // +0xC8 v1.1.7
        u32 mUnk35;    // +0xCC
        u32 mUnk36;    // +0xD0

        // SkinRenderer* mSkinRenderer
    };
}    // namespace MC3DSPluginFramework