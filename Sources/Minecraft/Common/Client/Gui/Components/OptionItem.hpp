#pragma once

#include "GuiElementContainer.hpp"
#include "Minecraft/Common/Client/Options/Options.hpp"

namespace MC3DSPluginFramework
{
    class OptionItem : public GuiElementContainer
    {
        USE_GAME_ALLOCATOR
    public:
        OptionItem(const Options::Option *option, BoxedPtr::Shared<GuiElement> element, bool p3, int offsetY);
        ~OptionItem() override = default;

        void                 render(MinecraftGame *minecraftGame, int touchX, int touchY) override;
        void                 Unknown6() override;
        bool                 Unknown19() override;
        int                  getHeight() override;
        void                 drawOutline(int offset) override;
        void                 onSelectedChanged() override;
        virtual void         Unknown27() = delete;    // +0x90
        virtual gstd::string getLocalizedName(MinecraftGame *minecraftGame);
        virtual int          getOffsetY();

    private:
        // 0x99D7E0
        // 0x99D884

        const Options::Option *mOption;    // 0x60
        bool                   mUnk1;    // 0x64
        int                    mOffsetY;    // 0x68
    };
}    // namespace MC3DSPluginFramework