#pragma once

#include "Minecraft/Common/Util/Util.hpp"

namespace MC3DSPluginFramework
{
    class C_Screen;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\screens\\ScreenStack.cpp"
    class ScreenStack
    {
    public:
        friend class ClientInstance;

        C_Screen &getScreen() const;
        void schedulePopScreen(int popCount);
        void _popScreen(u32 unknown);
        bool empty();
        void Unknown1();
        Util::BoxedPtr::Shared<C_Screen> getScreenByName(gstd::string screenName);
        gstd::vector<Util::BoxedPtr::Shared<C_Screen>> &getStack();

    private:
        gstd::vector<Util::BoxedPtr::Shared<C_Screen>> mScreenStack;
        gstd::vector<Util::BoxedPtr::Shared<C_Screen>> mUnk1;
        int mScheduledScreenPopCount;
        bool mUnk2;    // あるらしい
    };
}    // namespace MC3DSPluginFramework