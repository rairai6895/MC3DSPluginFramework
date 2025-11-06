#ifndef WORLDCLASS_HPP
#define WORLDCLASS_HPP

#include "Function.hpp"
#include "GameEnums.hpp"
#include "Structs.hpp"
#include "gstd.hpp"

namespace MC3DSPluginFramework {

enum Weathers : u32 {
    Clear   = 1 << 0,
    Rain    = 1 << 1,
    Thunder = 1 << 2,
};

class WeatherState {
  public:
    u32 Get(void) const;
    void Set(u32 weather);

  private:
    u32 functions;
    u32 unk1;
    gstd::vector<u32> unk2;
    u32 unk3;
    float unk4;    // sky?
    float unk5;    // sky?
    float rain;
    float unk6;    // sky?
    float unk7;    // sky?
    float thunder;
};

class World {
  public:
    u32 Offset(u32 offset = 0) const;
    WeatherState *Weather(void) const;
    u32 &Seed(void) const;
    Vec3_Int &SpawnCoords(void);
    TargetType GetTargetType(void);
    Vec3_Int &TargetBlock(void);

    // bool IsEntityInsideBlock(const Entity *entity, const u8 block);

    // void PlaySoundImpl(const u32 SoundID, const Vec3_Float *pos, const u32 data1, const u32 data2, const u32 data3);

  private:
};

}    // namespace MC3DSPluginFramework

#endif