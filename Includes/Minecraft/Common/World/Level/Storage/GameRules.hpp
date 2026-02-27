#pragma once

#include "Minecraft/Common/Client/Gui/Screens/SystemMessagesScreen.hpp"
#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include <CTRPluginFramework.hpp>

namespace MC3DSPluginFramework
{
    class GameRule
    {
    public:
        enum class Type : u8 {
            Bool  = 1,
            Int   = 2,
            Float = 3,
        };

        static inline const gstd::string
            &commandblockoutput      = *(gstd::string *)0xA351C4,
            &dodaylightcycle         = *(gstd::string *)0xA351C8,
            &doentitydrops           = *(gstd::string *)0xA351CC,
            &dofiretick              = *(gstd::string *)0xA351D0,
            &domobloot               = *(gstd::string *)0xA351D4,
            &domobspawning           = *(gstd::string *)0xA351D8,
            &dotiledrops             = *(gstd::string *)0xA351DC,
            &doweathercycle          = *(gstd::string *)0xA351E0,
            &drowningdamage          = *(gstd::string *)0xA351E4,
            &falldamage              = *(gstd::string *)0xA351E8,
            &firedamage              = *(gstd::string *)0xA351EC,
            &keepinventory           = *(gstd::string *)0xA351F0,
            &movgriefing             = *(gstd::string *)0xA351F4,
            &pvp                     = *(gstd::string *)0xA351F8,
            &sendcommandfeedback     = *(gstd::string *)0xA351FC,
            &globalmute              = *(gstd::string *)0xA35200,
            &allowdestructiveobjects = *(gstd::string *)0xA35204,
            &allowmobs               = *(gstd::string *)0xA35208;

        Type getType()
        {
            return mType;
        }

        // FUN_0x732FA4
        bool getBool()
        {
            return mBool;
        }

        // FUN_0x732F24
        int getInt()
        {
            return mInt;
        }

        // FUN_0x733024
        float getFloat()
        {
            return mFloat;
        }

        // FUN_0x6511E8
        void setBool(bool b)
        {
            if (!(mType == Type::Bool))
                LOG("Type Should be bool", mType == Type::Bool, 0);

            mBool = b;
        }

        // FUN_0x651184
        void setInt(int i)
        {
            if (!(mType == Type::Int))
                LOG("Type Should be Int", mType == Type::Int, 0);

            mInt = i;
        }

        // FUN_0x65124C
        void setFloat(float f)
        {
            if (!(mType == Type::Float))
                LOG("Type Should be Float", mType == Type::Float, 0);

            mFloat = f;
        }

    private:
        u8 mUnk1;
        u8 mUnk2;
        Type mType;
        u8 mUnk3;
        union {
            bool mBool;
            int mInt;
            float mFloat;
        };
    };

    // 変更後のルールはおそらく全てセーブデータに保存される。

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\storage\\GameRules.cpp"
    class GameRules
    {
    public:
        bool getBool(gstd::string rule) const
        {
            return reinterpret_cast<bool (*)(const GameRules *, gstd::string)>(0x73D1F8)(this, rule);
        }

        void setBool(gstd::string rule, bool b)
        {
            auto it = mRules.find(rule);

            if ((it != mRules.end()) && (it->second.getType() == GameRule::Type::Bool))
                it->second.setBool(b);
        }

    private:
        gstd::map<gstd::string, GameRule> mRules;
    };

}    // namespace MC3DSPluginFramework