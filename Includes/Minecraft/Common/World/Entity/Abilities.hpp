#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework {

class Ability {
  public:
    static inline const gstd::string &mayfly       = *(gstd::string *)0xA33AD4;    // CanFly
    static inline const gstd::string &worldbuilder = *(gstd::string *)0xA33AD8;
    static inline const gstd::string &mute         = *(gstd::string *)0xA33ADC;
    static inline const gstd::string &invulnerable = *(gstd::string *)0xA33AE0;    // Invincible
    static inline const gstd::string &flying       = *(gstd::string *)0xA33AE4;
    static inline const gstd::string &instabuild   = *(gstd::string *)0xA33AE8;    // InfiniteItems
    static inline const gstd::string &lightning    = *(gstd::string *)0xA33AEC;
    static inline const gstd::string &flySpeed     = *(gstd::string *)0xA33AF0;
    static inline const gstd::string &walkSpeed    = *(gstd::string *)0xA33AF4;
    static inline const gstd::string &noclip       = *(gstd::string *)0xA33AF8;

    enum class Type : u8 {
        Bool  = 1,
        Float = 2,
    };

    float &getFloat(void) {
        return mFValue;
    }

    bool &getBool(void) {
        return mBValue;
    }

  private:
    Type mType;
    union {
        float mFValue;
        bool mBValue;
    };
    u32 mUnk1;
};

class AbilityManager {
  public:
    Ability *get(gstd::string ability) {
        return reinterpret_cast<Ability *(*)(AbilityManager *, gstd::string)>(0x735384)(this, ability);
    }

    bool getBool(gstd::string ability) const {
        return reinterpret_cast<bool (*)(const AbilityManager *, gstd::string)>(0x7356A4)(this, ability);
    }

    void setBool(gstd::string ability, bool flag) {
        reinterpret_cast<void (*)(AbilityManager *, gstd::string, bool)>(0x665B14)(this, ability, flag);
    }

    bool isFlying(void) const {
        // flying || noclip
        return reinterpret_cast<bool (*)(const AbilityManager *)>(0x73576C)(this);
    }

  private:
    void *mUnk1;
    gstd::map<gstd::string, Ability> mAbilities;
};
}    // namespace MC3DSPluginFramework