#pragma once

#include "Minecraft/Common/Util/BoxedPtr.hpp"

namespace MC3DSPluginFramework
{
    class Attribute
    {
    public:
        struct Key {
            bool mFlag1;
            bool mFlag2;
            gstd::string mName;
        };

        static inline Key &Health              = *(Key *)0xA33338;    // minecraft:health
        static inline Key &FollowRange         = *(Key *)0xA33340;    // minecraft:follow_range
        static inline Key &KnockbackResistance = *(Key *)0xA33348;    // minecraft:knockback_resistance
        static inline Key &Movement            = *(Key *)0xA33350;    // minecraft:movement
        static inline Key &AtackDamage         = *(Key *)0xA33358;    // minecraft:attack_damage
        static inline Key &Absorption          = *(Key *)0xA33360;    // minecraft:absorption
        static inline Key &Luck                = *(Key *)0xA33368;    // minecraft:luck
        static inline Key &FallDamage          = *(Key *)0xA33370;    // minecraft:fall_damage
        static inline Key &HorseJumpStrength   = *(Key *)0xA33378;    // minecraft:horse.jump_strength

        static inline Key &Hunger     = *(Key *)0xA33B5C;    // minecraft:player.hunger
        static inline Key &Saturation = *(Key *)0xA33B64;    // minecraft:player.saturation
        static inline Key &Exhaustion = *(Key *)0xA33B6C;    // minecraft:player.exhaustion
        static inline Key &Level      = *(Key *)0xA33B74;    // minecraft:player.level
        static inline Key &XP         = *(Key *)0xA33B7C;    // minecraft:player.experience

        virtual ~Attribute();    // deletingデストラクタはなし
        virtual void Unknown1(void);
        virtual void Unknown2(void);
        virtual void Unknown3(void);

    private:
        gstd::map<gstd::string, Attribute> *mParent;
        Key *mKey;
        gstd::vector<u32> vec1;    // 謎
        gstd::vector<u32> vec2;    // 謎
        gstd::vector<u32> vec3;    // 謎
        Util::BoxedPtr::Shared<void *> mUnk1;    // テンプレートっぽい
        u32 mUnk2;    // 0
        float mFakeMaxValue;
        float mFakeCurrentValue;
        u32 mUnk3;    // 0

    public:
        float MaxValue;
        float CurrentValue;
    };
}    // namespace MC3DSPluginFramework