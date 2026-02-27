#pragma once

#include <types.h>

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\SubChunk.cpp"
    class SubChunk
    {
    public:
        SubChunk(u32 unknown1, u32 unknown2)
        {
            reinterpret_cast<void (*)(SubChunk *, u32, u32)>(0x661CDC)(this, unknown1, unknown2);
        }

        void *operator new(size_t size)
        {
            return reinterpret_cast<void *(*)(size_t)>(0x661D80)(size);
        }

        void writeBlockId(u16 index, BlockId id)
        {
            *(BlockId *)((u32)this + index) = id;
        }

        void writeDataId(u16 index, u8 id)
        {
            u8 *ptr = (u8 *)((u32)this + (0x1000 + (index >> 1)));

            if (index & 1)
                *ptr = (*ptr & 0xF) | ((id & 0xF) << 4);
            else
                *ptr = (*ptr & 0xF0) | (id & 0xF);
        }

        BlockId readBlockId(u16 index)
        {
            return *(BlockId *)((u32)this + index);
        }

        u8 readDataId(u16 index)
        {
            u8 dataID = *(u8 *)((u32)this + (0x1000 + (index >> 1)));

            if (index & 1)
                dataID >>= 4;
            else
                dataID &= 15;

            return dataID;
        }

    private:
    };
}    // namespace MC3DSPluginFramework