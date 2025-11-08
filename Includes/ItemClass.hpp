#ifndef ITEMCLASS_HPP
#define ITEMCLASS_HPP

#include "Function.hpp"
#include "GameEnums.hpp"

namespace MC3DSPluginFramework {
class Item {
  public:
    static Item *GetInstance(ItemID id);

    u8 &MaxStack(void);
    const char *AtlasName(void);
    ItemID GetID(void);
    const char *Name(void);
    u16 &MaxDurability(void);
    bool &EnchantEffect(void);
    u8 GetBlockID(void);

  private:
    static inline Item **Instances = (Item **)0xB0CEF0;

    u32 unk1;
    u8 maxStack;
    u8 unk2[3];
    char *atlasName;
    u32 unk3;
    u16 unk4;
    ItemID itemID;
    char *name1;
    char *name2;
    u8 unk5[2];
    u16 durability;
    bool enchantEffect;
    u8 unk6[2];
    bool disablePlacement;
    u32 unk7[2];
    u8 blockID;
    bool canEat;
    u8 unk8[2];
    u32 unk9[5];
};
}    // namespace MC3DSPluginFramework

#endif