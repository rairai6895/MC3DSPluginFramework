#include "Minecraft/Common/World/Level/Chunk/LevelChunk.hpp"

namespace MC3DSPluginFramework
{

    // FUN_0x156C44
    void LevelChunk::changeState(s32 from, s32 to)
    {
        if (!mUnk6.tryChangeState(from, to))
            LOG("Cannot change state, when using this call the initial state should be known", tryChangeState(from, to), 0);
    }

    // FUN_0x15718C;
    void LevelChunk::_setGenerator(void *generator)
    {
        if (mGenerator == nullptr)
            mGenerator = generator;

        LOG("Cannot set the generator on a levelChunk more than once!", mGenerator == nullptr, 0);
    }

    void LevelChunk::setBlockData(const BlockPos &pos, const BlockData &block)
    {
        ChunkBlockPos chunkBlockPos(pos);
        size_t targetSubChunkY = (chunkBlockPos.y >> 4);

        if (targetSubChunkY < MAX_CHUNK_HEIGHT) {
            newSubChunk(targetSubChunkY);

            if (SubChunk *subChunk = mSubChunks[targetSubChunkY]) {
                SubChunkBlockPos subChunkBlockPos(chunkBlockPos);
                u16 index = subChunkBlockPos.index();
                subChunk->writeBlockId(index, block.blockId);
                subChunk->writeDataId(index, block.dataId);
            }
        }
    }

    BlockData LevelChunk::getBlockData(const BlockPos &pos)
    {
        ChunkBlockPos chunkBlockPos(pos);
        size_t targetSubChunkY = (chunkBlockPos.y >> 4);

        if (targetSubChunkY < mSubChunks.size())
            if (SubChunk *subChunk = mSubChunks[targetSubChunkY]) {
                SubChunkBlockPos subChunkBlockPos(chunkBlockPos);
                u16 index = subChunkBlockPos.index();
                return { subChunk->readBlockId(index), subChunk->readDataId(index) };
            }

        return {};
    }

}    // namespace MC3DSPluginFramework