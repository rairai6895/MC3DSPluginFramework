#include "GuiComponent.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x6CFEC0
    void GuiComponent::fill(float x1, float y1, float x2, float y2, const Color &color)
    {
        auto &t = Tessellator::instance;

        t.begin(4);
        t.color(color);
        t.vertex(x1, y2, 0);
        t.vertex(x2, y2, 0);
        t.vertex(x2, y1, 0);
        t.vertex(x1, y1, 0);
        t.draw(Materials::ui_fill_gradient);
    }

    // FUN_0x6CFF68
    void GuiComponent::fill(int x1, int y1, int x2, int y2, const Color &color)
    {
        fill((float)x1, (float)y1, (float)x2, (float)y2, color);
    }

    // FUN_0x28B448
    void GuiComponent::fillGradient(int x1, int y1, int x2, int y2, const Color &color1, const Color &color2)
    {
        auto &t = Tessellator::instance;

        t.begin(4);
        t.color(color1);
        t.vertex(x2, y1, 0);
        t.vertex(x1, y1, 0);
        t.color(color2);
        t.vertex(x1, y2, 0);
        t.vertex(x2, y2, 0);
        t.draw(Materials::ui_fill_gradient);
    }

    // FUN_0x28C580
    void GuiComponent::outline(int x1, int y1, int x2, int y2, const Color &color, int offset)
    {
        fill(x1, y1, x2, y1 + offset, color);
        fill(x1, y2 - offset, x2, y2, color);
        fill(x1, y1, x1 + offset, y2, color);
        fill(x2 - offset, y1, x2, y2, color);
    }

    // FUN_0x28B970
    void GuiComponent::drawCenteredString(Font *font, gstd::string str, int x, int y, const Color &color, bool unknown)
    {
        int w = font->getTextWidth(str, false, 1.f);
        font->drawWithShadow((x - w / 2), (y + 5), 1.f, str, color, unknown, 0);
    }

    void GuiComponent::drawRect(int x, int y, int w, int h, const Color &color)
    {
        fill(x, y, x + w, y + h, color);
    }

    void GuiComponent::drawGradientRect(int x, int y, int w, int h, const Color &color1, const Color &color2)
    {
        fillGradient(x, y, x + w, y + h, color1, color2);
    }
}    // namespace MC3DSPluginFramework