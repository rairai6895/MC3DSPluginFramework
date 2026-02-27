#include "Extensions/NbtEditor.hpp"

namespace MC3DSPluginFramework::NbtEditor
{

    void checkSafe()
    {
        while (!(Event::States & EventStates::RegisteredNbtTags))
            svcSleepThread(MS(5));
    }

    size_t getRepairCost(ItemInstance &item)
    {
        checkSafe();

        if (item.mNbt)
            if (gstd::reference_ptr repairCostTag = item.mNbt->getInt(Tag::RepairCost))
                return repairCostTag->mValue;

        return 0;
    }

    void setSignTextTag(ItemInstance &item, gstd::string line1, gstd::string line2, gstd::string line3, gstd::string line4)
    {
        checkSafe();

        //{"CustomName", new StringTag("test")},

        if (item.mItem->mId == ItemId::sign) {
            gstd::reference_ptr<CompoundTag> nbt(item.mNbt);
            gstd::unique_ptr<CompoundTag> newNbt;

            if (!nbt) {
                newNbt = gstd::unique_ptr(new CompoundTag(""));
                nbt.borrow_from(newNbt);
            }

            gstd::reference_ptr blockEntityTag = item.mNbt->getCompound(Tag::BlockEntityTag);
            if (!blockEntityTag) {
                CompoundTag::Tags line;
                line.reserve(4);

                if (!line1.empty())
                    line.push_back({ Tag::Text1, gstd::unique_ptr(new StringTag("")) });
                if (!line2.empty())
                    line.push_back({ Tag::Text2, gstd::unique_ptr(new StringTag("")) });
                if (!line3.empty())
                    line.push_back({ Tag::Text3, gstd::unique_ptr(new StringTag("")) });
                if (!line4.empty())
                    line.push_back({ Tag::Text4, gstd::unique_ptr(new StringTag("")) });

                gstd::unique_ptr newBlockEntityTag(new CompoundTag(Tag::BlockEntityTag, std::move(line)));
                blockEntityTag.borrow_from(newBlockEntityTag);
                nbt->put({ Tag::BlockEntityTag, std::move(newBlockEntityTag) });
            }

            auto Set = [blockEntityTag](const gstd::string &tagName, const gstd::string &lineText) {
                if (!lineText.empty()) {
                    if (gstd::reference_ptr textTag = blockEntityTag->getString(tagName)) {
                        textTag->mString = lineText;
                        return;
                    }
                    blockEntityTag->put({ tagName, gstd::unique_ptr(new StringTag(lineText)) });
                }
            };

            Set(Tag::Text1, line1);
            Set(Tag::Text2, line2);
            Set(Tag::Text3, line3);
            Set(Tag::Text4, line4);

            if (item.mNbt.get() != nbt.get())
                item.mNbt = std::move(newNbt);
        }
    }

    void setMonsterSpawnerTag(ItemInstance &item, EntityId id, u16 delay, u16 minSpawnDelay, u16 maxSpawnDelay, u16 spawnCount, u16 maxNearbyEntities, u16 requiredPlayerRange, u16 spawnRange)
    {
        checkSafe();

        if (item.mItem->mId == ItemId::mob_spawner) {
            gstd::reference_ptr<CompoundTag> nbt(item.mNbt);
            gstd::unique_ptr<CompoundTag> newNbt;

            if (!item.mNbt) {
                newNbt = gstd::unique_ptr(new CompoundTag(""));
                nbt.borrow_from(newNbt);
            }

            gstd::reference_ptr blockEntityTag = nbt->getCompound(Tag::BlockEntityTag);

            if (!blockEntityTag) {
                gstd::unique_ptr newBlockEntityTag(new CompoundTag(Tag::BlockEntityTag));
                blockEntityTag.borrow_from(newBlockEntityTag);
                nbt->put({ Tag::BlockEntityTag, std::move(newBlockEntityTag) });
            }

            // BlockEntityTagは他にもTagが入る可能性があるから削除はせず編集する

            if (gstd::reference_ptr entityIdTag = blockEntityTag->getInt(Tag::EntityId))
                entityIdTag->mValue = (int)id;
            else
                blockEntityTag->put({ Tag::EntityId, gstd::unique_ptr(new IntTag((int)id)) });

            auto SetShort = [blockEntityTag](const gstd::string &tagName, short value) {
                if (gstd::reference_ptr tag = blockEntityTag->getShort(tagName))
                    tag->mValue = value;
                else
                    blockEntityTag->put({ tagName, gstd::unique_ptr(new ShortTag(value)) });
            };

            SetShort(Tag::Delay, delay);
            SetShort(Tag::MinSpawnDelay, minSpawnDelay);
            SetShort(Tag::MaxSpawnDelay, maxSpawnDelay);
            SetShort(Tag::SpawnCount, spawnCount);
            SetShort(Tag::MaxNearbyEntities, maxNearbyEntities);
            SetShort(Tag::RequiredPlayerRange, requiredPlayerRange);
            SetShort(Tag::SpawnRange, spawnRange);

            if (item.mNbt.get() != nbt.get())
                item.mNbt = std::move(newNbt);
        }
    }

    void setUnbreakableTag(ItemInstance &item)
    {
        checkSafe();

        gstd::reference_ptr<CompoundTag> nbt(item.mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!item.mNbt) {
            newNbt = gstd::unique_ptr(new CompoundTag(""));
            nbt.borrow_from(newNbt);
        }

        gstd::reference_ptr unbreakableTag = item.mNbt->getByte(Tag::Unbreakable);
        if (!unbreakableTag) {
            gstd::unique_ptr newUnbreakableTag(new ByteTag(0));
            unbreakableTag.borrow_from(newUnbreakableTag);
            nbt->put({ Tag::Unbreakable, std::move(newUnbreakableTag) });
        }

        unbreakableTag->mValue = 1;

        if (item.mNbt.get() != nbt.get())
            item.mNbt = std::move(newNbt);
    }

    void removeUnbreakableTag(ItemInstance &item)
    {
        checkSafe();

        if (item.mNbt && item.mNbt->contains(Tag::Unbreakable))
            item.mNbt->remove(Tag::Unbreakable);
    }

    void setCustomColorTag(ItemInstance &item, const BColor &color)
    {
        checkSafe();

        gstd::reference_ptr<CompoundTag> nbt(item.mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!item.mNbt) {
            newNbt = gstd::unique_ptr(new CompoundTag(""));
            nbt.borrow_from(newNbt);
        }

        gstd::reference_ptr customColorTag = item.mNbt->getInt(Tag::customColor);
        if (!customColorTag) {
            gstd::unique_ptr newCustomColorTag(new IntTag(0));
            customColorTag.borrow_from(newCustomColorTag);
            nbt->put({ Tag::Unbreakable, std::move(newCustomColorTag) });
        }

        customColorTag->mValue = color.toInt();

        if (item.mNbt.get() != nbt.get())
            item.mNbt = std::move(newNbt);
    }

    void removeCustomColorTag(ItemInstance &item)
    {
        checkSafe();

        if (item.mNbt && item.mNbt->contains(Tag::customColor))
            item.mNbt->remove(Tag::customColor);
    }

    void setItemsTag(ItemInstance &item, const std::vector<std::pair<u8, ItemInstance>> &items)
    {
        checkSafe();

        gstd::reference_ptr<CompoundTag> nbt(item.mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!item.mNbt) {
            newNbt = gstd::unique_ptr(new CompoundTag(""));
            nbt.borrow_from(newNbt);
        }

        if (nbt->contains(Tag::Items))
            nbt->remove(Tag::Items);

        CompoundTag::Tags tags;
        for (auto &item : items) {
            tags.push_back({ Tag::id, gstd::unique_ptr(new ShortTag((short)item.second.mItem->mId)) });
            tags.push_back({ Tag::Count, gstd::unique_ptr(new ByteTag(item.second.mCount)) });
            tags.push_back({ Tag::Damage, gstd::unique_ptr(new ShortTag(item.second.mDataValue)) });
            tags.push_back({ Tag::Slot, gstd::unique_ptr(new ByteTag(item.first)) });

            if (item.second.mNbt) {
                gstd::unique_ptr copy(item.second.mNbt->copy());
                if (copy)
                    tags.push_back({ Tag::tag, std::move(copy) });
            }
        }

        ListTag::List list;
        list.push_back(gstd::unique_ptr(new CompoundTag(Tag::Item, std::move(tags))));
        nbt->put({ Tag::Items, gstd::unique_ptr(new ListTag(std::move(list))) });

        if (item.mNbt.get() != nbt.get())
            item.mNbt = std::move(newNbt);
    }

    void setItemsTag(ItemInstance &item, std::vector<std::pair<u8, gstd::unique_ptr<CompoundTag>>> &&items)
    {
        checkSafe();

        gstd::reference_ptr<CompoundTag> nbt(item.mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!item.mNbt) {
            newNbt = gstd::unique_ptr(new CompoundTag(""));
            nbt.borrow_from(newNbt);
        }

        if (nbt->contains(Tag::Items))
            nbt->remove(Tag::Items);

        ListTag::List list;
        for (auto &item : items) {
            gstd::unique_ptr copy(item.second->copy());
            if (copy)
                ((CompoundTag *)copy.get())->put({ Tag::Slot, gstd::unique_ptr(new ByteTag(item.first)) });

            list.push_back(std::move(copy));
        }

        nbt->put({ Tag::Items, gstd::unique_ptr(new ListTag(std::move(list))) });

        if (item.mNbt.get() != nbt.get())
            item.mNbt = std::move(newNbt);
    }

    void setItemFrameTag(ItemInstance &item, const ItemInstance &in, u8 rotation)
    {
        checkSafe();

        if (item.mItem->mId == ItemId::frame) {
            gstd::reference_ptr<CompoundTag> nbt(item.mNbt);
            gstd::unique_ptr<CompoundTag> newNbt;

            if (!item.mNbt) {
                newNbt = gstd::unique_ptr(new CompoundTag(""));
                nbt.borrow_from(newNbt);
            }

            gstd::reference_ptr blockEntityTag = nbt->getCompound(Tag::BlockEntityTag);
            if (!blockEntityTag) {
                gstd::unique_ptr newBlockEntityTag(new CompoundTag(Tag::BlockEntityTag));
                blockEntityTag.borrow_from(newBlockEntityTag);
                nbt->put({ Tag::BlockEntityTag, std::move(newBlockEntityTag) });
            }

            if (blockEntityTag->contains(Tag::Item))
                blockEntityTag->remove(Tag::Item);

            CompoundTag::Tags itemData;
            itemData.push_back({ Tag::id, gstd::unique_ptr(new ShortTag((short)in.mItem->mId)) });
            itemData.push_back({ Tag::Count, gstd::unique_ptr(new ByteTag(in.mCount)) });
            itemData.push_back({ Tag::Damage, gstd::unique_ptr(new ShortTag(in.mDataValue)) });

            if (in.mNbt) {
                gstd::unique_ptr copy(in.mNbt->copy());
                if (copy)
                    itemData.push_back({ Tag::tag, std::move(copy) });
            }

            blockEntityTag->put({ Tag::Item, gstd::unique_ptr(new CompoundTag(Tag::Item, std::move(itemData))) });

            gstd::reference_ptr<ByteTag> rotationTag = blockEntityTag->getByte(Tag::ItemRotation);
            if (!rotationTag) {
                gstd::unique_ptr newRotationTag(new ByteTag(0));
                rotationTag.borrow_from(newRotationTag);
                blockEntityTag->put({ Tag::ItemRotation, std::move(newRotationTag) });
            }

            rotationTag->mValue = rotation;

            if (item.mNbt.get() != nbt.get())
                item.mNbt = std::move(newNbt);
        }
    }
}    // namespace MC3DSPluginFramework::NbtEditor