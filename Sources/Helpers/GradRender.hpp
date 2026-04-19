#pragma once

#include <CTRPluginFramework.hpp>
#include <CTRPluginFrameworkImpl.hpp>

namespace GradRender
{
    namespace CTRPF = CTRPluginFramework;

    int  drawGlyph(const CTRPF::Screen &scr, const CTRPF::Glyph *glyph, int posX, const int posY, const CTRPF::Color &baseColor, const bool shadow);
    int  drawSysfont(const CTRPF::Screen &scr, const std::string &text, const int posX, const int posY, const bool shadow, int xLimits = 400, float offset = 0, const char *end = nullptr);
    void install();
    void unInstall();
    void notify(const std::string &msg);

}    // namespace GradRender