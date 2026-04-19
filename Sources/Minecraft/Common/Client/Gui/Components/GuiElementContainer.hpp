#pragma once

#include "GuiElement.hpp"
#include "Helpers/Macro.hpp"
#include "Minecraft/Common/Util/Util.hpp"
#include <algorithm>

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\components\\GuiElementContainer.cpp"
    class GuiElementContainer : public GuiElement
    {
        USE_GAME_ALLOCATOR
    public:
        GuiElementContainer(bool active, bool visible, int x, int y, int w, int h);
        ~GuiElementContainer() override = default;

        void         Unknown3(MinecraftGame *minecraftGame) override;
        void         render(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        void         Unknown5(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        void         Unknown6() override;
        bool         onTouchDown(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        bool         onTouchRelease(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        void         Unknown9(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        void         Unknown10(MinecraftGame *minecraftGame, int x, int y) override;
        void         Unknown12(MinecraftGame *minecraftGame, int p2) override;
        void         Unknown13(MinecraftGame *minecraftGame, int x, int y) override;
        bool         onBack(MinecraftGame *minecraftGame, int p2) override;
        bool         Unknown17() override;
        bool         Unknown25() override;
        virtual void addChild(BoxedPtr::Shared<GuiElement> element, bool p2);
        virtual void addChild(GuiElement *element, bool p2);
        virtual void Unknown26() = delete;    // +0x88
        virtual void clearChildren();    // +0x8C

    protected:
        // 0x9BC2E4

        gstd::vector<BoxedPtr::Shared<GuiElement>> mChildren;    // +0x38
        gstd::vector<bool>                         mUnk1;    // +0x44
        int                                        mUnk2;    // +0x58
        int                                        mUnk3;    // +0x5C
    };
}    // namespace MC3DSPluginFramework