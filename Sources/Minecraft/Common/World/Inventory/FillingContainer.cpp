#include "FillingContainer.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x6E0634
    // +0x10
    ItemInstance &FillingContainer::getItem(int idx)
    {
        if (idx <= -1 || idx > mItems.size())
            return ItemInstance::EMPTY_ITEM;

        if (idx >= mLinkedSlots.size())
            return mItems[idx];

        int i = mLinkedSlots[idx];

        if (i >= mLinkedSlots.size() && i < getContainerSize())
            return getItem(i);

        return ItemInstance::EMPTY_ITEM;
    }

    // FUN_0x318224
    // +0x1C
    void FillingContainer::setItem(int slot, const ItemInstance &set)
    {
        if (slot >= 0 && slot < mItems.size())
        {
            mItems[slot] = set;
            vFunc0x50(slot);
        }
    }

    // FUN_0x6E023C
    // +0x28
    size_t FillingContainer::getContainerSize()
    {
        return mItems.size();
    }

    // FUN_0x6E0060
    int FillingContainer::vFunc0x2C()
    {
        return 0xFE;
    }

    // FUN_0x318714
    void FillingContainer::vFunc0x34()
    {
        return;
    }

    // FUN_0x317554
    // +0x70
    int FillingContainer::getNextEmptySlot()
    {
        for (int i = mLinkedSlots.size(); i < getContainerSize(); ++i)
            if (getItem(i).isNull())
                return i;

        return -1;
    }

    // FUN_0x318134
    void FillingContainer::vFunc0x80()
    {
        return;
    }
}    // namespace MC3DSPluginFramework