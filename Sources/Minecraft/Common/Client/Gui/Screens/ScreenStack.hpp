#pragma once

#include "Minecraft/Common/Util/Util.hpp"

namespace MC3DSPluginFramework
{
    class Screen;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\screens\\ScreenStack.cpp"
    class ScreenStack
    {
        USE_GAME_ALLOCATOR
    public:
        friend class ClientInstance;

        Screen                                 &getScreen() const;
        void                                    schedulePopScreen(int popCount);
        void                                    _popScreen(u32 unknown);
        bool                                    empty();
        void                                    FUN_0x1a8c6c();
        BoxedPtr::Shared<Screen>                getScreenByName(gstd::string screenName);
        gstd::vector<BoxedPtr::Shared<Screen>> &getStack();

    private:
        gstd::vector<BoxedPtr::Shared<Screen>> mScreenStack;    // +0x0
        gstd::vector<BoxedPtr::Shared<Screen>> mPushQueue;    // +0xC
        int                                    mScheduledScreenPopCount;    // +0x18
        bool                                   mUnk2;    // +0x1C
    };
}    // namespace MC3DSPluginFramework