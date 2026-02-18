#pragma once

#include "Minecraft/Common/World/Entity/EntityClass.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Entity;
    class DamageSource
    {
    public:
        enum class Cause : u32 {
            Attack          = 2,
            Projectile      = 3,
            Suffocation     = 4,
            Fall            = 5,
            Fire            = 6,
            FireTick        = 7,
            Lava            = 8,
            Drowning        = 9,
            BlockExplosion  = 10,
            EntityExplosion = 11,
            Void            = 12,
            Magic           = 14,
            Wither          = 15,
            Starve          = 16,
            Anvil           = 17,
            FlyIntoWall     = 21,
        };

        struct MessageMaterial {
            gstd::string descriptionId;
            gstd::vector<gstd::string> params;
        };

        // FUN_0x395B8C
        DamageSource(Cause type) :
            mType(type)
        {
            *(u32 *)this = 0x9B988C;
        }

        void *operator new(size_t) = delete;

        virtual ~DamageSource() = default;
        virtual bool Unknown1(void) { return false; }
        virtual Entity *getAttacker(void) { return nullptr; }
        virtual bool Unknown2(void) { return false; }
        virtual Entity *getProjectile(void) { return nullptr; }
        virtual void Unknown3(void) {}
        virtual MessageMaterial getMessageMaterial(gstd::string name, Entity *target) { return {}; }
        virtual void Unknown4(void) {}
        virtual void Unknown5(void) {}

    protected:
        Cause mType;
    };

    class EntityDamageSource : public DamageSource
    {
    public:
        // FUN_0x487AA4;
        EntityDamageSource(Entity *attacker, Cause type) :
            DamageSource(type), mAttacker(attacker)
        {
            *(u32 *)this = 0x9C4B84;
        }

        ~EntityDamageSource() override = default;
        bool Unknown1(void) override { return true; }
        Entity *getAttacker(void) override { return mAttacker; }
        Entity *getProjectile(void) override { return mAttacker; }
        MessageMaterial getMessageMaterial(gstd::string name, Entity *target) override { return {}; }

    protected:
        Entity *mAttacker;
    };

    class ProjectileEntityDamageSource : public EntityDamageSource
    {
    public:
        // FUN_0x4CE878
        ProjectileEntityDamageSource(Entity *projectile, Entity *attacker, Cause type) :
            EntityDamageSource(attacker, type), mProjectile(projectile)
        {
            *(u32 *)this = 0x9C6028;
        }

        ~ProjectileEntityDamageSource() override = default;
        Entity *getProjectile(void) override { return mProjectile; }
        MessageMaterial getMessageMaterial(gstd::string name, Entity *target) override { return {}; }

    protected:
        Entity *mProjectile;
    };
}    // namespace MC3DSPluginFramework