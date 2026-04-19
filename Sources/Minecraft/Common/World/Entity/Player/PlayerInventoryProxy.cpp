#include "PlayerInventoryProxy.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x3F9250
    // +0x0
    void PlayerInventoryProxy::containerSizeChanged(int p1)
    {
        reinterpret_cast<void (*)(PlayerInventoryProxy *, int)>(0x3F9250)(this, p1);
    }

    int PlayerInventoryProxy::getSelectedSlot() const
    {
        return mSelectedInventorySlot;
    }

    void PlayerInventoryProxy::changeSelectedSlot(int set)
    {
        mSelectedInventorySlot = set;
    }

    // FUN_0x703998
    ItemInstance &PlayerInventoryProxy::getItem(int idx, int selectedContainerId)
    {
        return selectedContainerId != 0x7B ? mInventory->getItem(idx) : ItemInstance::EMPTY_ITEM;
    }

    // FUN_0x3170DC
    Inventory *PlayerInventoryProxy::getInventory() const
    {
        return mInventory.get();
    }

    // FUN_0x7039BC
    gstd::vector<ItemInstance *> PlayerInventoryProxy::getSlots() const
    {
        return mInventory->getSlots();
    }

    // FUN_0x6E03E4
    int PlayerInventoryProxy::getHotbarSize() const
    {
        return mInventory->getLinkedSlotsCount();
    }

}    // namespace MC3DSPluginFramework