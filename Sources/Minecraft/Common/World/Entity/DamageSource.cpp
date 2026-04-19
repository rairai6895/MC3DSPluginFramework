#include "DamageSource.hpp"
#include "Minecraft/Common/World/Entity/Entity.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x395B8C
    DamageSource::DamageSource(Cause cause) :
        mType(cause)
    {
        *(u32 *)this = 0x9B988C;
    }

    // FUN_0x6F5250
    // +0x8
    bool DamageSource::Unknown1()
    {
        return false;
    }

    // FUN_0x6F5924
    // +0xC
    Entity *DamageSource::getAttacker()
    {
        return nullptr;
    }

    // FUN_0x6F591C
    // +0x10
    bool DamageSource::Unknown2()
    {
        return false;
    }

    // FUN_0x6F5914
    // +0x14
    Entity *DamageSource::getProjectile()
    {
        return nullptr;
    }

    // FUN_0x6F5258
    // +0x1C
    DamageSource::MessageMaterial DamageSource::getMessageMaterial(gstd::string name, Entity *target)
    {
        return reinterpret_cast<MessageMaterial (*)(DamageSource *, gstd::string, Entity *)>(0x6F5258)(this, name, target);
    }

    // FUN_0x487AA4
    EntityDamageSource::EntityDamageSource(Entity *attacker, Cause cause) :
        DamageSource(cause), mAttacker(attacker)
    {
        *(u32 *)this = 0x9C4B84;
    }

    // FUN_0x70D86C
    // +0x8
    bool EntityDamageSource::Unknown1()
    {
        return true;
    }

    // FUN_0x70DD18
    // +0xC
    Entity *EntityDamageSource::getAttacker()
    {
        return mAttacker;
    }

    // FUN_0x70DD10
    // +0x14
    Entity *EntityDamageSource::getProjectile()
    {
        return mAttacker;
    }

    // FUN_0x70D874
    // +0x1C
    EntityDamageSource::MessageMaterial EntityDamageSource::getMessageMaterial(gstd::string name, Entity *target)
    {
        return reinterpret_cast<MessageMaterial (*)(DamageSource *, gstd::string, Entity *)>(0x70D874)(this, name, target);
    }

    // FUN_0x4CE878
    ProjectileEntityDamageSource::ProjectileEntityDamageSource(Entity *projectile, Entity *attacker, Cause cause) :
        EntityDamageSource(attacker, cause), mProjectile(projectile)
    {
        *(u32 *)this = 0x9C6028;
    }

    // FUN_0x713394
    // +0x10
    bool ProjectileEntityDamageSource::Unknown2()
    {
        return true;
    }

    // FUN_0x71338C
    // +0x14
    Entity *ProjectileEntityDamageSource::getProjectile()
    {
        return mProjectile;
    }

    // FUN_0x71305C
    // +0x1C
    ProjectileEntityDamageSource::MessageMaterial ProjectileEntityDamageSource::getMessageMaterial(gstd::string name, Entity *target)
    {
        return reinterpret_cast<MessageMaterial (*)(DamageSource *, gstd::string, Entity *)>(0x71305C)(this, name, target);
    }
}    // namespace MC3DSPluginFramework