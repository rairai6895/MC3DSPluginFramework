#pragma once

#include "../Block/BlockData.hpp"
#include <cstddef>

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\SubChunk.cpp"
    class SubChunk
    {
    public:
        SubChunk(u32 unknown1, u32 unknown2);

        void   *operator new(size_t size);
        void    writeBlockId(u16 index, BlockId id);
        void    writeDataId(u16 index, u8 id);
        BlockId readBlockId(u16 index);
        u8      readDataId(u16 index);
    };
}    // namespace MC3DSPluginFramework