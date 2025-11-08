#ifndef ENTITYCLASS_HPP
#define ENTITYCLASS_HPP

#include "GameEnums.hpp"
#include "GameStructs.hpp"
#include "ItemSlot.hpp"
#include "Structs.hpp"
#include "WorldClass.hpp"

namespace MC3DSPluginFramework {

struct ArmorSlots {
    ItemSlot helmet, chestplate, leggings, boots;
};

class Entity {
  public:
    u32 Offset(u32 offset = 0) const;
    bool IsPlayer(void) const;
    bool Check(EntityVtable id) const;
    bool Check(const std::initializer_list<EntityVtable> &ids) const;
    bool Check(const std::vector<EntityVtable> &ids) const;
    World *GetWorld(void) const;
    ArmorSlots &GetArmorSlot(void) const;
    ItemSlot &GetOffhandSlot(void) const;
    ItemSlot &GetMainhandSlot(void) const;
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
    void Damage(u32 damage);
    void Kill(void);
    void Collapse(void);
    Vec3_Float &Velocity(void) const;
    Vec3_Float &Position(void) const;
    Vec3_Int Position_Int(void) const;
    StatusData *GetStatus(Status status) const;
    bool IsEffected(Effects effect) const;
    EffectData &GetEffectData(Effects effect) const;
    gstd::vector<EffectData> &GetEffectData(void) const;
    void GetEffect(Effects effect, u32 level, u32 time);
    u16 Oxygen(void) const;
    void Oxygen(u16 oxygen);
    u16 MaxOxygen(void) const;
    void MaxOxygen(u16 maxOxygen);
    bool InfiniteOxygen(void) const;
    void InfiniteOxygen(bool infinite);
    float Size(void) const;
    void Size(float size);
    bool IsSprinting(void) const;
    void IsSprinting(bool sprinting);
    bool IsInvisible(void) const;
    void IsInvisible(bool invisible);
    bool IsElytraFlying(void) const;
    void IsElytraFlying(bool flying);
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

  private:
    struct OxygenData {
      private:
        u32 vtable;

      public:
        bool infinite;

      private:
        u8 unk[5];

      public:
        u16 value;
    };

    struct SizeData {
      private:
        u32 vtable;

      public:
        u8 invisible;

      private:
        u8 unk[7];

      public:
        float value;
    };

    struct ActionData {
      private:
        u32 vtable;
        u32 unk1[3];

      public:
        u32 flag;

      private:
        u32 unk2;
    };

    template <typename T>
    T *GetState(size_t index) const;

    bool CheckFlag(ActionFlags flag) const;
    void SetFlag(ActionFlags flag, bool enable);
};

}    // namespace MC3DSPluginFramework

#endif