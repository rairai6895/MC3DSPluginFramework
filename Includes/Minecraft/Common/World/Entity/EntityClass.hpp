#pragma once

#include "Minecraft/Common/World/Entity/Abilities.hpp"
#include "Minecraft/Common/World/Entity/Attribute.hpp"
#include "Minecraft/Common/World/Entity/DamageSource.hpp"
#include "Minecraft/Common/World/Entity/Effects.hpp"
#include "Minecraft/Common/World/Entity/SynchedEntityData.hpp"
#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Common/World/Level/BlockSource.hpp"
#include "Minecraft/Common/World/Level/Level.hpp"
#include "Minecraft/Common/World/Phys/AABB.hpp"
#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/Helper/GameStructs.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    struct ArmorSlots;
    class DamageSource;
    class ItemInstance;
    class Level;

    class Entity
    {
    public:
        u32 Offset(u32 offset = 0) const;
        bool IsPlayer(void) const;
        bool Check(EntityVtable id) const;
        bool Check(const std::initializer_list<EntityVtable> &ids) const;
        bool Check(const std::vector<EntityVtable> &ids) const;
        Level *GetLevel(void) const;
        BlockSource *GetBlockSource(void) const;
        ArmorSlots &GetArmorSlot(void) const;
        ItemInstance &GetOffhandSlot(void) const;
        ItemInstance &GetMainhandSlot(void) const;
        CameraAngles &Camera(void) const;
        bool &IsTouchingWall(void) const;
        bool IsOnGround(void) const;
        void IsOnGround(bool onGround);
        void WasJustLeftGround(bool &wasJustLeftGround);
        u32 &JumpCooldown(void) const;
        void JumpUp(void);
        void Jump(void);
        size_t &InvincibleTime(void) const;
        size_t ArmSwingAnimFrame(void) const;
        Vec2_Float &ArmSwingAnim(void) const;
        void SwingArm(void);
        void Attack(Entity *target);
        void Damage(const DamageSource &damageSource, u32 damage);
        void Kill(void);
        void Collapse(void);
        Vec3_Float &Velocity(void) const;
        Vec3_Float &Position(void) const;
        Vec3_Int Position_Int(void) const;
        Attribute *GetAttribute(const Attribute::Key &key) const;
        bool IsEffected(Effect *effect) const;
        EffectData &GetEffectData(Effect *effect) const;
        gstd::vector<EffectData> &GetEffectData(void) const;
        void GetEffect(Effect *effect, u32 level, u32 time);
        SynchedEntityData &GetSynchedEntityData(void) const;
        SynchedEntityData::DataItem<u16> *GetOxygen(void) const;
        SynchedEntityData::DataItem<u16> *GetMaxOxygen(void) const;
        SynchedEntityData::DataItem<float> *GetSize(void) const;
        SynchedEntityData::DataItem<u64> *GetStates(void) const;
        bool GetState(EntityStateFlag flag) const;
        void SetState(EntityStateFlag flag, bool enable);
        bool &IsMoving(void) const;
        bool IsInNether(void) const;
        bool &IsInWater(void) const;
        size_t &NetherGateTeleportTime(void) const;
        bool IsInNetherGate(void) const;
        void IsInNetherGate(bool flag);
        size_t &RunTime(void) const;
        Entity *FishingInstance(void) const;

        // FishingInstance Only
        size_t &TimeUntilCatch(void) const;

        Entity *RidingEntity(void) const;
        bool IsRiding(void) const;
        bool CanRideOnMe(Entity *other) const;
        bool Ride(Entity *target);

        float &AirMoveSpeed(void) const;

        AbilityManager *GetAbilityManager(void) const;
        void SetGameMode(GameModes mode);
        GameModes GetGameMode(void) const;
        EntityId GetId(void) const;

        AABB &GetAABB(void) const;
        UniqueID &GetUniqueID(void) const;
        void SetRuntimeID(u32 unknown, u64 id);

        bool HasCategory(EntityCategory category);

        // FUN_0x725588
        bool isRemoved(void) const { return *(bool *)Offset(0xD4B); }

        // FUN_0x723DA8
        bool isRegionValid(void) { return this->GetBlockSource(); }

    private:
    };

}    // namespace MC3DSPluginFramework