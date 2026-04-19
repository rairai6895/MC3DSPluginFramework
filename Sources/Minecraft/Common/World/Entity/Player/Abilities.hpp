#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/NBT/CompoundTag.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Ability
    {
    public:
        enum class Type : u8 {
            Bool  = 1,
            Float = 2,
        };

        // FUN_0x729F24
        float getFloat()
        {
            if (!(mType == Type::Float))
                LOG("Type mismatch", mType == Type::Float, 0);

            return mFValue;
        }

        void setFloat(float set)
        {
            if (!(mType == Type::Float))
                LOG("Type mismatch", mType == Type::Float, 0);

            mFValue = set;
        }

        // FUN_0x729EA8
        bool getBool()
        {
            if (!(mType == Type::Bool))
                LOG("Type mismatch", mType == Type::Bool, 0);

            return mBValue;
        }

        // FUN_0x629014
        void setBool(bool set)
        {
            if (!(mType == Type::Bool))
                LOG("Type mismatch", mType == Type::Bool, 0);

            mBValue = set;
        }

    private:
        Type mType;
        union {
            float mFValue;
            bool  mBValue;
        };
        u32 mUnk1;
    };

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\entity\\player\\Abilities.cpp"
    class Abilities
    {
    public:
        static inline const gstd::string &MAYFLY       = *(gstd::string *)0xA33AD4;    // CanFly
        static inline const gstd::string &WORLDBUILDER = *(gstd::string *)0xA33AD8;
        static inline const gstd::string &MUTE         = *(gstd::string *)0xA33ADC;
        static inline const gstd::string &INVULNERABLE = *(gstd::string *)0xA33AE0;    // Invincible
        static inline const gstd::string &FLYING       = *(gstd::string *)0xA33AE4;
        static inline const gstd::string &INSTABUILD   = *(gstd::string *)0xA33AE8;
        static inline const gstd::string &LIGHTNING    = *(gstd::string *)0xA33AEC;
        static inline const gstd::string &FLYSPEED     = *(gstd::string *)0xA33AF0;
        static inline const gstd::string &WALKSPEED    = *(gstd::string *)0xA33AF4;
        static inline const gstd::string &NOCLIP       = *(gstd::string *)0xA33AF8;

    public:
        Ability &getAbility(gstd::string ability);
        bool     getBool(gstd::string ability);
        void     setBool(gstd::string ability, bool set);
        float    getFloat(gstd::string ability);
        void     setFloat(gstd::string ability, float set);
        bool     isFlying();
        u8       getPermissionsLevel() const;
        void     loadSaveData(const CompoundTag &tag);
        void     addSaveData(CompoundTag &tag);

    private:
        void putPermissionsLevel(u8 *permissionsLevel, CompoundTag &tag);

    private:
        u8                              *mPermissionsLevel;
        gstd::map<gstd::string, Ability> mAbilities;
    };
}    // namespace MC3DSPluginFramework