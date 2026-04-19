#pragma once

#include "../Item/ItemInstance.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Container
    {
    public:
        virtual ~Container();

        // FUN_0x66A958
        virtual void vFunc0x8();

        // FUN_0x66ABEC
        virtual void vFunc0xC();

        virtual ItemInstance &getItem(int idx) = 0;    // +0x10

        // FUN_0x66AE40
        virtual void vFunc0x14(ItemInstance &p1);

        // FUN_0x66A838
        virtual bool vFunc0x18();

        virtual void setItem(int slot, const ItemInstance &item) = 0;    // +0x1C

        virtual void subItem(int slot, u8 count) = 0;    // +0x20

        // FUN_0x6692F8
        virtual void vFunc0x24();

        virtual size_t getContainerSize() = 0;    // +0x28

        virtual int vFunc0x2C() = 0;

        virtual void vFunc0x30() = 0;

        virtual void vFunc0x34() = 0;

        // FUN_0x7381C8
        // +0x38
        virtual gstd::vector<ItemInstance> getSlotCopies();

        // FUN_0x7384E4
        // +0x3C
        virtual gstd::vector<ItemInstance *> getSlots();

        virtual void vFunc0x40() = delete;

        virtual void vFunc0x44() = delete;

        // FUN_0x7381C0
        virtual int vFunc0x48()
        {
            return 1;
        }

        // FUN_0x7384DC
        virtual int vFunc0x4C()
        {
            return 1;
        }

        // FUN_0x669A94
        virtual void vFunc0x50(int slot);

        // FUN_0x6699D4
        virtual void vFunc0x54();

        // FUN_0x66991C
        virtual void vFunc0x58(const gstd::string &p1)
        {
            m0x44 = 1;
            m0x40 = p1;
        }

        // FUN_0x7384D4
        virtual u8 vFunc0x5C()
        {
            return m0x44;
        }

        virtual void vFunc0x60() = delete;

        virtual void vFunc0x64() = delete;

    protected:
        // 0x9D3570

        u8                                                    m0x4;
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> m0x8;
        gstd::map<gstd::type_unknown<>, gstd::type_unknown<>> m0x24;
        gstd::string                                          m0x40;
        u8                                                    m0x44;
    };
}    // namespace MC3DSPluginFramework