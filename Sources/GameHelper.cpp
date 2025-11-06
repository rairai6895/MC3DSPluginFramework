#include "GameHelper.hpp"
#include "Function.hpp"
#include "GameSystem.hpp"
#include "Inventory.hpp"
#include "PlayerClass.hpp"
#include "WorldClass.hpp"
#include <algorithm>
#include <cstring>

namespace MC3DSPluginFramework {
namespace GameHelper {

bool Eat(int speed) {
    if (const SlotData *inv = Inventory::Get(Inventory::HeldSlot()))
        return Function<bool>(0x600798)(Player::GetInstance(), inv, std::clamp<int>(0x20 - speed, 1, 0x20));
    return false;
}

bool UseBow(bool fullCharge) {
    if (const SlotData *inv = Inventory::Get(Inventory::HeldSlot()))
        if (inv->CheckName("bow"))
            return Function<bool>(0x600798)(Player::GetInstance(), inv, fullCharge ? 0x1192C : 0x11940);
    return false;
}

void ShotArrow(u32 charge) {
    // 0~20
    if (const Entity *player = Player::GetInstance())
        Function<void>(0x72AA94)(*(u32 *)0xB0D304, player->Offset(0x18B4), player, 0x11940 - charge);
}

bool IsMultiPlayer(void) {
    if (const Entity *player = Player::GetInstance())
        return Function<bool>(0x720908)(player->GetWorld());
    return false;
}

/*
bool Enchanting(SlotData *slot, SlotData *enchantBook) {
    struct EnchantArg {
        u32 val1[8]   = {};
        SlotData item = {};    // スタックを使いまわしてる構造で一時的にスロットデータを使っているため必要
        u32 val2[7]   = {};    // val1と同じ構造？を使っていてSlotDataに重なってるけどサイズが足りないので追加
    };

    EnchantArg EncArg{};
    auto FUN_0x6B25EC = Function<void>(0x6B25EC);
    FUN_0x6B25EC(&EncArg, enchantBook);
    FUN_0x6B25EC(&EncArg.item.enchant, slot);                                // フラグを立ててくれるっぽい？(鋭さなら0x10)
    bool check = Function<bool>(0x1D0354)(&EncArg.item.enchant, &EncArg);    // 付与できるなら1が返るので必要なデータの構築とチェックを同時にしてくれてるっぽい
    if (check)
        Function<void>(0x1D1670)(slot, &EncArg.item.enchant);
    return check;
}
*/

/*
void SpawnEgg(const Vec3_Float &pos, u8 id) {
    if (const Entity *player = Player::GetInstance()) {
        SlotData egg{};
        egg.dataValue = id;
        Function<void>(0x36BB18)(*(u32 *)player->Offset(0x210), 0, &pos, 0, &egg);
    }
}

Entity *SpawnItem(const Vec3_Float &pos, const SlotData *item) {
    if (const Entity *player = Player::GetInstance())
        if (const World *world = World::GetInstance())
            return Function<Entity *>(0x645218)(*(u32 *)world->Offset(0x1D0), *(u32 *)player->Offset(0x210), item, player, &pos, 0);
    return nullptr;
}

Entity *SpawnMob(const Vec3_Float &pos, EntityID id) {
    Entity *e;
    u32 data1[2];
    Function<void>(0x48AF00)(data1, id);
    Function<void>(0x213254)(&e, data1, 0, &pos, 0xA35268, 0);
    if (e)
        return Function<Entity *>(0x5CE734)(World::GetInstance(), *(u32 *)Player::GetInstance()->Offset(0x210), &e);
    return nullptr;
}

Entity *SpawnXP(const Vec3_Float &pos, u32 amount) {
    Entity *e;
    u32 data1[2];
    Function<void>(0x48AF00)(data1, EntityID::XPOrb);
    Function<void>(0x213254)(&e, data1, 0, &pos, 0xA35268, 0);
    if (e) {
        Function<void>(0x214A18)(e, amount);
        return Function<Entity *>(0x5CE734)(World::GetInstance(), *(u32 *)Player::GetInstance()->Offset(0x210), &e);
    }
    return nullptr;
}

Entity *SpawnThunder(const Vec3_Float &pos) {
    Entity *e;
    u32 data1[2];
    Function<void>(0x48AF00)(data1, EntityID::Thunder);
    Function<void>(0x213254)(&e, data1, 0, &pos, 0xA35268, 0);
    if (e)
        return Function<Entity *>(0x5C8358)(World::GetInstance(), *(u32 *)Player::GetInstance()->Offset(0x210), &e);
    return nullptr;
}
*/

/*
void Vec3_IntToFloat(Vec3_Float &res, const Vec3_Int &vecInt) {
    Function<void>(0x582C7C)(&res, &vecInt);
}
*/

/*
int GetLevel(void) {
    if (const Entity *player = Player::GetInstance())
        return Function<int>(0x726998)(player);
    return 0;
}
*/

void Equip(Entity *entity, SlotData &item) {
    Function<void>(0x735B50)(item.itemdata, &item, entity);
}

bool IsWearableItem(const SlotData &item) {
    return Function<bool>(0x6B15A0)(&item);
}

bool IsEquiped(Entity *entity, const SlotData &item) {
    return Function<bool>(0x6B2954)(entity->Offset(0xF70), &item);
}

/*
float HandUpdate(void) {
    u32 param = *(u32 *)(GameSystem::GetInstance()->Offset(0x14));
    return Function<float>(0x39A7C0)(param);    // 戻り値はモーションの現在値(float)
}
*/

/*
bool HasItemChanged(void) {
    if (const Entity *player = Player::GetInstance()) {
        SlotData *RealTimeSlot = Function<SlotData *>(0x726D50)(player);
        SlotData *checkItem    = (SlotData *)(*(u32 *)((u32)GameSystem::GetInstance() + 0x14) + 0x40);
        return !Function<bool>(0x6B2B4C)(RealTimeSlot, checkItem);
    }
    return false;
}
*/

/*
u32 GetU32VectorData(std::vector<u32> vec, size_t index) {
    return Function<u32>(0x6F2CEC)(vec, index);
}
*/

gstd::vector<Entity *> *GetEntityList(void) {
    /*
    if (auto addr = *(u32 *)(0xA32244))
        return (gstd::vector<Entity *> *)(addr + 0x110);
    */

    if (GameSystem *system = GameSystem::GetInstance()) {
        u32 _0x341E84E4 = *(u32 *)(*(u32 *)(system->Offset(0xC)) + 0x18);
        u32 *ptr        = (u32 *)(_0x341E84E4 + 0x48);
        return (gstd::vector<Entity *> *)(ptr[1] + 0x744);
    }
    return nullptr;
}

bool ChangeCoordsText(const gstd::string &str) {
    if (GameSystem *system = GameSystem::GetInstance()) {
        u32 _0x341E84E4 = *(u32 *)(*(u32 *)(system->Offset(0xC)) + 0x18);
        if (gstd::vector<u32> *vec = *(gstd::vector<u32> **)(_0x341E84E4 + 0x6C))
            if (u32 instance = *(u32 *)((*vec)[4] + 0x1F8))
                return Function<bool>(0x33E5E0)(instance, str);
    }
    return false;
}

gstd::string GetEntityName(EntityID id) {
    gstd::string res;
    Function<void>(0x1496EC)(res, id);
    return res;
}

gstd::vector<size_t> *GetItemCooldowns(void) {
    if (Entity *player = Player::GetInstance())
        return (gstd::vector<size_t> *)player->Offset(0x1988);

    return nullptr;
}

size_t GetChorusFruitCooldown(void) {
    if (gstd::vector<size_t> *vec = GetItemCooldowns())
        return (*vec)[0];

    return 0;
}

bool SetChorusFruitCooldown(size_t cooldown) {
    if (gstd::vector<size_t> *vec = GetItemCooldowns()) {
        (*vec)[0] = cooldown;
        return true;
    }
    return false;
}

size_t GetEnderpearlCooldown(void) {
    if (gstd::vector<size_t> *vec = GetItemCooldowns())
        return (*vec)[1];

    return 0;
}

bool SetEnderpearlCooldown(size_t cooldown) {
    if (gstd::vector<size_t> *vec = GetItemCooldowns()) {
        (*vec)[1] = cooldown;
        return true;
    }
    return false;
}

/*
void *GameHelper::Test(void) {                            // GetScreen?
    void *mem = Function(0x11493C).Call<void *>(0xA8);    // malloc
    void *buf1, *buf2;
    Function(0x1A19A8).Call<void>(mem, buf1, buf2);    // settingData
    return mem;
}
*/

}    // namespace GameHelper
}    // namespace MC3DSPluginFramework