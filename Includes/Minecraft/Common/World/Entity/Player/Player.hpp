#pragma once

#include "Minecraft/Common/Client/Renderer/Entity/EntityRenderDispatcher.hpp"
#include "Minecraft/Common/World/Entity/EntityClass.hpp"
#include "Minecraft/Common/World/Entity/Mob.hpp"

namespace MC3DSPluginFramework
{
    class Player
    {
    public:
        static Entity *GetInstance(void);
        static bool IsLoaded(void);
        static bool IsJumping(void);
        static void IsJumping(bool jumping);
        static bool IsSneaking(void);
        static void IsSneaking(bool sneak);
        static u32 SprintDelay(void);
        static void SprintDelay(u32 delay);
        static bool IsInUnderWater(void);
        static void IsInUnderWater(const bool flag);
        static void Teleport(const Vec3_Int &pos);

        void setPlayerGameType(GameModes mode)
        {
            reinterpret_cast<void (*)(Player *, GameModes)>(0x601900)(this, mode);
        }

        void prepareRegion(u32 unknown)
        {
            reinterpret_cast<void (*)(Player *, u32)>(0x600044)(this, unknown);
        }

        void *getAgent()
        {
            return reinterpret_cast<void *(*)(Player *)>(0x727A64)(this);
        }

        void sendEventPacket(u32 unknown)
        {
            reinterpret_cast<void (*)(Player *, u32)>(0x726D6C)(this, unknown);
        }

        void eat(const ItemInstance &item)
        {
            reinterpret_cast<void (*)(Player *, const ItemInstance &)>(0x605820)(this, item);
        }

    private:
    };

    // vtable 0x99C31C
    class _Player : public Mob
    {
    public:
        // void initializeComponents(u32 unknown) override;

        ~_Player() override;

    private:
    };
}    // namespace MC3DSPluginFramework