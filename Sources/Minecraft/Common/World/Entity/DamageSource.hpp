#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Entity;

    class DamageSource
    {
    public:
        enum class Cause : int {
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

        struct MessageMaterial
        {
            gstd::string               descriptionId;
            gstd::vector<gstd::string> params;
        };

        DamageSource(Cause cause);
        virtual ~DamageSource() = default;

        virtual bool            Unknown1();
        virtual Entity         *getAttacker();
        virtual bool            Unknown2();
        virtual Entity         *getProjectile();
        virtual void            Unknown3() = delete;    // +0x18
        virtual MessageMaterial getMessageMaterial(gstd::string name, Entity *target);

    protected:
        Cause mType;
    };

    class EntityDamageSource : public DamageSource
    {
    public:
        EntityDamageSource(Entity *attacker, Cause cause);
        ~EntityDamageSource() override = default;

        bool            Unknown1() override;
        Entity         *getAttacker() override;
        Entity         *getProjectile() override;
        MessageMaterial getMessageMaterial(gstd::string name, Entity *target) override;

    protected:
        Entity *mAttacker;
    };

    class ProjectileEntityDamageSource : public EntityDamageSource
    {
    public:
        ProjectileEntityDamageSource(Entity *projectile, Entity *attacker, Cause cause);
        ~ProjectileEntityDamageSource() override = default;

        bool            Unknown2() override;
        Entity         *getProjectile() override;
        MessageMaterial getMessageMaterial(gstd::string name, Entity *target) override;

    protected:
        Entity *mProjectile;
    };
}    // namespace MC3DSPluginFramework