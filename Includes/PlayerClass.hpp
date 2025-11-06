#ifndef PLAYERCLASS_HPP
#define PLAYERCLASS_HPP

#include "EntityClass.hpp"
#include "GameSystem.hpp"

namespace MC3DSPluginFramework {

class Player {
  public:
    struct AbilityState;

    static Entity *GetInstance(void);
    static bool IsLoaded(void);
    static AbilityState *GetAbilityState(void);
    static bool IsJumping(void);
    static void IsJumping(bool jumping);
    static bool IsSneaking(void);
    static void IsSneaking(bool sneak);
    static u32 SprintDelay(void);
    static void SprintDelay(u32 delay);
    static bool IsInUnderWater(void);
    static void IsInUnderWater(const bool flag);
    static void Teleport(const Vec3_Int &pos);

    struct AbilityState {
        GameModes &Mode;
        bool &CanFly;
        bool &IsInvincible;
        bool &IsFlying;
        bool &InfiniteItems;
        bool &Lightning;
        float &FlySpeed;
        float &WalkSpeed;
        bool &NoClip;

        void Set(GameModes mode) {
            if (!Player::IsLoaded())
                return;

            Mode = mode;

            if (mode == Survival) {
                CanFly        = false;
                IsInvincible  = false;
                IsFlying      = false;
                InfiniteItems = false;
                NoClip        = false;
            } else if (mode == Creative) {
                CanFly        = true;
                IsInvincible  = true;
                InfiniteItems = true;
                NoClip        = false;
            } else if (mode == Adventure) {
                CanFly        = false;
                IsInvincible  = false;
                IsFlying      = false;
                InfiniteItems = false;
                NoClip        = false;
            } else {    // Spectators
                CanFly        = true;
                IsInvincible  = true;
                IsFlying      = true;
                InfiniteItems = true;
                NoClip        = true;
            }
        }
    };

  private:
    static void *GetAbility(Ability id);
};

}    // namespace MC3DSPluginFramework

#endif