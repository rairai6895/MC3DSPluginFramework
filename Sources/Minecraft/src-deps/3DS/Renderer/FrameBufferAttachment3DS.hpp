#pragma once

#include "Minecraft/src-deps/Core/Math/Color.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Renderer\\HAL\\3DS\\FrameBufferAttachment3DS.cpp"
    class FrameBufferAttachment3DS
    {
    public:
        void clearFrameBufferAttachment(const Color &color, int frameBufferAttachmentType)
        {
            reinterpret_cast<void (*)(FrameBufferAttachment3DS *, const Color &, int)>(0x504158)(this, color, frameBufferAttachmentType);
        }

    private:
    };
}    // namespace MC3DSPluginFramework