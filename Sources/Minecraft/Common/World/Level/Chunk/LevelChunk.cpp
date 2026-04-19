#include "LevelChunk.hpp"

namespace MC3DSPluginFramework
{
    void *LevelChunk::operator new(size_t size)
    {
        return reinterpret_cast<void *(*)(size_t)>(0x15D164)(size);
    }

    void LevelChunk::operator delete(void *m)
    {
        reinterpret_cast<void (*)(void *)>(0x15D148)(m);
    }

    LevelChunk::~LevelChunk()
    {
        reinterpret_cast<LevelChunk *(*)(LevelChunk *)>(0x15CF14)(this);
    }

    // FUN_0x156C44
    void LevelChunk::changeState(int32_t from, int32_t to)
    {
        if (!mChunkState.tryChangeState(from, to))
            LOG("Cannot change state, when using this call the initial state should be known", tryChangeState(from, to), 0);
    }

    // FUN_0x15718C
    void LevelChunk::_setGenerator(ChunkSource *generator)
    {
        if (!(mGenerator == nullptr))
            LOG("Cannot set the generator on a levelChunk more than once!", mGenerator == nullptr, 0);

        mGenerator = generator;
    }

    void LevelChunk::setBlockData(const BlockPos &pos, const BlockData &block)
    {
        ChunkBlockPos chunkBlockPos(pos);
        u32           targetSubChunkY = (chunkBlockPos.y >> 4);

        if (targetSubChunkY < MAX_CHUNK_HEIGHT)
        {
            newSubChunk(targetSubChunkY);

            if (SubChunk *subChunk = mSubChunks[targetSubChunkY])
            {
                SubChunkBlockPos subChunkBlockPos(chunkBlockPos);
                u16              index = subChunkBlockPos.index();
                subChunk->writeBlockId(index, block.blockId);
                subChunk->writeDataId(index, block.dataId);
            }
        }
    }

    BlockData LevelChunk::getBlockData(const BlockPos &pos)
    {
        ChunkBlockPos chunkBlockPos(pos);
        u32           targetSubChunkY = (chunkBlockPos.y >> 4);

        if (targetSubChunkY < mSubChunks.size())
            if (SubChunk *subChunk = mSubChunks[targetSubChunkY])
            {
                SubChunkBlockPos subChunkBlockPos(chunkBlockPos);
                u16              index = subChunkBlockPos.index();
                return { subChunk->readBlockId(index), subChunk->readDataId(index) };
            }

        return {};
    }

}    // namespace MC3DSPluginFramework