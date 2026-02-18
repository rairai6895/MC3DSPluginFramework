#include "HookEx/HookEx.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include <types.h>

namespace MC3DSPluginFramework
{

    ItemInstance &ItemInstance::operator=(const ItemInstance &other)
    {
        if (this != &other) {
            gstd::unique_ptr<CompoundTag> tmp(mNbt.get());
            reinterpret_cast<void (*)(ItemInstance *, const ItemInstance &)>(0x1D2768)(this, other);
        }
        return *this;
    }

    ItemInstance &ItemInstance::operator=(ItemInstance &&other) noexcept
    {
        if (this != &other) {
            gstd::unique_ptr<CompoundTag> tmp(mNbt.get());
            memcpy(this, &other, sizeof(ItemInstance));
            memset(&other, 0, sizeof(ItemInstance));
        }
        return *this;
    }

    bool ItemInstance::isEnchanted(void) const
    {
        if (mNbt)
            if (gstd::reference_ptr enchTag = mNbt->getList(Tag::ench))
                return enchTag->mList.size();

        return false;
    }

    gstd::vector<EnchantStatus> ItemInstance::getEnchants(void) const
    {
        gstd::vector<EnchantStatus> res;

        if (mNbt)
            if (gstd::reference_ptr<ListTag> enchTag = mNbt->getList(Tag::ench)) {
                gstd::vector<gstd::unique_ptr<CompoundTag>> &enchants = *(gstd::vector<gstd::unique_ptr<CompoundTag>> *)&enchTag->mList;

                for (auto &enchant : enchants) {
                    short id = 0, lvl = 0;

                    if (gstd::reference_ptr tag = enchant->getShort(Tag::id))
                        id = tag->mValue;

                    if (gstd::reference_ptr tag = enchant->getShort(Tag::lvl))
                        lvl = tag->mValue;

                    res.push_back({ (EnchantId)id, lvl });
                }
            }

        return res;
    }

    void ItemInstance::setEnchants(const gstd::vector<EnchantStatus> &enchants)
    {
        gstd::reference_ptr<CompoundTag> nbt(mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!nbt) {
            newNbt = gstd::unique_ptr(new CompoundTag(""));
            nbt.borrow_from(newNbt);
        }

        gstd::reference_ptr enchTag(nbt->getList(Tag::ench));
        if (!enchTag) {
            gstd::unique_ptr newEnchTag(new ListTag({}));
            enchTag.borrow_from(newEnchTag);
            nbt->put({ Tag::ench, std::move(newEnchTag) });
        }

        ListTag::List enchList;
        for (auto enchant : enchants) {
            CompoundTag::Tags state;
            state.emplace_back(Tag::id, new ShortTag((short)enchant.id));
            state.emplace_back(Tag::lvl, new ShortTag(enchant.level));
            enchList.push_back(gstd::unique_ptr(new CompoundTag("", std::move(state))));
        }

        enchTag->mList = std::move(enchList);

        if (mNbt.get() != nbt.get())
            mNbt = std::move(newNbt);
    }

    gstd::string ItemInstance::getName(void) const
    {
        return reinterpret_cast<gstd::string (*)(const ItemInstance *)>(0x6B1840)(this);
    }

    gstd::string ItemInstance::getNoFormatedName(void) const
    {
        return reinterpret_cast<gstd::string (*)(const ItemInstance *)>(0x6B2A34)(this);
    }

    gstd::string ItemInstance::getRawName(void) const
    {
        return mItem->getTranslatedName(*this);
    }

    bool ItemInstance::isNamed(void) const
    {
        if (mNbt)
            if (gstd::reference_ptr displayTag = mNbt->getCompound(Tag::display))
                return (bool)displayTag->getString(Tag::Name);

        return false;
    }

    gstd::string ItemInstance::givenName(void) const
    {
        if (mNbt)
            if (gstd::reference_ptr displayTag = mNbt->getCompound(Tag::display))
                if (gstd::reference_ptr nameTag = displayTag->getString(Tag::Name))
                    return nameTag->mString;

        return "";
    }

    void ItemInstance::reName(gstd::string name)
    {
        gstd::reference_ptr<CompoundTag> nbt(mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!nbt) {
            newNbt = gstd::unique_ptr(new CompoundTag(""));
            nbt.borrow_from(newNbt);
        }

        gstd::reference_ptr displayTag(nbt->getCompound(Tag::display));
        if (!displayTag) {
            // Tag::displayにしないと表示バグが起きる
            gstd::unique_ptr newDisplayTag(new CompoundTag(Tag::display));
            displayTag.borrow_from(newDisplayTag);
            nbt->put({ Tag::display, std::move(newDisplayTag) });
        }

        gstd::reference_ptr nameTag(displayTag->getString(Tag::Name));
        if (!nameTag) {
            gstd::unique_ptr newNameTag(new StringTag(""));
            nameTag.borrow_from(newNameTag);
            displayTag->put({ Tag::Name, std::move(newNameTag) });
        }

        if (nameTag->mString != name)
            nameTag->mString = name;

        if (mNbt.get() != nbt.get())
            mNbt = std::move(newNbt);
    }

    size_t ItemInstance::getRepairCost(void) const
    {
        if (mNbt)
            if (gstd::reference_ptr repairCostTag = mNbt->getInt(Tag::RepairCost))
                return repairCostTag->mValue;

        return 0;
    }

    void ItemInstance::setSignTextTag(gstd::string line1, gstd::string line2, gstd::string line3, gstd::string line4)
    {
        //{"CustomName", new StringTag("test")},

        if (mItem->mId == ItemId::sign) {
            gstd::reference_ptr<CompoundTag> nbt(mNbt);
            gstd::unique_ptr<CompoundTag> newNbt;

            if (!nbt) {
                newNbt = gstd::unique_ptr(new CompoundTag(""));
                nbt.borrow_from(newNbt);
            }

            gstd::reference_ptr blockEntityTag = mNbt->getCompound(Tag::BlockEntityTag);
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

            if (mNbt.get() != nbt.get())
                mNbt = std::move(newNbt);
        }
    }

    void ItemInstance::setMonsterSpawnerTag(EntityId id, u16 delay, u16 minSpawnDelay, u16 maxSpawnDelay, u16 spawnCount, u16 maxNearbyEntities, u16 requiredPlayerRange, u16 spawnRange)
    {
        if (mItem->mId == ItemId::mob_spawner) {
            gstd::reference_ptr<CompoundTag> nbt(mNbt);
            gstd::unique_ptr<CompoundTag> newNbt;

            if (!mNbt) {
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

            if (mNbt.get() != nbt.get())
                mNbt = std::move(newNbt);
        }
    }

    void ItemInstance::setUnbreakableTag(void)
    {
        gstd::reference_ptr<CompoundTag> nbt(mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!mNbt) {
            newNbt = gstd::unique_ptr(new CompoundTag(""));
            nbt.borrow_from(newNbt);
        }

        gstd::reference_ptr unbreakableTag = mNbt->getByte(Tag::Unbreakable);
        if (!unbreakableTag) {
            gstd::unique_ptr newUnbreakableTag(new ByteTag(0));
            unbreakableTag.borrow_from(newUnbreakableTag);
            nbt->put({ Tag::Unbreakable, std::move(newUnbreakableTag) });
        }

        unbreakableTag->mValue = 1;

        if (mNbt.get() != nbt.get())
            mNbt = std::move(newNbt);
    }

    void ItemInstance::removeUnbreakableTag(void)
    {
        if (mNbt && mNbt->contains(Tag::Unbreakable))
            mNbt->remove(Tag::Unbreakable);
    }

    void ItemInstance::setCustomColorTag(const BColor &color)
    {
        gstd::reference_ptr<CompoundTag> nbt(mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!mNbt) {
            newNbt = gstd::unique_ptr(new CompoundTag(""));
            nbt.borrow_from(newNbt);
        }

        gstd::reference_ptr customColorTag = mNbt->getInt(Tag::customColor);
        if (!customColorTag) {
            gstd::unique_ptr newCustomColorTag(new IntTag(0));
            customColorTag.borrow_from(newCustomColorTag);
            nbt->put({ Tag::Unbreakable, std::move(newCustomColorTag) });
        }

        customColorTag->mValue = color.toInt();

        if (mNbt.get() != nbt.get())
            mNbt = std::move(newNbt);
    }

    void ItemInstance::removeCustomColorTag(void)
    {
        if (mNbt && mNbt->contains(Tag::customColor))
            mNbt->remove(Tag::customColor);
    }

    void ItemInstance::setItemsTag(const std::vector<std::pair<u8, ItemInstance>> &items)
    {
        gstd::reference_ptr<CompoundTag> nbt(mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!mNbt) {
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

        if (mNbt.get() != nbt.get())
            mNbt = std::move(newNbt);
    }

    void ItemInstance::setItemsTag(std::vector<std::pair<u8, gstd::unique_ptr<CompoundTag>>> &&items)
    {
        gstd::reference_ptr<CompoundTag> nbt(mNbt);
        gstd::unique_ptr<CompoundTag> newNbt;

        if (!mNbt) {
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

        if (mNbt.get() != nbt.get())
            mNbt = std::move(newNbt);
    }

    void ItemInstance::setItemFrameTag(const ItemInstance &item, u8 rotation)
    {
        if (mItem->mId == ItemId::frame) {
            gstd::reference_ptr<CompoundTag> nbt(mNbt);
            gstd::unique_ptr<CompoundTag> newNbt;

            if (!mNbt) {
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
            itemData.push_back({ Tag::id, gstd::unique_ptr(new ShortTag((short)item.mItem->mId)) });
            itemData.push_back({ Tag::Count, gstd::unique_ptr(new ByteTag(item.mCount)) });
            itemData.push_back({ Tag::Damage, gstd::unique_ptr(new ShortTag(item.mDataValue)) });

            if (item.mNbt) {
                gstd::unique_ptr copy(item.mNbt->copy());
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

            if (mNbt.get() != nbt.get())
                mNbt = std::move(newNbt);
        }
    }

}    // namespace MC3DSPluginFramework