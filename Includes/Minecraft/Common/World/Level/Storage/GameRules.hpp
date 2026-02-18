#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework {
// "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\storage\\GameRules.cpp"
class GameRule {
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

    // FUN_0x732FA4
    bool getBool(void) { return mBool; }

    // FUN_0x732F24
    int getInt(void) { return mInt; }

    // FUN_0x733024
    float getFloat(void) { return mFloat; }

    // FUN_0x6511E8
    void setBool(bool b) { mBool = b; }

    // FUN_0x651184
    void setInt(int i) { mInt = i; }

    // FUN_0x65124C
    void setFloat(float f) { mFloat = f; }

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

class GameRules {
  public:
    bool getBool(gstd::string rule) const {
        return reinterpret_cast<bool (*)(const GameRules *, gstd::string)>(0x73D1F8)(this, rule);
    }

  private:
    gstd::map<gstd::string, GameRule> mRules;
};

}    // namespace MC3DSPluginFramework