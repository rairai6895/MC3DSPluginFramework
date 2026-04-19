#pragma once

#include "Gui/Font.hpp"
#include "Minecraft/Common/Client/Renderer/Renderer/Tessellator.hpp"
#include "Minecraft/src-deps/Core/Math/Color.hpp"

namespace MC3DSPluginFramework
{
    namespace UseScreen
    {
        enum : int {
            Top    = 64,
            Bottom = 128,

            Both = Top | Bottom,
        };
    }    // namespace UseScreen

    namespace Unanalyzed
    {
        inline void setShaderColor(const Color &c)
        {
            reinterpret_cast<void (*)(u32, const Color &)>(0x1A9948)(0xB2DD40, c);
        }

    }    // namespace Unanalyzed

    class GuiComponent
    {
    public:
        struct Materials
        {
            static inline MaterialPtr &ui_textured          = *(MaterialPtr *)0xABFC80;
            static inline MaterialPtr &ui_fill_gradient     = *(MaterialPtr *)0xABFC98;
            static inline MaterialPtr &ui_texture_and_color = *(MaterialPtr *)0xABFCA4;
        };

        // FUN_0x1CA098
        GuiComponent()          = default;
        virtual ~GuiComponent() = default;

        void fill(float x1, float y1, float x2, float y2, const Color &color);
        void fill(int x1, int y1, int x2, int y2, const Color &color);
        void fillGradient(int x1, int y1, int x2, int y2, const Color &color1, const Color &color2);
        void outline(int x1, int y1, int x2, int y2, const Color &color, int offset);
        void drawCenteredString(Font *font, gstd::string str, int x, int y, const Color &color, bool unknown);

        // Original Helpers

        void drawRect(int x, int y, int w, int h, const Color &color);
        void drawGradientRect(int x, int y, int w, int h, const Color &color1, const Color &color2);

    private:
    };

}    // namespace MC3DSPluginFramework