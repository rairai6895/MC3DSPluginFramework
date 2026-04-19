#pragma once

#include "../../Inventory/Inventory.hpp"
#include "../../Item/ItemInstance.hpp"
#include "Minecraft/Common/Util/Util.hpp"

namespace MC3DSPluginFramework
{
    class ContainerSizeChangeListener
    {
        USE_GAME_ALLOCATOR
    public:
        virtual void containerSizeChanged(int p1);    // +0x0
        virtual ~ContainerSizeChangeListener();    // +0x4
    };

    class ContainerContentChangeListener
    {
        USE_GAME_ALLOCATOR
    public:
        virtual ~ContainerContentChangeListener();    // +0x0
        virtual void vFunc0x8() = delete;
    };

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\entity\\player\\PlayerInventoryProxy.cpp"
    class PlayerInventoryProxy : public ContainerSizeChangeListener, public ContainerContentChangeListener
    {
        USE_GAME_ALLOCATOR
    public:
        PlayerInventoryProxy(gstd::unique_ptr<Inventory> inventory);    // FUN_0x3F9704
        void containerSizeChanged(int p1) override;
        ~PlayerInventoryProxy() override = default;    // FUN_0x3F9760
        virtual void vFunc0xC()          = delete;

        int                          getSelectedSlot() const;
        void                         changeSelectedSlot(int set);
        ItemInstance                &getItem(int idx, int selectedContainerId);
        Inventory                   *getInventory() const;
        gstd::vector<ItemInstance *> getSlots() const;
        int                          getHotbarSize() const;

    private:
        // 0x9BF364
        // 0x9BF37C

        int                                  mSelectedInventorySlot;    // +0x8
        ItemInstance                         m0xC;
        u8                                   mSelectedContainerId;    // +0x3C
        gstd::unique_ptr<Inventory>          mInventory;    // +0x40
        gstd::vector<ItemInstance>           m0x44;
        BoxedPtr::Weak<gstd::type_unknown<>> mHudContainerManager;    // +0x50
    };
}    // namespace MC3DSPluginFramework