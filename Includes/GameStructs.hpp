#ifndef GAMESTRUCTS_HPP
#define GAMESTRUCTS_HPP

#include "Function.hpp"
#include "GameEnums.hpp"
#include "gstd.hpp"
#include "string"
#include "types.h"
#include <vector>

namespace MC3DSPluginFramework {

struct StatusData {
  private:
    u32 functions;
    u32 unk1;
    u32 id;
    gstd::vector<void *> vec1;
    gstd::vector<void *> vec2;
    gstd::vector<void *> vec3;
    u32 unk2[3];
    void *fakeData1;
    void *fakeData2;
    u32 unk3;

  public:
    float MaxValue;
    float CurrentValue;
};

struct EffectData {
    u32 effectID;
    u32 time;
    u32 level;
    u32 unk;
};

}    // namespace MC3DSPluginFramework

#endif