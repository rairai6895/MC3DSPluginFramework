#ifndef CHUNK_HPP
#define CHUNK_HPP

#include "PlayerClass.hpp"
#include "Structs.hpp"
#include <types.h>

namespace MC3DSPluginFramework {
// Do not use while the game thread is stopped.
namespace Chunk {

struct BlockData {
    u8 blockID, dataID;
};

bool Read(const Vec3_Int &pos, BlockData &blockData);
bool Write(const Vec3_Int &pos, const BlockData &blockData);
void Fill(const Vec3_Int &start, const Vec3_Int &end, const BlockData &blockData);

};    // namespace Chunk
}    // namespace MC3DSPluginFramework

#endif