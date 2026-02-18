#pragma once

#include "Minecraft/Common/Util/BoxedPtr.hpp"
#include "Minecraft/Helper/GameStructs.hpp"

namespace MC3DSPluginFramework
{
    class Effect
    {
    public:
        static inline Effect *&speed           = *(Effect **)0xA33560;
        static inline Effect *&slowness        = *(Effect **)0xA33564;
        static inline Effect *&haste           = *(Effect **)0xA33568;
        static inline Effect *&mining_fatigue  = *(Effect **)0xA3356C;
        static inline Effect *&strength        = *(Effect **)0xA33570;
        static inline Effect *&instant_health  = *(Effect **)0xA33574;
        static inline Effect *&instant_damage  = *(Effect **)0xA33578;
        static inline Effect *&jump_boost      = *(Effect **)0xA3357C;
        static inline Effect *&nausea          = *(Effect **)0xA33580;
        static inline Effect *&regeneration    = *(Effect **)0xA33584;
        static inline Effect *&resistance      = *(Effect **)0xA33588;
        static inline Effect *&fire_resistance = *(Effect **)0xA3358C;
        static inline Effect *&water_breathing = *(Effect **)0xA33590;
        static inline Effect *&invisibility    = *(Effect **)0xA33594;
        static inline Effect *&blindness       = *(Effect **)0xA33598;
        static inline Effect *&night_vision    = *(Effect **)0xA3359C;
        static inline Effect *&hunger          = *(Effect **)0xA335A0;
        static inline Effect *&weakness        = *(Effect **)0xA335A4;
        static inline Effect *&poison          = *(Effect **)0xA335A8;
        static inline Effect *&wither          = *(Effect **)0xA335AC;
        static inline Effect *&health_Boost    = *(Effect **)0xA335B0;
        static inline Effect *&absorption      = *(Effect **)0xA335B4;
        static inline Effect *&saturation      = *(Effect **)0xA335B8;
        static inline Effect *&levitation      = *(Effect **)0xA335BC;

        struct Data {
            void *mUnk1;
            Util::BoxedPtr::Shared<void *> mUnk2;
        };

        virtual ~Effect();
        virtual void Unknown1(void);
        virtual void Unknown2(void);
        virtual void Unknown3(void);
        virtual void Unknown4(void);
        virtual void Unknown5(void);
        virtual void Unknown6(void);
        virtual void Unknown7(void);

    private:
        size_t mId;
        bool mUnk1;
        FColor mParticleColor;
        gstd::string mKey;    // potion.name (翻訳キー)
        size_t mIconId;
        float mUnk2;
        bool mUnk3;
        gstd::string mName1;    // name
        gstd::string mName2;    // minecraft:effect.name
        Util::BoxedPtr::Shared<void *> mUnk4;    // 多分
        Util::BoxedPtr::Shared<void *> mUnk5;    // 多分
        gstd::vector<Data> mUnk6;
        gstd::vector<Data> mUnk7;
    };
}    // namespace MC3DSPluginFramework