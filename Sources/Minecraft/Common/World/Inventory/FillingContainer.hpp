#pragma once

#include "Container.hpp"

namespace MC3DSPluginFramework
{
    class Player;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\inventory\\FillingContainer.cpp"
    class FillingContainer : public Container
    {
    public:
        int getLinkedSlotsCount()
        {
            return mLinkedSlots.size();
        }

    public:
        ~FillingContainer() override;

        ItemInstance &getItem(int idx) override;
        void          setItem(int slot, const ItemInstance &set) override;

        // FUN_0x316FF8
        // +0x20
        void   subItem(int slot, u8 count) override;
        size_t getContainerSize() override;
        int    vFunc0x2C() override;
        void   vFunc0x34() override;

        // FUN_0x317650
        virtual bool vFunc0x68(ItemInstance &p1, int p2);

        // FUN_0x6E05A8
        virtual bool vFunc0x6C(ItemInstance &p1);

        virtual int getNextEmptySlot();

        virtual void vFunc0x74() = delete;

        // FUN_0x318288
        virtual void vFunc0x78(int slot);

        // FUN_0x3179D8
        virtual void vFunc0x7C(void *p1);

        virtual void vFunc0x80();

        // FUN_0x6E025C
        // +0x84
        virtual void getEmptySlotCount();

    protected:
        // 0x9B33E4

        gstd::vector<ItemInstance> mItems;    // +0x48
        Player                    *mPlayer;    // +0x54
        gstd::vector<int>          mLinkedSlots;    // +0x58
    };
}    // namespace MC3DSPluginFramework