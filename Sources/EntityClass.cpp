#include "EntityClass.hpp"

namespace MC3DSPluginFramework {

u32 Entity::Offset(u32 offset) const {
    return (u32)this + offset;
}

bool Entity::IsPlayer(void) const {
    return *(EntityVtable *)this == EntityVtable::Player;
}

bool Entity::Check(EntityVtable id) const {
    return *(EntityVtable *)this == id;
}
bool Entity::Check(const std::initializer_list<EntityVtable> &ids) const {
    for (auto id : ids) {
        if (Check(id))
            return true;
    }
    return false;
}

bool Entity::Check(const std::vector<EntityVtable> &ids) const {
    for (auto id : ids) {
        if (Check(id))
            return true;
    }
    return false;
}

World *Entity::GetWorld(void) const {
    return Function<MC3DSPluginFramework::World *>(0x5F741C)(this);
}

ArmorSlots &Entity::GetArmorSlot(void) const {
    return *(ArmorSlots *)this->Offset(0xF40);
}

SlotData &Entity::GetOffhandSlot(void) const {
    return *(SlotData *)Offset(0xF08);
}

SlotData &Entity::GetMainhandSlot(void) const {
    return *(SlotData *)Offset(0xED8);
}

CameraAngles &Entity::Camera(void) const {
    return *(CameraAngles *)Offset(0x1F0);
}

bool &Entity::IsTouchingWall(void) const {
    return *(bool *)Offset(0x25C);
}

bool Entity::IsOnGround(void) const {
    return *(bool *)Offset(0x25A) && *(bool *)Offset(0x25D);
}

void Entity::IsOnGround(bool onGround) {
    *(bool *)Offset(0x25A) = onGround;
    *(bool *)Offset(0x25D) = onGround;
}

void Entity::WasJustLeftGround(bool &wasJustLeftGround) {
    bool onGround     = IsOnGround();
    bool justLeft     = (wasJustLeftGround && !onGround);
    wasJustLeftGround = onGround;
}

u32 &Entity::JumpCooldown(void) const {
    return *(u32 *)Offset(0x107C);
}

void Entity::JumpUp(void) {
    Function<void>(0x6004B8)(this);
}

void Entity::Jump(void) {
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

size_t &Entity::InvincibleTime(void) const {
    return *(size_t *)Offset(0x2F0);
}

size_t Entity::ArmSwingAnimFrame(void) const {
    return Function<size_t>(0x4E7C80)(this);
}

Vec2_Float &Entity::ArmSwingAnim(void) const {
    return Function<Vec2_Float &>(0x4E576C)(this);
}

void Entity::SwingArm(void) {
    Function<void>(0x4EBD28)(this);
}

void Entity::Attack(Entity *target) {
    if (target)
        Function<void>(0x606020)(this, target);
}

void Entity::Damage(u32 damage) {
    // 0x4EB408でもなぜか同じ引数が使われている(多分特に処理はない)
    // アイテムや無機物のエンティティに使うとクラッシュする可能性あり

    struct DamageArg {
        u32 vtable = 0x9C4B84;
        u32 unk    = 0;
        Entity *attacker;

        DamageArg(Entity *attacker) :
            attacker(attacker) {}
    };
    DamageArg arg(this);
    if (GetStatus(Status::Health) && GetStatus(Status::Absorption))
        Function<bool>(0x4EBAC8)(this, &arg, damage, 0, 0);
}

void Entity::Kill(void) {
    Function<void>(0x4E7C90)(this, 3);
}

void Entity::Collapse(void) {    // 倒されるモーションを進める関数
    Function<void>(0x4EE684)(this);
}

Vec3_Float &Entity::Velocity(void) const {
    return *(Vec3_Float *)Offset(0x1E4);
}

Vec3_Float &Entity::Position(void) const {
    return *(Vec3_Float *)Offset(0x214);
}

Vec3_Int Entity::Position_Int(void) const {
    Vec3_Float pos = Position();
    Vec3_Int res   = {(int)(std::ceil(pos.x - 1)), (int)(std::ceil(pos.y - 1)), (int)(std::ceil(pos.z - 1))};
    return res;
}

StatusData *Entity::GetStatus(Status status) const {    // 0x99C6D0(vtable)
    return Function<StatusData *>(0x2E9564)(this, status);
}

bool Entity::IsEffected(Effects effect) const {
    return Function<bool>(0x71435C)(this, *(u32 *)effect);
}

EffectData &Entity::GetEffectData(Effects effect) const {
    return Function<EffectData &>(0x7142C4)(this, *(u32 *)effect);
}

gstd::vector<EffectData> &Entity::GetEffectData(void) const {
    return *(gstd::vector<EffectData> *)Offset(0x1014);
}

void Entity::GetEffect(Effects effect, u32 level, u32 time) {
    EffectData data{
        .effectID = *(u32 *)(*(u32 *)(effect) + 0x4),
        .time     = time,
        .level    = level,
        .unk      = 0x00010000,
    };
    Function<void>(0x4EDD7C)(this, &data);
}

template <typename T>
T *Entity::GetState(size_t index) const {
    return (T *)(*(std::vector<void *> *)Offset(0x230))[index];
}

u16 Entity::Oxygen(void) const {
    if (const auto state = GetState<OxygenData>(0x7))
        return state->value;
    return 0;
}

void Entity::Oxygen(u16 oxygen) {
    if (const auto state = GetState<OxygenData>(0x7))
        state->value = oxygen;
}

u16 Entity::MaxOxygen(void) const {
    if (const auto state = GetState<OxygenData>(0x2C))
        return state->value;
    return 0;
}

void Entity::MaxOxygen(u16 maxOxygen) {
    if (const auto state = GetState<OxygenData>(0x2C))
        state->value = maxOxygen;
}

bool Entity::InfiniteOxygen(void) const {
    if (const auto state = GetState<OxygenData>(0x7))
        return state->infinite;
    return false;
}

void Entity::InfiniteOxygen(bool infinite) {
    if (const auto state = GetState<OxygenData>(0x7))
        state->infinite = infinite;
}

float Entity::Size(void) const {
    if (const auto state = GetState<SizeData>(0x27))
        return state->value;
    return 0;
}

void Entity::Size(float size) {
    if (const auto state = GetState<SizeData>(0x27))
        state->value = size;
}

bool Entity::CheckFlag(ActionFlags flag) const {
    return GetState<ActionData>(0)->flag & (u32)flag;
}

void Entity::SetFlag(ActionFlags flag, bool enable) {
    if (enable)
        GetState<ActionData>(0)->flag |= (u32)flag;
    else
        GetState<ActionData>(0)->flag &= ~(u32)flag;
}

bool Entity::IsSprinting(void) const {
    return CheckFlag(ActionFlags::Sprint);
}

void Entity::IsSprinting(bool sprinting) {
    SetFlag(ActionFlags::Sprint, sprinting);
}

bool Entity::IsInvisible(void) const {
    return CheckFlag(ActionFlags::Invisible);
}

void Entity::IsInvisible(bool invisible) {
    SetFlag(ActionFlags::Invisible, invisible);
}

bool Entity::IsElytraFlying(void) const {
    return CheckFlag(ActionFlags::ElytraFly);
}

void Entity::IsElytraFlying(bool flying) {
    SetFlag(ActionFlags::ElytraFly, flying);
}

bool &Entity::IsMoving(void) const {
    return *(bool *)Offset(0x10BC);
}

bool Entity::IsInNether(void) const {
    return Function<bool>(0x69DF64)(*(u32 *)this->Offset(0x210));
}

bool &Entity::IsInWater(void) const {
    return *(bool *)Offset(0x2DE);
}

size_t &Entity::NetherGateTeleportTime(void) const {
    return *(size_t *)Offset(0x320);
}

bool Entity::IsInNetherGate(void) const {
    return *(u8 *)Offset(0x25F) == 0x5A;
}

void Entity::IsInNetherGate(bool flag) {
    *(u8 *)Offset(0x25F) == flag ? 0x5A : 0;
}

size_t &Entity::RunTime(void) const {
    return *(size_t *)Offset(0x2EC);    // Function<size_t>(0x4E6014)(this);
}

Entity *Entity::FishingInstance(void) const {
    return *(Entity **)Offset(0x35C);
}

size_t &Entity::TimeUntilCatch(void) const {
    return *(size_t *)Offset(0xEA0);
}

Entity *Entity::RidingEntity(void) const {
    return *(Entity **)Offset(0x348);
}

bool Entity::IsRiding(void) const {
    return Function<bool>(0x725380)(this);
}

bool Entity::CanRideOnMe(Entity *other) const {
    return Function<bool>(0x71A4CC)(this, other);
}

bool Entity::Ride(Entity *target) {
    return Function<bool>(0x1944FC)(this, target);
}

float &Entity::AirMoveSpeed(void) const {
    return *(float *)Offset(0x1038);
}

}    // namespace MC3DSPluginFramework