#include "Helpers/GradRender.hpp"

namespace GradRender
{

    struct NotificationItem
    {
        NotificationItem(const std::string &msg) :
            mMessage(msg), mDrawn(false) {}

        std::string mMessage;
        CTRPF::Clock mClock;
        bool mDrawn;
    };

    inline std::vector<NotificationItem> messages;
    inline RecursiveLock mMutex;

    constexpr float MAXBRIGHTNESS = 1.6f;
    constexpr float MINBRIGHTNESS = 0.f;
    constexpr float SHADOW_POWER  = 0.1f;

    int drawGlyph(const CTRPF::Screen &scr, const CTRPF::Glyph *glyph, int posX, const int posY, const CTRPF::Color &baseColor, const bool shadow)
    {
        if (!glyph)
            return posX;

        posX += glyph->xOffset;
        const u8 *data                   = glyph->glyph;
        static constexpr int glyphHeight = 16;

        const auto Blend_Draw =
            [&](int x, int y, const CTRPF::Color &input) {
                CTRPF::Color c;
                scr.ReadPixel(x, y, c);
                scr.DrawPixel(x, y, c.Blend(input, CTRPF::Color::BlendMode::Alpha));
            };

        for (int row = 0; row < glyphHeight; ++row) {
            float brightness = MAXBRIGHTNESS - ((float)row / (float)glyphHeight) * (MAXBRIGHTNESS - MINBRIGHTNESS);
            brightness       = std::clamp(brightness, 0.0f, 2.0f);

            u8 r = (u8)(std::min(baseColor.r * brightness, 255.0f));
            u8 g = (u8)(std::min(baseColor.g * brightness, 255.0f));
            u8 b = (u8)(std::min(baseColor.b * brightness, 255.0f));
            CTRPF::Color gradColor(r, g, b);

            for (int col = 0; col < 13; ++col) {
                u8 alpha = data[row * 13 + col];

                if (alpha <= 12)
                    continue;

                int drawX   = posX + col;
                int drawY   = posY + row;
                gradColor.a = alpha;

                if (shadow) {
                    CTRPF::Color shadowColor((u8)(r * SHADOW_POWER), (u8)(g * SHADOW_POWER), (u8)(b * SHADOW_POWER), alpha);
                    Blend_Draw(drawX + 1, drawY + 1, shadowColor);
                }

                Blend_Draw(drawX, drawY, gradColor);
            }
        }
        return posX + glyph->xAdvance;
    }

    int drawSysfont(const CTRPF::Screen &scr, const std::string &text, const int posX, const int posY, const bool shadow, int xLimits, float offset, const char *end)
    {
        CTRPF::Color color = CTRPF::Color::White;
        int x              = posX;
        int y              = posY;
        u8 *str            = (u8 *)text.c_str();

        if (!(str && *str))
            return x;

        xLimits = std::min(xLimits, (scr.IsTop ? 400 : 320));

        if (str[0] == 0xEF && str[1] == 0xBB && str[2] == 0xBF)
            str += 3;

        do {
            if (x >= xLimits || str == (u8 *)end)
                break;

            u8 c = *str;

            if (c == '\n' || c == '\r') {
                ++str;
                x = posX;
                y += 16;
                continue;
            }

            if (c == 0x1B) {
                ++str;
                color.r = *str++;
                color.g = *str++;
                color.b = *str++;
                continue;
            }

            CTRPF::Glyph *glyph = CTRPluginFramework::Font::GetGlyph(str);

            if (!glyph)
                break;

            float gWidth = glyph->Width();
            if (x + gWidth >= xLimits) {
                x = posX;
                y += 16;
            }

            if (offset >= gWidth) {
                offset -= gWidth;
                continue;
            }

            x = drawGlyph(scr, glyph, x, y, color, shadow);

        } while (*str);

        return y + 16;
    }

    bool main(const CTRPF::Screen &scr)
    {
        RecursiveLock_Lock(&mMutex);

        messages.erase(
            std::remove_if(
                messages.begin(),
                messages.end(),
                [](NotificationItem &data) {
                    return data.mDrawn && data.mClock.HasTimePassed(CTRPF::Seconds(5.f));
                }
            ),
            messages.end()
        );

        if (scr.IsTop) {
            int size  = messages.size();
            int count = std::min(9, size);
            int posY  = 240 - 24 * count - 5;

            for (size_t i = std::max(0, size - count); i < size; ++i) {
                auto &msg = messages[i];
                int width = CTRPF::OSD::GetTextWidth(1, msg.mMessage);
                int posX  = (400 - width) - 10;

                scr.DrawRect(posX - 3, posY, width + 8, 18, CTRPF::Color::Black);
                drawSysfont(scr, msg.mMessage, posX, posY, false);
                posY += 24;

                if (!msg.mDrawn) {
                    msg.mDrawn = true;
                    msg.mClock.Restart();
                }
            }
        }

        RecursiveLock_Unlock(&mMutex);
        return 0;
    }

    void install()
    {
        CTRPF::OSD::Run(main);
    }

    void unInstall()
    {
        CTRPF::OSD::Stop(main);
    }

    void notify(const std::string &msg)
    {
        RecursiveLock_Lock(&mMutex);
        messages.push_back(NotificationItem(msg));
        RecursiveLock_Unlock(&mMutex);
    }

}    // namespace GradRender