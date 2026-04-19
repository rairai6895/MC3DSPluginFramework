#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class MinecraftOptionValue;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\options\\Options.cpp"
    class Options
    {
        USE_GAME_ALLOCATOR
    public:
        enum class Type {
            Byte,
            Float,
            String,
            Int,
        };

        using Option = std::pair<Type, gstd::string>;

        static inline const Option
            &music                           = *(Option *)0xA31C4C,
            &sound                           = *(Option *)0xA31C54,
            &invertYAxis                     = *(Option *)0xA31C5C,
            &sensitivity                     = *(Option *)0xA31C64,
            &renderDistance                  = *(Option *)0xA31C6C,
            &particleRenderDistance          = *(Option *)0xA31C74,
            &viewBobbing                     = *(Option *)0xA31C7C,
            &limitFramerate                  = *(Option *)0xA31C84,
            &difficulty                      = *(Option *)0xA31C8C,
            &graphics                        = *(Option *)0xA31C94,
            &transparentleaves               = *(Option *)0xA31C9C,
            &uiprofile                       = *(Option *)0xA31CA4,
            &guiScale_optionName             = *(Option *)0xA31CAC,
            &dev_use_fps_independent_turning = *(Option *)0xA31CB4,
            &filelocation_title              = *(Option *)0xA31CBC,
            &thirdperson                     = *(Option *)0xA31CC4,
            &hidegui                         = *(Option *)0xA31CCC,
            &multiplayergame                 = *(Option *)0xA31CD4,
            &servervisible                   = *(Option *)0xA31CDC,
            &xboxlivevisible                 = *(Option *)0xA31CE4,
            &lefthanded                      = *(Option *)0xA31CEC,
            &usetouchscreen                  = *(Option *)0xA31CF4,
            &usetouchpad                     = *(Option *)0xA31CFC,
            &swapJumpAndSneak                = *(Option *)0xA31D04,
            &destroyvibration                = *(Option *)0xA31D0C,
            &autojump                        = *(Option *)0xA31D14,
            &toggleCrouch                    = *(Option *)0xA31D1C,
            &resourcepacks                   = *(Option *)0xA31D24,
            &fancyskies                      = *(Option *)0xA31D2C,
            &buttonSize                      = *(Option *)0xA31D34,
            &name                            = *(Option *)0xA31D3C,
            &skin                            = *(Option *)0xA31D44,
            &worldsizelimit                  = *(Option *)0xA31D4C,
            &gamma                           = *(Option *)0xA31D54,
            &dev_createRealmWithoutPurchase  = *(Option *)0xA31D5C,
            &dev_offersUnlocked              = *(Option *)0xA31D64,
            &dev_storeOfferQueryRequiresXbl  = *(Option *)0xA31D6C,
            &dev_renderBoundingBox           = *(Option *)0xA31D74,
            &dev_renderPaths                 = *(Option *)0xA31D7C,
            &dev_renderGoalState             = *(Option *)0xA31D84,
            &dev_resetClientId               = *(Option *)0xA31D8C,
            &fullscreen                      = *(Option *)0xA31D94,
            &fov                             = *(Option *)0xA31D9C,
            &msaa                            = *(Option *)0xA31DA4,
            &texelAA                         = *(Option *)0xA31DAC,
            &maxFramerate                    = *(Option *)0xA31DB4,
            &dev_enableDebugHudOverlay       = *(Option *)0xA31DBC,
            &dev_showBuildInfo               = *(Option *)0xA31DC4,
            &showAdvancedVideoSettings       = *(Option *)0xA31DCC,
            &dev_showChunkMap                = *(Option *)0xA31DD4,
            &dev_enableProfiler              = *(Option *)0xA31DDC,
            &dev_achievementsAlwaysEnabled   = *(Option *)0xA31DE4,
            &dev_useLocalServer              = *(Option *)0xA31DEC,
            &dev_useIPv6Only                 = *(Option *)0xA31DF4,
            &dev_connectionQuality           = *(Option *)0xA31DFC,
            &dev_useRetailXboxSandbox        = *(Option *)0xA31E04,
            &dev_realmsEnvironment           = *(Option *)0xA31E0C,
            &dev_realmsEndpoint              = *(Option *)0xA31E14,
            &dev_realmsEndpointPayment       = *(Option *)0xA31E1C,
            &dev_realmsRelyingParty          = *(Option *)0xA31E24,
            &dev_realmsRelyingPartyPayment   = *(Option *)0xA31E2C;

        Options(gstd::string unknown1 /* "extdata:/" */, u8 unknown2, gstd::unique_ptr<MinecraftOptionValue> &&unknown3, u32 unknown4);
        void  setFloat(const Option &option, float value);
        float getFloat(const Option &option);
        void  setByte(const Option &option, u8 value);
        u8    getByte(const Option &option);
        void  setInt(const Option &option, int value);
        int   getInt(const Option &option);

    private:
        gstd::string        mFile;    // +0 options.txt
        u32                 mUnk1;    // +0x4
        u32                 mUnk2;    // +0x8
        u32                 mUnk3;    // +0xC
        std::vector<void *> mOptionObserversBool;    // +0x10
        std::vector<void *> mOptionObserversFloat;    // +0x1C
        std::vector<void *> mOptionObserversInt;    // +0x28
        std::vector<void *> mOptionObserversString;    // +0x34
        std::vector<void *> mOptionLocks;    // +0x40
        u8                  mUnk9;    // +0x4C
        float               mMusic;    // +0x50
        float               mSound;    // +0x54
        float               mSensitivity1;    // +0x58  // unknown
        float               mSensitivity2;    // +0x5C // unknown
        bool                mInvertYAxis;    // +0x60
        int                 mRenderDistance;    // +0x64
        u32                 mUnk10;    // +0x68
        bool                mViewBobbing;    // +0x6C
        bool                mLimitFramerate;    // +0x6D
        bool                mGraphics;    // +0x6E  // particle
        bool                mTransparentleaves;    // +0x6F
        bool                mUnk11;    // +0x70
        bool                mUnk12;    // +0x71
        bool                mUnk13;    // +0x72
        bool                mUnk14;    // +0x73
        bool                mAutojump;    // +0x74 // 0x341F3054
        bool                mUnk15;    // +0x75
        bool                mUnk16;    // +0x76
        char                mUnk17;    // +0x77
        void               *mUnk18;    // +0x78
        void               *mUnk19;    // +0x7C
        void               *mUnk20;    // +0x80
        void               *mUnk21;    // +0x84
        u32                 mUnk22;    // +0x88
        void               *mUnk23;    // +0x8C
        void               *mUnk24;    // +0x90
        gstd::string        mLanguageLocale;    // +0x94   // 0x341F3074
        int                 mUnk25;    // +0x98
        u32                 mUnk26;    // +0x9C
        u32                 mUnk27;    // +0xA0
        u32                 mUnk28;    // +0xA4
        u32                 mUnk29;    // +0xA8
        u32                 mUnk30;    // +0xAC  // 0x341F308C
        u32                 mUnk31;
        u32                 mUnk32;
        u32                 mUnk33;
        u32                 mUnk34;
        u32                 mUnk35;
        u32                 mUnk36;
        u32                 mUnk37;
        u32                 mUnk38;
        u32                 mUnk39;
        u32                 mUnk40;
        u32                 mUnk41;    // 0x341F30B8
        u32                 mUnk42;
        u32                 mUnk43;
        u32                 mUnk44;
        u32                 mUnk45;
        u32                 mUnk46;
        u32                 mUnk47;    // 0x341F30D0
        u32                 mUnk48;
        u32                 mUnk49;
        u32                 mUnk50;
        u32                 mUnk51;
        bool                mUnk52;
        bool                mUnk53;
        bool                mUnk54;
        bool                mUnk55;
        float               mUnk56;
        int                 mUnk57;
        u32                 mUnk58;
        float               mUnk59;
        float               mUnk60;    // 0x341F30F8
        u32                 mUnk61;    // bools or int
        u32                 mUnk62;
        u32                 mUnk63;    // bools
        float               mUnk64;
        float               mUnk65;
        u32                 mUnk66;
        gstd::string        mName;
        gstd::string        mSkin;
        gstd::string        mUnk67;
        gstd::string        mUnk68;
        gstd::string       *mUnk69;
        u32                 mUnk70;
        u32                 mUnk71;
        u32                 mUnk72;
        bool                mUnk73;
        u32                 mUnk74;    // int? 1
        u32                 mUnk75;    // int? 1
        u32                 mUnk76;    // int? 7
        u32                 mUnk77;    // int? 1
        float               mUnk78;
        u32                 mUnk79;
        float               mUnk80;
        u32                 mUnk81;    // bools
        u32                 mUnk82;    // bools
        u32                 mUnk83;
        u32                 mUnk84;
        u32                 mUnk85;    // bools?
        u32                 mUnk86;    // -1
        u32                 mUnk87;    // 0x341F316C -1
        u32                 mUnk88;
        u32                 mUnk89;
        u32                 mUnk90;    // 1
        u32                 mUnk91;    // 2
        gstd::string        mLink1;    // http://127.0.0.1:8080/
        gstd::string        mLink2;    // http://127.0.0.1:8085/
        gstd::string        mLink3;    // http://pocket-dev.realms.minecraft.net/
        gstd::string        mLink4;    // http://payments-dev.realms.minecraft.net/
        u32                 mUnk92;    // 0x341F3190 3

        // ...
    };
}    // namespace MC3DSPluginFramework