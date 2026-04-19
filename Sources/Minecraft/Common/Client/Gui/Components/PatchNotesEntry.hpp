#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\gui\\components\\PatchNotesEntry.cpp"
    class PatchNotesEntry
    {
        USE_GAME_ALLOCATOR
    public:
        void _process(gstd::string line, u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(PatchNotesEntry *, gstd::string, u32, u32)>(0x2D6548)(this, line, unknown1, unknown2);
        }

    private:
    };
}    // namespace MC3DSPluginFramework