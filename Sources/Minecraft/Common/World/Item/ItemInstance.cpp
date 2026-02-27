#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "HookEx/HookEx.hpp"
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

}    // namespace MC3DSPluginFramework