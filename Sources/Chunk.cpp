#include "Chunk.hpp"

namespace MC3DSPluginFramework {
namespace Chunk {

struct ChunkNumber {
    u32 data[2];
};

struct ChunkOffset {
    u8 data1, data2;
    u16 data3;
};

struct ChunkPos {
    u8 x, y, z, unk;
};

static constexpr int MAX_CHUNK_HEIGHT = 128 / 16;

ChunkOffset GetChunkOffset(const Vec3_Int &pos) {
    ChunkOffset chunkOffset{};
    Function<void>(0x206DD8)(&chunkOffset, &pos);
    return chunkOffset;
}

ChunkNumber GetChunkNumber(const Vec3_Int &pos) {
    ChunkNumber num;
    return *Function<ChunkNumber *>(0x64CA6C)(&num, &pos);
}

void *GetChunk(const ChunkNumber &chunkNumber) {
    if (Entity *player = Player::GetInstance())
        return Function<void *>(0x17AB3C)(*(u32 *)player->Offset(0x210), &chunkNumber);
    return 0;
}

ChunkPos GetChunkPos(const ChunkOffset &chunkOffset) {
    ChunkPos chunkPos{};
    chunkPos.x = chunkOffset.data1;
    u8 data    = (chunkOffset.data3 >> 31);
    data       = (chunkOffset.data3 + (data >> 28));
    data       = (data & ~15);
    data       = (chunkOffset.data3 - data);
    chunkPos.y = data;
    chunkPos.z = chunkOffset.data2;
    return chunkPos;
}

u32 GetPackedPosData(const ChunkPos &chunkPos) {
    return Function<u32>(0x6E3D2C)(&chunkPos);
}

u8 *GetChunkBlocks(const void *chunk, u8 chunkHeight) {
    return *(u8 **)((u32)chunk + 0x5C + (chunkHeight << 2));
}

void CreateNewHeight(void *chunk, u8 chunkHeight) {
    Function<void>(0x15750C)(chunk, chunkHeight, 1);
}

void ReadBlockID(const u8 *blocks, u32 packedPosData, u8 &id) {
    if (blocks)
        id = blocks[packedPosData];
}

void WriteBlockID(u8 *blocks, u32 packedPosData, u8 id) {
    if (blocks)
        blocks[packedPosData] = id;
}

void ReadDataID(const u8 *blocks, u32 packedPosData, u8 &id) {
    if (blocks) {
        u8 dataID = blocks[0x1000 + (packedPosData >> 1)];
        if (packedPosData & 1)
            dataID >>= 4;
        else
            dataID &= 15;
        id = dataID;
    }
}

void WriteDataID(u8 *blocks, u32 packedPosData, u8 id) {
    if (blocks) {
        u8 *ptr = &blocks[0x1000 + (packedPosData >> 1)];
        if (packedPosData & 1)
            *ptr = (*ptr & 0x0F) | ((id & 0xF) << 4);
        else
            *ptr = (*ptr & 0xF0) | (id & 0xF);
    }
}

bool Read(const Vec3_Int &pos, BlockData &blockData) {    // FUN_0x695C84(&blockData, chunk, &chunkOffset)
    ChunkOffset chunkOffset = GetChunkOffset(pos);
    void *chunk             = GetChunk(GetChunkNumber(pos));
    u32 loaded              = *(u32 *)((u32)chunk + 0x7C);    // Loaded Chunk height?
    u32 target              = (chunkOffset.data3 >> 4);       // Target Chunk height?
    if (loaded >= target)
        if (u8 *chunkBlocks = GetChunkBlocks(chunk, target)) {
            u32 packed = GetPackedPosData(GetChunkPos(chunkOffset));
            ReadBlockID(chunkBlocks, packed, blockData.blockID);
            ReadDataID(chunkBlocks, packed, blockData.dataID);
            return true;
        }

    return false;
}

bool Write(const Vec3_Int &pos, const BlockData &blockData) {
    ChunkOffset chunkOffset = GetChunkOffset(pos);
    void *chunk             = GetChunk(GetChunkNumber(pos));
    u32 target              = (chunkOffset.data3 >> 4);
    if (target < MAX_CHUNK_HEIGHT) {
        CreateNewHeight(chunk, target);
        if (u8 *chunkBlocks = GetChunkBlocks(chunk, target)) {
            u32 packed = GetPackedPosData(GetChunkPos(chunkOffset));
            WriteBlockID(chunkBlocks, packed, blockData.blockID);
            WriteDataID(chunkBlocks, packed, blockData.dataID);
            return true;
        }
    }
    return false;
}

void Fill(const Vec3_Int &start, const Vec3_Int &end, const BlockData &blockData) {
    int minX = std::min(start.x, end.x);
    int maxX = std::max(start.x, end.x);
    int minY = std::min(start.y, end.y);
    int maxY = std::max(start.y, end.y);
    int minZ = std::min(start.z, end.z);
    int maxZ = std::max(start.z, end.z);

    for (int x = minX; x <= maxX; ++x)
        for (int z = minZ; z <= maxZ; ++z)
            for (int y = minY; y <= maxY; ++y)
                Write({x, y, z}, blockData);
}

/*
void Chunk::Update(const Vec3_Int &pos) {
    if (const Entity *player = Player::GetInstance()) {
        ChunkOffset chunkOffset = GetChunkOffset(pos);
        Chunk *chunk            = GetChunk(GetChunkNumber(pos));
        auto chunkPos           = GetChunkPos(chunkOffset);
        u32 data1               = 0;
        u32 data2[2]            = {};
        Function(0x15764C).Call<void>(chunk, &chunkPos, &data2[0], &data2[1], *(u32 *)player->Offset(0x210), &data1);
    }
}
*/

}    // namespace Chunk
}    // namespace MC3DSPluginFramework