#pragma once

#include "ChunkSource.hpp"

namespace MC3DSPluginFramework
{
    class UnknownChunkSource : public ChunkSource
    {
        USE_GAME_ALLOCATOR
    public:
        LevelChunk *getChunk(const ChunkPos &pos) override;

    private:
        // 0x9AE90C

        int   mUnk3;    // +0x18
        void *mUnk4;    // +0x1C
        void *mUnk5;    // +0x20
        void (*mUnk6)(void *, void *, int);    // +0x24
        void *mUnk7;    // +0x28
        void *mUnk8;    // +0x2C
        void *mUnk9;    // +0x30
        void (*mUnk10)(void *, void *, int);    // +0x34
        void *mUnk11;    // +0x38
        void *mUnk12;    // +0x3C
        void *mUnk13;    // +0x40
        void (*mUnk14)(void *, void *, int);    // +0x44
        void *mUnk15;    // +0x48

        // ChunkPosかもしれない
        BlockPos mUnk16;    // +0x4C
        BlockPos mUnk17;    // +0x58
        BlockPos mUnk18;    // +0x64
        BlockPos mUnk19;    // +0x70

        gstd::vector<LevelChunk *>         mUnk20;    // +0x7C
        gstd::vector<gstd::type_unknown<>> mUnk21;    // +0x88
        bool                               mUnk22;    // +0x8C
    };
}    // namespace MC3DSPluginFramework