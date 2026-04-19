#pragma once

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\platform\\AppPlatform.cpp"
    class AppPlatform
    {
    public:
        static constexpr int TOP_SCREEN_WIDTH     = 400;    // 0x919FC4
        static constexpr int TOP_SCREEN_HEIGHT    = 240;    // 0x919FC8
        static constexpr int BOTTOM_SCREEN_WIDTH  = 320;    // 0x919FCC
        static constexpr int BOTTOM_SCREEN_HEIGHT = 240;    // 0x919FD0

    public:
        static AppPlatform *singleton();
        void               *getUIScalingRules();

    private:
    };
}    // namespace MC3DSPluginFramework