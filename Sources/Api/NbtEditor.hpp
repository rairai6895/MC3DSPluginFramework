#pragma once

#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include "Minecraft/src-deps/Core/Math/Color.hpp"

namespace MC3DSPluginFramework::NbtEditor
{
    void setSignTextTag(ItemInstance &item, gstd::string line1, gstd::string line2, gstd::string line3, gstd::string line4);
    void setMonsterSpawnerTag(ItemInstance &item, EntityId id, u16 delay, u16 minSpawnDelay, u16 maxSpawnDelay, u16 spawnCount, u16 maxNearbyEntities, u16 requiredPlayerRange, u16 spawnRange);
    void setUnbreakableTag(ItemInstance &item);
    void removeUnbreakableTag(ItemInstance &item);
    void setCustomColorTag(ItemInstance &item, const Color &color);
    void removeCustomColorTag(ItemInstance &item);
    void setItemsTag(ItemInstance &item, const std::vector<std::pair<u8, ItemInstance>> &items);
    void setItemsTag(ItemInstance &item, std::vector<std::pair<u8, std::unique_ptr<CompoundTag>>> &&items);
    void setItemFrameTag(ItemInstance &item, const ItemInstance &in, u8 rotation);

}    // namespace MC3DSPluginFramework::NbtEditor