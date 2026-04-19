#include "Minecraft/Common/Client/Gui/Screens/ScreenStack.hpp"
#include "Minecraft/Common/Client/Gui/Screens/Screen.hpp"
#include "Minecraft/Common/Logger.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x12D54C
    Screen &ScreenStack::getScreen() const
    {
        if (mScreenStack.empty())
            LOG("Screen Stack is empty - There must always be at least one stack on the screen", !mScreenStack.empty(), 0);

        return *mScreenStack.back();
    }

    // FUN_0x1A8304
    void ScreenStack::schedulePopScreen(int popCount)
    {
        mScheduledScreenPopCount += popCount;

        if (!((int)mScreenStack.size() - mScheduledScreenPopCount > 0))
            LOG("Attempting to pop too many screens", (int)mScreenStack.size() - mScheduledScreenPopCount > 0, 0);
    }

    void ScreenStack::_popScreen(u32 unknown)
    {
        reinterpret_cast<void (*)(ScreenStack *, int)>(0x1A79E0)(this, unknown);
    }

    // FUN_0x12D530
    bool ScreenStack::empty()
    {
        return mScreenStack.empty();
    }

    // FUN_0x1A8C6C
    void ScreenStack::FUN_0x1a8c6c()
    {
        mUnk2 = false;
    }

    // FUN_0x6AB38C
    BoxedPtr::Shared<Screen> ScreenStack::getScreenByName(gstd::string screenName)
    {
        for (auto &scr : mScreenStack)
            if (scr && (scr->getName() == screenName))
                return scr;

        return nullptr;
    }

    gstd::vector<BoxedPtr::Shared<Screen>> &ScreenStack::getStack()
    {
        return mScreenStack;
    }
}    // namespace MC3DSPluginFramework