#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework {
class Options {
  public:
    enum class Type {
        Byte,
        Float,
        String,
        Int,
    };

    using Key = std::pair<Type, gstd::string>;

    static inline const Key
        &music                           = *(Key *)0xA31C4C,
        &sound                           = *(Key *)0xA31C54,
        &invertYAxis                     = *(Key *)0xA31C5C,
        &sensitivity                     = *(Key *)0xA31C64,
        &renderDistance                  = *(Key *)0xA31C6C,
        &particleRenderDistance          = *(Key *)0xA31C74,
        &viewBobbing                     = *(Key *)0xA31C7C,
        &limitFramerate                  = *(Key *)0xA31C84,
        &difficulty                      = *(Key *)0xA31C8C,
        &graphics                        = *(Key *)0xA31C94,
        &transparentleaves               = *(Key *)0xA31C9C,
        &uiprofile                       = *(Key *)0xA31CA4,
        &guiScale_optionName             = *(Key *)0xA31CAC,
        &dev_use_fps_independent_turning = *(Key *)0xA31CB4,
        &filelocation_title              = *(Key *)0xA31CBC,
        &thirdperson                     = *(Key *)0xA31CC4,
        &hidegui                         = *(Key *)0xA31CCC,
        &multiplayergame                 = *(Key *)0xA31CD4,
        &servervisible                   = *(Key *)0xA31CDC,
        &xboxlivevisible                 = *(Key *)0xA31CE4,
        &lefthanded                      = *(Key *)0xA31CEC,
        &usetouchscreen                  = *(Key *)0xA31CF4,
        &usetouchpad                     = *(Key *)0xA31CFC,
        &swapJumpAndSneak                = *(Key *)0xA31D04,
        &destroyvibration                = *(Key *)0xA31D0C,
        &autojump                        = *(Key *)0xA31D14,
        &toggleCrouch                    = *(Key *)0xA31D1C,
        &resourcepacks                   = *(Key *)0xA31D24,
        &fancyskies                      = *(Key *)0xA31D2C,
        &buttonSize                      = *(Key *)0xA31D34,
        &name                            = *(Key *)0xA31D3C,
        &skin                            = *(Key *)0xA31D44,
        &worldsizelimit                  = *(Key *)0xA31D4C,
        &gamma                           = *(Key *)0xA31D54,
        &dev_createRealmWithoutPurchase  = *(Key *)0xA31D5C,
        &dev_offersUnlocked              = *(Key *)0xA31D64,
        &dev_storeOfferQueryRequiresXbl  = *(Key *)0xA31D6C,
        &dev_renderBoundingBox           = *(Key *)0xA31D74,
        &dev_renderPaths                 = *(Key *)0xA31D7C,
        &dev_renderGoalState             = *(Key *)0xA31D84,
        &dev_resetClientId               = *(Key *)0xA31D8C,
        &fullscreen                      = *(Key *)0xA31D94,
        &fov                             = *(Key *)0xA31D9C,
        &msaa                            = *(Key *)0xA31DA4,
        &texelAA                         = *(Key *)0xA31DAC,
        &maxFramerate                    = *(Key *)0xA31DB4,
        &dev_enableDebugHudOverlay       = *(Key *)0xA31DBC,
        &dev_showBuildInfo               = *(Key *)0xA31DC4,
        &showAdvancedVideoSettings       = *(Key *)0xA31DCC,
        &dev_showChunkMap                = *(Key *)0xA31DD4,
        &dev_enableProfiler              = *(Key *)0xA31DDC,
        &dev_achievementsAlwaysEnabled   = *(Key *)0xA31DE4,
        &dev_useLocalServer              = *(Key *)0xA31DEC,
        &dev_useIPv6Only                 = *(Key *)0xA31DF4,
        &dev_connectionQuality           = *(Key *)0xA31DFC,
        &dev_useRetailXboxSandbox        = *(Key *)0xA31E04,
        &dev_realmsEnvironment           = *(Key *)0xA31E0C,
        &dev_realmsEndpoint              = *(Key *)0xA31E14,
        &dev_realmsEndpointPayment       = *(Key *)0xA31E1C,
        &dev_realmsRelyingParty          = *(Key *)0xA31E24,
        &dev_realmsRelyingPartyPayment   = *(Key *)0xA31E2C;

    void setFloat(const Key &option, float value) {
        reinterpret_cast<void (*)(Options *, const Key &, float)>(0x6329B8)(this, option, value);
    }

    void setByte(const Key &option, char value) {
        reinterpret_cast<void (*)(Options *, const Key &, char)>(0x632644)(this, option, value);
    }

    char getByte(const Key &option) {
        return reinterpret_cast<char (*)(Options *, const Key &)>(0x63019C)(this, option);
    }

    void setInt(const Key &option, int value, u32 unknown) {
        reinterpret_cast<void (*)(Options *, const Key &, int, u32)>(0x632AEC)(this, option, value, unknown);
    }

    int getInt(const Key &option) {
        return reinterpret_cast<int (*)(Options *, const Key &)>(0x62FCDC)(this, option);
    }

  private:
    gstd::string mFile;    // options.txt
    u32 mUnk1;
    u32 mUnk2;
    u32 mUnk3;
    std::vector<void *> mUnk4;
    std::vector<void *> mUnk5;
    std::vector<void *> mUnk6;
    std::vector<void *> mUnk7;
    std::vector<void *> mUnk8;
    u8 mUnk9;
    float mMusic;
    float mSound;
    float mSensitivity1;    // unknown
    float mSensitivity2;    // unknown
    bool mInvertYAxis;
    int mRenderDistance;
    u32 mUnk10;
    bool mViewBobbing;
    bool mLimitFramerate;
    bool mGraphics;    // particle
    bool mTransparentleaves;
    bool mUnk11;
    bool mUnk12;
    bool mUnk13;
    bool mUnk14;
    bool mAutojump;    // 0x341F3054
    bool mUnk15;
    bool mUnk16;
    char mUnk17;
    void *mUnk18;
    void *mUnk19;
    void *mUnk20;
    void *mUnk21;
    u32 mUnk22;
    void *mUnk23;
    void *mUnk24;
    gstd::string mLanguageLocale;    // 0x341F3074
    int mUnk25;
    u32 mUnk26;
    u32 mUnk27;
    u32 mUnk28;
    u32 mUnk29;
    u32 mUnk30;    // 0x341F308C
    u32 mUnk31;
    u32 mUnk32;
    u32 mUnk33;
    u32 mUnk34;
    u32 mUnk35;
    u32 mUnk36;
    u32 mUnk37;
    u32 mUnk38;
    u32 mUnk39;
    u32 mUnk40;
    u32 mUnk41;    // 0x341F30B8
    u32 mUnk42;
    u32 mUnk43;
    u32 mUnk44;
    u32 mUnk45;
    u32 mUnk46;
    u32 mUnk47;    // 0x341F30D0
    u32 mUnk48;
    u32 mUnk49;
    u32 mUnk50;
    u32 mUnk51;
    bool mUnk52;
    bool mUnk53;
    bool mUnk54;
    bool mUnk55;
    float mUnk56;
    int mUnk57;
    u32 mUnk58;
    float mUnk59;
    float mUnk60;    // 0x341F30F8
    u32 mUnk61;      // bools or int
    u32 mUnk62;
    u32 mUnk63;    // bools
    float mUnk64;
    float mUnk65;
    u32 mUnk66;
    gstd::string mName;
    gstd::string mSkin;
    gstd::string mUnk67;
    gstd::string mUnk68;
    gstd::string *mUnk69;
    u32 mUnk70;
    u32 mUnk71;
    u32 mUnk72;
    bool mUnk73;
    u32 mUnk74;    // int? 1
    u32 mUnk75;    // int? 1
    u32 mUnk76;    // int? 7
    u32 mUnk77;    // int? 1
    float mUnk78;
    u32 mUnk79;
    float mUnk80;
    u32 mUnk81;    // bools
    u32 mUnk82;    // bools
    u32 mUnk83;
    u32 mUnk84;
    u32 mUnk85;    // bools?
    u32 mUnk86;    // -1
    u32 mUnk87;    // 0x341F316C -1
    u32 mUnk88;
    u32 mUnk89;
    u32 mUnk90;             // 1
    u32 mUnk91;             // 2
    gstd::string mLink1;    // http://127.0.0.1:8080/
    gstd::string mLink2;    // http://127.0.0.1:8085/
    gstd::string mLink3;    // http://pocket-dev.realms.minecraft.net/
    gstd::string mLink4;    // http://payments-dev.realms.minecraft.net/
    u32 mUnk92;             // 0x341F3190 3

    // ...
};

u32 s = sizeof(Options);
}    // namespace MC3DSPluginFramework