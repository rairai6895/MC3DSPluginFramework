#include "Minecraft/Common/World/Entity/Player/Player.hpp"

namespace MC3DSPluginFramework
{

    Entity *Player::GetInstance(void)
    {
        if (EntityRenderDispatcher *instance = EntityRenderDispatcher::getInstance())
            return instance->getClientInstance()->getLocalPlayer();

        return nullptr;
    }

    bool Player::IsLoaded(void)
    {
        return GetInstance();
    }

    bool Player::IsJumping(void)
    {
        if (EntityRenderDispatcher *instance = EntityRenderDispatcher::getInstance())
            return *(bool *)((u32)(instance->getClientInstance()->getController()->mUnk2) + 0x4D);

        return false;
    }

    void Player::IsJumping(bool jumping)
    {
        if (EntityRenderDispatcher *instance = EntityRenderDispatcher::getInstance())
            *(bool *)((u32)(instance->getClientInstance()->getController()->mUnk2) + 0x4D) = jumping;
    }

    bool Player::IsSneaking(void)
    {
        if (EntityRenderDispatcher *instance = EntityRenderDispatcher::getInstance())
            return *(bool *)((u32)(instance->getClientInstance()->getController()->mUnk2) + 0x4E);

        return false;
    }

    void Player::IsSneaking(bool sneak)
    {
        if (EntityRenderDispatcher *instance = EntityRenderDispatcher::getInstance())
            *(bool *)((u32)(instance->getClientInstance()->getController()->mUnk2) + 0x4E) = sneak;
    }

    u32 Player::SprintDelay(void)
    {
        if (Entity *player = GetInstance())
            return *(u32 *)player->Offset(0x1A28);

        return 0;
    }

    /*
    void Player::UpdateSprintDelay(void) {
        Function<u32>(0x198334)(this);
    }
    */

    void Player::SprintDelay(u32 delay)
    {
        if (Entity *player = GetInstance())
            *(u32 *)player->Offset(0x1A28) = delay;
    }

    bool Player::IsInUnderWater(void)
    {
        if (u32 Addr = *(u32 *)0xA32244)
            return *(bool *)(Addr + 0x381);

        return false;
    }

    void Player::IsInUnderWater(const bool flag)
    {
        if (u32 Addr = *(u32 *)0xA32244)
            *(bool *)(Addr + 0x380) = flag;
    }

    void Player::Teleport(const Vec3_Int &pos)
    {
        if (Entity *player = GetInstance()) {
            u32 Addr = player->Offset();

            *(float *)(Addr + 0x1C0) = pos.x + 0.5f;
            *(float *)(Addr + 0x288) = pos.x + 0.2f;
            *(float *)(Addr + 0x294) = pos.x + 0.8f;

            *(float *)(Addr + 0x1C4) = pos.y + 0.62f;
            *(float *)(Addr + 0x28C) = pos.y - 1;
            *(float *)(Addr + 0x298) = pos.y + 0.8f;

            *(float *)(Addr + 0x1C8) = pos.z + 0.5f;
            *(float *)(Addr + 0x290) = pos.z + 0.2f;
            *(float *)(Addr + 0x29C) = pos.z + 0.8f;

            player->Velocity() = {};
        }
    }

}    // namespace MC3DSPluginFramework