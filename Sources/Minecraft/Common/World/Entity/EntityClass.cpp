#include "Minecraft/Common/World/Entity/EntityClass.hpp"

namespace MC3DSPluginFramework
{

    u32 Entity::Offset(u32 offset) const
    {
        return (u32)this + offset;
    }

    bool Entity::IsPlayer(void) const
    {
        return *(EntityVtable *)this == EntityVtable::Player;
    }

    bool Entity::Check(EntityVtable id) const
    {
        return *(EntityVtable *)this == id;
    }
    bool Entity::Check(const std::initializer_list<EntityVtable> &ids) const
    {
        for (auto id : ids) {
            if (Check(id))
                return true;
        }
        return false;
    }

    bool Entity::Check(const std::vector<EntityVtable> &ids) const
    {
        for (auto id : ids) {
            if (Check(id))
                return true;
        }
        return false;
    }

    Level *Entity::GetLevel(void) const
    {
        // 0x724F54
        return reinterpret_cast<Level *(*)(const Entity *)>(0x5F741C)(this);
    }

    BlockSource *Entity::GetBlockSource(void) const
    {
        return *(BlockSource **)Offset(0x210);
    }

    ArmorSlots &Entity::GetArmorSlot(void) const
    {
        return *(ArmorSlots *)Offset(0xF40);
    }

    ItemInstance &Entity::GetOffhandSlot(void) const
    {
        return *(ItemInstance *)Offset(0xF08);
    }

    ItemInstance &Entity::GetMainhandSlot(void) const
    {
        return *(ItemInstance *)Offset(0xED8);
    }

    CameraAngles &Entity::Camera(void) const
    {
        return *(CameraAngles *)Offset(0x1F0);
    }

    bool &Entity::IsTouchingWall(void) const
    {
        return *(bool *)Offset(0x25C);
    }

    bool Entity::IsOnGround(void) const
    {
        return *(bool *)Offset(0x25A) && *(bool *)Offset(0x25D);
    }

    void Entity::IsOnGround(bool onGround)
    {
        *(bool *)Offset(0x25A) = onGround;
        *(bool *)Offset(0x25D) = onGround;
    }

    void Entity::WasJustLeftGround(bool &wasJustLeftGround)
    {
        bool onGround     = IsOnGround();
        bool justLeft     = (wasJustLeftGround && !onGround);
        wasJustLeftGround = onGround;
    }

    u32 &Entity::JumpCooldown(void) const
    {
        return *(u32 *)Offset(0x107C);
    }

    void Entity::JumpUp(void)
    {
        reinterpret_cast<void (*)(Entity *)>(0x6004B8)(this);
    }

    void Entity::Jump(void)
    {
        if (IsOnGround()) {
            JumpUp();
            JumpCooldown() = 10;
        }
    }

    /*
    void Entity::ResetPitch(void) {
        Function<void>(0x4E6684)(this);
    }
    */

    size_t &Entity::InvincibleTime(void) const
    {
        return *(size_t *)Offset(0x2F0);
    }

    size_t Entity::ArmSwingAnimFrame(void) const
    {
        return reinterpret_cast<size_t (*)(const Entity *)>(0x4E7C80)(this);
    }

    Vec2_Float &Entity::ArmSwingAnim(void) const
    {
        return reinterpret_cast<Vec2_Float &(*)(const Entity *)>(0x4E576C)(this);
    }

    void Entity::SwingArm(void)
    {
        reinterpret_cast<void (*)(Entity *)>(0x4EBD28)(this);
    }

    void Entity::Attack(Entity *target)
    {
        if (target)
            reinterpret_cast<void (*)(Entity *, Entity *)>(0x606020)(this, target);
    }

    void Entity::Damage(const DamageSource &damageSource, u32 damage)
    {
        // 0x4EB408でもなぜか同じ引数が使われている(多分特に処理はない)
        // アイテムや無機物のエンティティに使うとクラッシュする可能性あり

        if (GetAttribute(Attribute::Health))
            reinterpret_cast<bool (*)(Entity *, const DamageSource &, u32, u32, u32)>(0x4EBAC8)(this, damageSource, damage, 1, 0);
    }

    void Entity::Kill(void)
    {
        reinterpret_cast<void (*)(Entity *, u32)>(0x4E7C90)(this, 3);
    }

    void Entity::Collapse(void)
    {    // 倒されるモーションを進める関数
        reinterpret_cast<void (*)(Entity *)>(0x4EE684)(this);
    }

    Vec3_Float &Entity::Velocity(void) const
    {
        return *(Vec3_Float *)Offset(0x1E4);
    }

    Vec3_Float &Entity::Position(void) const
    {
        return *(Vec3_Float *)Offset(0x214);
    }

    Vec3_Int Entity::Position_Int(void) const
    {
        Vec3_Float pos = Position();
        Vec3_Int res   = { (int)(std::ceil(pos.x - 1)), (int)(std::ceil(pos.y - 1)), (int)(std::ceil(pos.z - 1)) };
        return res;
    }

    Attribute *Entity::GetAttribute(const Attribute::Key &key) const
    {    // 0x99C6D0(vtable)
        return reinterpret_cast<Attribute *(*)(const Entity *, const Attribute::Key &)>(0x2E9564)(this, key);
    }

    bool Entity::IsEffected(Effect *effect) const
    {
        return reinterpret_cast<bool (*)(const Entity *, u32)>(0x71435C)(this, *(u32 *)effect);
    }

    EffectData &Entity::GetEffectData(Effect *effect) const
    {
        return reinterpret_cast<EffectData &(*)(const Entity *, u32)>(0x7142C4)(this, *(u32 *)effect);
    }

    gstd::vector<EffectData> &Entity::GetEffectData(void) const
    {
        return *(gstd::vector<EffectData> *)Offset(0x1014);
    }

    void Entity::GetEffect(Effect *effect, u32 level, u32 time)
    {
        EffectData data {
            .effectID = *(u32 *)(*(u32 *)(effect) + 0x4),
            .time     = time,
            .level    = level,
            .unk      = 0x00010000,
        };
        reinterpret_cast<void (*)(Entity *, EffectData &)>(0x4EDD7C)(this, data);
    }

    SynchedEntityData &Entity::GetSynchedEntityData(void) const
    {
        return *(SynchedEntityData *)Offset(0x230);
    }

    SynchedEntityData::DataItem<u16> *Entity::GetOxygen(void) const
    {
        using SED = SynchedEntityData;

        if (SED::DataItemBase *data = GetSynchedEntityData()._find(SED::ID::Oxygen))
            if (data->getType() == SED::DataType::Short)
                return (SED::DataItem<u16> *)data;

        return nullptr;
    }

    SynchedEntityData::DataItem<u16> *Entity::GetMaxOxygen(void) const
    {
        using SED = SynchedEntityData;

        if (SED::DataItemBase *data = GetSynchedEntityData()._find(SED::ID::MaxOxygen))
            if (data->getType() == SED::DataType::Short)
                return (SED::DataItem<u16> *)data;

        return nullptr;
    }

    SynchedEntityData::DataItem<float> *Entity::GetSize(void) const
    {
        using SED = SynchedEntityData;

        if (SED::DataItemBase *data = GetSynchedEntityData()._find(SED::ID::Size))
            if (data->getType() == SED::DataType::Float)
                return (SED::DataItem<float> *)data;

        return nullptr;
    }

    SynchedEntityData::DataItem<u64> *Entity::GetStates(void) const
    {
        using SED = SynchedEntityData;

        if (SED::DataItemBase *data = GetSynchedEntityData()._find(SED::ID::EntityState))
            if (data->getType() == SED::DataType::Int64)
                return (SED::DataItem<u64> *)data;

        return nullptr;
    }

    bool Entity::GetState(EntityStateFlag flag) const
    {
        if (SynchedEntityData::DataItem<u64> *state = GetStates()) {
            u32 data = (u32)(state->data() & 0x00000000FFFFFFFF);
            return data & (u32)flag;
        }

        return false;
    }

    void Entity::SetState(EntityStateFlag flag, bool enable)
    {
        if (SynchedEntityData::DataItem<u64> *state = GetStates()) {
            u64 &value = state->data();
            u32 data   = (u32)(value & 0x00000000FFFFFFFF);
            enable ? data |= (u32)flag : data &= ~(u32)flag;
            value = (value & 0xFFFFFFFF00000000) | data;
        }
    }

    bool &Entity::IsMoving(void) const
    {
        return *(bool *)Offset(0x10BC);
    }

    bool Entity::IsInNether(void) const
    {
        return reinterpret_cast<bool (*)(u32)>(0x69DF64)(*(u32 *)Offset(0x210));
    }

    bool &Entity::IsInWater(void) const
    {
        return *(bool *)Offset(0x2DE);
    }

    size_t &Entity::NetherGateTeleportTime(void) const
    {
        return *(size_t *)Offset(0x320);
    }

    bool Entity::IsInNetherGate(void) const
    {
        return *(u8 *)Offset(0x25F) == 0x5A;
    }

    void Entity::IsInNetherGate(bool flag)
    {
        *(u8 *)Offset(0x25F) == flag ? 0x5A : 0;
    }

    size_t &Entity::RunTime(void) const
    {
        return *(size_t *)Offset(0x2EC);    // Function<size_t>(0x4E6014)(this);
    }

    Entity *Entity::FishingInstance(void) const
    {
        return *(Entity **)Offset(0x35C);
    }

    size_t &Entity::TimeUntilCatch(void) const
    {
        return *(size_t *)Offset(0xEA0);
    }

    Entity *Entity::RidingEntity(void) const
    {
        return *(Entity **)Offset(0x348);
    }

    bool Entity::IsRiding(void) const
    {
        return reinterpret_cast<bool (*)(const Entity *)>(0x725380)(this);
    }

    bool Entity::CanRideOnMe(Entity *other) const
    {
        return reinterpret_cast<bool (*)(const Entity *, Entity *)>(0x71A4CC)(this, other);
    }

    bool Entity::Ride(Entity *target)
    {
        return reinterpret_cast<bool (*)(const Entity *, Entity *)>(0x1944FC)(this, target);
    }

    float &Entity::AirMoveSpeed(void) const
    {
        return *(float *)Offset(0x1038);
    }

    AbilityManager *Entity::GetAbilityManager(void) const
    {
        if (IsPlayer())
            return (AbilityManager *)Offset(0x1160);

        return nullptr;
    }

    void Entity::SetGameMode(GameModes mode)
    {
        if (IsPlayer())
            reinterpret_cast<void (*)(Entity *, GameModes)>(0x19709C)(this, mode);
    }

    GameModes Entity::GetGameMode(void) const
    {
        return IsPlayer() ? *(GameModes *)Offset(0x196C) : GameModes::Survival;
    }

    EntityId Entity::GetId(void) const
    {
        return reinterpret_cast<EntityId (*)()>((*(u32 *)this) + 0x1D4)();
    }

    AABB &Entity::GetAABB(void) const
    {
        return *(AABB *)Offset(0x288);
    }

    UniqueID &Entity::GetUniqueID(void) const
    {
        return reinterpret_cast<UniqueID &(*)(const Entity *)>(0x723618)(this);
    }

    void Entity::SetRuntimeID(u32 unknown, u64 id)
    {
        reinterpret_cast<void (*)(Entity *, u32, u64)>(0x5E9EF0)(this, unknown, id);
    }

    bool Entity::HasCategory(EntityCategory category)
    {
        return reinterpret_cast<bool (*)(Entity *, EntityCategory)>(0x723678)(this, category);
    }

}    // namespace MC3DSPluginFramework