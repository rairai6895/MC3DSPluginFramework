#include "ItemClass.hpp"

namespace MC3DSPluginFramework {

Item *Item::GetInstance(ItemID id) {
    return Instances[(u16)id];
}

u8 &Item::MaxStack(void) {
    return maxStack;
}

const char *Item::AtlasName(void) {
    return atlasName;
}

ItemID Item::GetID(void) {
    return itemID;
}

const char *Item::Name(void) {
    return name2;
}

u16 &Item::MaxDurability(void) {
    return durability;
}

bool &Item::EnchantEffect(void) {
    return enchantEffect;
}

u8 Item::GetBlockID(void) {
    return blockID;
}

}