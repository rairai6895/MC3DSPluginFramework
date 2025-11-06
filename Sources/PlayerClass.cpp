#include "PlayerClass.hpp"

namespace MC3DSPluginFramework {

Entity *Player::GetInstance(void) {
    if (GameSystem *system = GameSystem::GetInstance()) {
        if (u32 param = *(u32 *)system->Offset(0x8))
            return *(Entity **)(**(u32 **)(param + 0xC0) + 0x30);    // FUN_0x25118C
    }
    return nullptr;
}

bool Player::IsLoaded(void) {
    return GetInstance();
}

void *Player::GetAbility(Ability id) {
    if (Entity *player = Player::GetInstance())
        return (void *)(Function<u32>(0x735384)(player->Offset(0x1160), id) + 0x4);

    return 0;
}

Player::AbilityState *Player::GetAbilityState(void) {
    if (Entity *player = GetInstance()) {
        static AbilityState state{
            *(GameModes *)(player->Offset(0x196C)),
            *(bool *)GetAbility(Ability::CanFly),
            *(bool *)GetAbility(Ability::IsInvincible),
            *(bool *)GetAbility(Ability::IsFlying),
            *(bool *)GetAbility(Ability::InfiniteItems),
            *(bool *)GetAbility(Ability::Lightning),
            *(float *)GetAbility(Ability::FlySpeed),
            *(float *)GetAbility(Ability::WalkSpeed),
            *(bool *)GetAbility(Ability::NoClip),
        };
        return &state;
    }
    return nullptr;
}

bool Player::IsJumping(void) {
    if (GameSystem *system = GameSystem::GetInstance())
        return *(bool *)(system->GetController() + 0x4D);

    return false;
}

void Player::IsJumping(bool jumping) {
    if (GameSystem *system = GameSystem::GetInstance())
        *(bool *)(system->GetController() + 0x4D) = jumping;
}

bool Player::IsSneaking(void) {
    if (GameSystem *system = GameSystem::GetInstance())
        return *(bool *)(system->GetController() + 0x4E);

    return false;
}

void Player::IsSneaking(bool sneak) {
    if (GameSystem *system = GameSystem::GetInstance())
        *(bool *)(system->GetController() + 0x4E) = sneak;
}

u32 Player::SprintDelay(void) {
    if (Entity *player = GetInstance())
        return *(u32 *)player->Offset(0x1A28);

    return 0;
}

/*
void Player::UpdateSprintDelay(void) {
    Function<u32>(0x198334)(this);
}
*/

void Player::SprintDelay(u32 delay) {
    if (Entity *player = GetInstance())
        *(u32 *)player->Offset(0x1A28) = delay;
}

bool Player::IsInUnderWater(void) {
    if (u32 BaseAddr = *(u32 *)0xA32244)
        return *(bool *)(BaseAddr + 0x381);

    return false;
}

void Player::IsInUnderWater(const bool flag) {
    if (u32 BaseAddr = *(u32 *)0xA32244)
        *(bool *)(BaseAddr + 0x380) = flag;
}

void Player::Teleport(const Vec3_Int &pos) {
    if (Entity *player = GetInstance()) {
        u32 BaseAddr      = player->Offset();
        Vec3_Float coord1 = {};
        Vec3_Float coord2 = {};
        Vec3_Float coord3 = {};

        *(float *)(BaseAddr + 0x1C0) = pos.x + 0.5f;
        *(float *)(BaseAddr + 0x288) = pos.x + 0.2f;
        *(float *)(BaseAddr + 0x294) = pos.x + 0.8f;

        *(float *)(BaseAddr + 0x1C4) = pos.y + 0.62f;
        *(float *)(BaseAddr + 0x28C) = pos.y - 1;
        *(float *)(BaseAddr + 0x298) = pos.y + 0.8f;

        *(float *)(BaseAddr + 0x1C8) = pos.z + 0.5f;
        *(float *)(BaseAddr + 0x290) = pos.z + 0.2f;
        *(float *)(BaseAddr + 0x29C) = pos.z + 0.8f;

        player->Velocity() = {};
    }
}

}    // namespace MC3DSPluginFramework