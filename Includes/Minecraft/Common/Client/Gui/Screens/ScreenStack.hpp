#pragma once

#include "Minecraft/Common/Client/Gui/Screens/BaseScreen.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\screens\\ScreenStack.cpp"
    class ScreenStack
    {
    public:
        // FUN_0x12D54C
        BaseScreen &getScreen(void) const
        {
            if (mScreenStack.empty()) {
                LOG("Screen Stack is empty - There must always be at least one stack on the screen", !mScreenStack.empty(), 0);
            }

            return *mScreenStack.back();
        }

        // FUN_0x1A8304
        void schedulePopScreen(int popCount)
        {
            mScheduledScreenPopCount += popCount;

            if (!((int)mScreenStack.size() - mScheduledScreenPopCount > 0))
                LOG("Attempting to pop too many screens", (int)mScreenStack.size() - mScheduledScreenPopCount > 0, 0);
        }

        void _popScreen(u32 unknown)
        {
            reinterpret_cast<void (*)(ScreenStack *, int)>(0x1A79E0)(this, unknown);
        }

    private:
        gstd::vector<Util::BoxedPtr::Shared<BaseScreen>> mScreenStack;
        gstd::vector<Util::BoxedPtr::Shared<BaseScreen>> mUnk1;
        int mScheduledScreenPopCount;
    };
}    // namespace MC3DSPluginFramework