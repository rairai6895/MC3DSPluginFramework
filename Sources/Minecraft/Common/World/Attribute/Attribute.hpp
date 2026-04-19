#pragma once

#include "Minecraft/Common/Util/BoxedPtr.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\attribute\\Attribute.cpp"
    class Attribute
    {
        USE_GAME_ALLOCATOR
    public:
        static inline Attribute &Health              = *(Attribute *)0xA33338;    // minecraft:health
        static inline Attribute &FollowRange         = *(Attribute *)0xA33340;    // minecraft:follow_range
        static inline Attribute &KnockbackResistance = *(Attribute *)0xA33348;    // minecraft:knockback_resistance
        static inline Attribute &Movement            = *(Attribute *)0xA33350;    // minecraft:movement
        static inline Attribute &AtackDamage         = *(Attribute *)0xA33358;    // minecraft:attack_damage
        static inline Attribute &Absorption          = *(Attribute *)0xA33360;    // minecraft:absorption
        static inline Attribute &Luck                = *(Attribute *)0xA33368;    // minecraft:luck
        static inline Attribute &FallDamage          = *(Attribute *)0xA33370;    // minecraft:fall_damage
        static inline Attribute &HorseJumpStrength   = *(Attribute *)0xA33378;    // minecraft:horse.jump_strength

        static inline Attribute &Hunger     = *(Attribute *)0xA33B5C;    // minecraft:player.hunger
        static inline Attribute &Saturation = *(Attribute *)0xA33B64;    // minecraft:player.saturation
        static inline Attribute &Exhaustion = *(Attribute *)0xA33B6C;    // minecraft:player.exhaustion
        static inline Attribute &Level      = *(Attribute *)0xA33B74;    // minecraft:player.level
        static inline Attribute &XP         = *(Attribute *)0xA33B7C;    // minecraft:player.experience

    public:
        Attribute(gstd::string name, bool unknown1, bool unknown2) :
            mUnk1(unknown1), mUnk2(unknown2), mName(name)
        {
            if (name.empty())
                LOG("Attribute Name cannot be empty", !name.empty(), 0);

            auto &mAttributesMap = reinterpret_cast<gstd::map<gstd::string, const Attribute *> &(*)()>(0x3AD008)();
            addAttribute(mAttributesMap, name, this);
        }

        static void addAttribute(gstd::map<gstd::string, const Attribute *> &mAttributesMap, gstd::string name, const Attribute *add)
        {
            reinterpret_cast<void (*)(gstd::map<gstd::string, const Attribute *> &, gstd::string, const Attribute *)>(0x3ACB6C)(mAttributesMap, name, add);
        }

    private:
        bool         mUnk1;
        bool         mUnk2;
        gstd::string mName;
    };
}    // namespace MC3DSPluginFramework