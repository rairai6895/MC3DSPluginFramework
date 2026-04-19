#include "NbtEditor.hpp"
#include "Extensions/Event.hpp"

namespace MC3DSPluginFramework::NbtEditor
{

    void checkSafe()
    {
        while (!(Event::States & EventStates::RegisteredNbtTags))
            svcSleepThread(MS(5));
    }

    void setSignTextTag(ItemInstance &item, gstd::string line1, gstd::string line2, gstd::string line3, gstd::string line4)
    {
        checkSafe();

        if (!item.mItem)
            return;

        if (item.getId() != (u16)ItemId::sign)
            return;

        if (!item.mNbt)
            item.mNbt = gstd::make_unique<CompoundTag>("");

        if (!item.mNbt->contains(Tag::BlockEntityTag, Tag::Type::Compound))
            item.mNbt->putCompound(Tag::BlockEntityTag, gstd::make_unique<CompoundTag>());

        auto blockEntityTag     = item.mNbt->getCompound(Tag::BlockEntityTag);
        auto copyBlockEntityTag = blockEntityTag->_copy();

        copyBlockEntityTag->putString(Tag::Text1, line1);
        copyBlockEntityTag->putString(Tag::Text2, line2);
        copyBlockEntityTag->putString(Tag::Text3, line3);
        copyBlockEntityTag->putString(Tag::Text4, line4);

        item.mNbt->putCompound(Tag::BlockEntityTag, std::move(copyBlockEntityTag));
    }

    void setMonsterSpawnerTag(ItemInstance &item, EntityId id, u16 delay, u16 minSpawnDelay, u16 maxSpawnDelay, u16 spawnCount, u16 maxNearbyEntities, u16 requiredPlayerRange, u16 spawnRange)
    {
        checkSafe();

        if (!item.mItem)
            return;

        if (item.getId() != (u16)ItemId::mob_spawner)
            return;

        if (!item.mNbt)
            item.mNbt = gstd::make_unique<CompoundTag>("");

        if (!item.mNbt->contains(Tag::BlockEntityTag, Tag::Type::Compound))
            item.mNbt->putCompound(Tag::BlockEntityTag, gstd::make_unique<CompoundTag>());

        auto blockEntityTag     = item.mNbt->getCompound(Tag::BlockEntityTag);
        auto copyBlockEntityTag = blockEntityTag->_copy();

        copyBlockEntityTag->putInt(Tag::EntityId, (int)id);
        copyBlockEntityTag->putShort(Tag::Delay, delay);
        copyBlockEntityTag->putShort(Tag::MinSpawnDelay, minSpawnDelay);
        copyBlockEntityTag->putShort(Tag::MaxSpawnDelay, maxSpawnDelay);
        copyBlockEntityTag->putShort(Tag::SpawnCount, spawnCount);
        copyBlockEntityTag->putShort(Tag::MaxNearbyEntities, maxNearbyEntities);
        copyBlockEntityTag->putShort(Tag::RequiredPlayerRange, requiredPlayerRange);
        copyBlockEntityTag->putShort(Tag::SpawnRange, spawnRange);

        item.mNbt->putCompound(Tag::BlockEntityTag, std::move(copyBlockEntityTag));
    }

    void setUnbreakableTag(ItemInstance &item)
    {
        checkSafe();

        if (!item.mItem)
            return;

        if (!item.mNbt)
            item.mNbt = gstd::make_unique<CompoundTag>("");

        item.mNbt->putByte(Tag::Unbreakable, true);
    }

    void removeUnbreakableTag(ItemInstance &item)
    {
        checkSafe();

        if (!item.mNbt)
            return;

        item.mNbt->remove(Tag::Unbreakable);
    }

    void setCustomColorTag(ItemInstance &item, const Color &color)
    {
        checkSafe();

        if (!item.mItem)
            return;

        if (!item.mNbt)
            item.mNbt = gstd::make_unique<CompoundTag>("");

        item.mNbt->putInt(Tag::customColor, color.toARGB());
    }

    void removeCustomColorTag(ItemInstance &item)
    {
        checkSafe();

        if (!item.mNbt)
            return;

        item.mNbt->remove(Tag::customColor);
    }

    void setItemsTag(ItemInstance &item, const std::vector<std::pair<u8, ItemInstance>> &items)
    {
        checkSafe();

        if (!item.mItem)
            return;

        if (!item.mNbt)
            item.mNbt = gstd::make_unique<CompoundTag>("");

        auto itemsTag = gstd::make_unique<ListTag>();

        for (auto &d : items)
        {
            auto itemTag = d.second.toNbt();
            itemTag->putByte(Tag::Slot, d.first);
            itemTag->setTag(Tag::Item);
            itemsTag->mList.push_back(std::move(itemTag));
        }

        item.mNbt->putList(Tag::Items, std::move(itemsTag));
    }

    void setItemsTag(ItemInstance &item, std::vector<std::pair<u8, gstd::unique_ptr<CompoundTag>>> &&items)
    {
        checkSafe();

        if (!item.mItem)
            return;

        if (!item.mNbt)
            item.mNbt = gstd::make_unique<CompoundTag>("");

        auto itemsTag = gstd::make_unique<ListTag>();

        for (auto &d : items)
        {
            d.second->putByte(Tag::Slot, d.first);
            d.second->setTag(Tag::Item);
            itemsTag->mList.push_back(std::move(d.second));
        }

        item.mNbt->putList(Tag::Items, std::move(itemsTag));
    }

    void setItemFrameTag(ItemInstance &item, const ItemInstance &in, u8 rotation)
    {
        checkSafe();

        if (!item.mItem)
            return;

        if (item.getId() != (u16)ItemId::frame)
            return;

        if (!item.mNbt)
            item.mNbt = gstd::make_unique<CompoundTag>("");

        if (!item.mNbt->contains(Tag::BlockEntityTag, Tag::Type::Compound))
            item.mNbt->putCompound(Tag::BlockEntityTag, gstd::make_unique<CompoundTag>());

        auto blockEntityTag     = item.mNbt->getCompound(Tag::BlockEntityTag);
        auto copyBlockEntityTag = blockEntityTag->_copy();

        copyBlockEntityTag->putByte(Tag::ItemRotation, rotation);
        copyBlockEntityTag->putCompound(Tag::Item, in.toNbt());
        item.mNbt->putCompound(Tag::BlockEntityTag, std::move(copyBlockEntityTag));
    }
}    // namespace MC3DSPluginFramework::NbtEditor