#include "Spawn.hpp"

namespace MC3DSPluginFramework {
namespace Spawn {

Entity *Item(const Vec3_Float &pos, const SlotData &item) {
    if (Entity *player = Player::GetInstance())
        return Function<Entity *>(0x645218)(*(u32 *)player->GetWorld()->Offset(0x1D0), *(u32 *)player->Offset(0x210), &item, player, &pos, 0);
    return nullptr;
}

Entity *Mob(const Vec3_Float &pos, const EntityID id) {
    if (Entity *player = Player::GetInstance()) {
        u32 data1    = Function<u32>(0x14C484)(id, 0);
        u32 data2[3] = {};
        u32 unk      = 0;
        Function<void>(0x48B3A4)(data2, 0x98A38C, &data1, &unk);
        return Function<Entity *>(0x6450A0)(*(u32 *)player->GetWorld()->Offset(0x1D0), *(u32 *)player->Offset(0x210), data2, 0, &pos);
    }
    return nullptr;
}

Entity *Xp(const Vec3_Float &pos, u32 amount) {
    if (Entity *player = Player::GetInstance()) {
        Entity *e;
        u32 data1[2];
        Function<void>(0x48AF00)(data1, EntityID::XPOrb);
        Function<void>(0x213254)(&e, data1, 0, &pos, 0xA35268, 0);
        if (e) {
            Function<void>(0x214A18)(e, amount);
            return Function<Entity *>(0x5CE734)(player->GetWorld(), *(u32 *)player->Offset(0x210), &e);
        }
    }
    return nullptr;
}

Entity *Thunder(const Vec3_Float &pos) {
    if (Entity *player = Player::GetInstance()) {
        Entity *e;
        u32 data1[2];
        Function<void>(0x48AF00)(data1, EntityID::Thunder);
        Function<void>(0x213254)(&e, data1, 0, &pos, 0xA35268, 0);
        if (e)
            return Function<Entity *>(0x5C8358)(player->GetWorld(), *(u32 *)Player::GetInstance()->Offset(0x210), &e);
    }
    return nullptr;
}

void Egg(const Vec3_Float &pos, const SlotData &egg) {
    if (Entity *player = Player::GetInstance())
        Function<void>(0x36BB18)(*(u32 *)player->Offset(0x210), 0, &pos, 0, &egg);
}

}    // namespace Spawn
}    // namespace MC3DSPluginFramework