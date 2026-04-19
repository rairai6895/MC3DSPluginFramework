#pragma once

#include "../Attribute/Attribute.hpp"
#include "Minecraft/Common/Util/BoxedPtr.hpp"
#include "Minecraft/src-deps/Core/Math/Color.hpp"

namespace MC3DSPluginFramework
{
    class Effect
    {
    public:
        static inline gstd::unique_ptr<Effect>
            &speed           = *(gstd::unique_ptr<Effect> *)0xA33560,
            &slowness        = *(gstd::unique_ptr<Effect> *)0xA33564,
            &haste           = *(gstd::unique_ptr<Effect> *)0xA33568,
            &mining_fatigue  = *(gstd::unique_ptr<Effect> *)0xA3356C,
            &strength        = *(gstd::unique_ptr<Effect> *)0xA33570,
            &instant_health  = *(gstd::unique_ptr<Effect> *)0xA33574,
            &instant_damage  = *(gstd::unique_ptr<Effect> *)0xA33578,
            &jump_boost      = *(gstd::unique_ptr<Effect> *)0xA3357C,
            &nausea          = *(gstd::unique_ptr<Effect> *)0xA33580,
            &regeneration    = *(gstd::unique_ptr<Effect> *)0xA33584,
            &resistance      = *(gstd::unique_ptr<Effect> *)0xA33588,
            &fire_resistance = *(gstd::unique_ptr<Effect> *)0xA3358C,
            &water_breathing = *(gstd::unique_ptr<Effect> *)0xA33590,
            &invisibility    = *(gstd::unique_ptr<Effect> *)0xA33594,
            &blindness       = *(gstd::unique_ptr<Effect> *)0xA33598,
            &night_vision    = *(gstd::unique_ptr<Effect> *)0xA3359C,
            &hunger          = *(gstd::unique_ptr<Effect> *)0xA335A0,
            &weakness        = *(gstd::unique_ptr<Effect> *)0xA335A4,
            &poison          = *(gstd::unique_ptr<Effect> *)0xA335A8,
            &wither          = *(gstd::unique_ptr<Effect> *)0xA335AC,
            &health_Boost    = *(gstd::unique_ptr<Effect> *)0xA335B0,
            &absorption      = *(gstd::unique_ptr<Effect> *)0xA335B4,
            &saturation      = *(gstd::unique_ptr<Effect> *)0xA335B8,
            &levitation      = *(gstd::unique_ptr<Effect> *)0xA335BC;

        struct Data
        {
            Attribute                             &mAttribute;
            BoxedPtr::Shared<gstd::type_unknown<>> m0x4;
        };

        int getId() const
        {
            return mId;
        }

        virtual ~Effect();
        virtual void Unknown1(void);
        virtual void Unknown2(void);
        virtual void Unknown3(void);
        virtual void Unknown4(void);
        virtual void Unknown5(void);
        virtual void Unknown6(void);
        virtual void Unknown7(void);

    private:
        int                                    mId;    // +0x4
        bool                                   m0x8;
        Color                                  mColor;    // +0xC
        gstd::string                           mLocalizeKey;    // +0x1C potion.name
        int                                    mIconId;    // +0x20
        float                                  m0x24;
        bool                                   m0x28;
        gstd::string                           m0x2C;    // name
        gstd::string                           m0x30;    // minecraft:effect.name
        BoxedPtr::Shared<gstd::type_unknown<>> m0x34;
        BoxedPtr::Shared<gstd::type_unknown<>> m0x3C;
        gstd::vector<Data>                     m0x44;
        gstd::vector<Data>                     m0x50;
    };
}    // namespace MC3DSPluginFramework