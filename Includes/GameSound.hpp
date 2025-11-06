#ifndef GAMESOUND_HPP
#define GAMESOUND_HPP

#include "PlayerClass.hpp"
#include "gstd.hpp"
#include <types.h>

namespace MC3DSPluginFramework {
namespace GameSound {

enum class Instruments {
    Piano     = 0,
    BassDrum  = 1,
    SnareDrum = 2,
    HihatDrum = 3,
    Bass      = 4,
};

void Walk1(const Vec3_Float &pos, u16 blockID);
void Walk2(const Vec3_Float &pos, u16 blockID);
void Walk3(const Vec3_Float &pos, u16 blockID);
void Walk4(const Vec3_Float &pos, u16 blockID);
void Break(const Vec3_Float &pos, u16 blockID);
void Place(const Vec3_Float &pos, u16 blockID);
void ToolBreak(const Vec3_Float &pos);
void Walk5(const Vec3_Float &pos, u16 blockID);
void Cry(const Vec3_Float &pos, EntityID entity, bool child);
void Damage1(const Vec3_Float &pos, EntityID entity, bool child);
void Damage2(const Vec3_Float &pos, EntityID entity, bool child);
void Shot(const Vec3_Float &pos);
void Fall1(const Vec3_Float &pos);
void Fall2(const Vec3_Float &pos);
void Hiss1(const Vec3_Float &pos);
void Hiss2(const Vec3_Float &pos);
void Drink(const Vec3_Float &pos);
void Eat(const Vec3_Float &pos);
void Spawning(const Vec3_Float &pos);
void Unk1(const Vec3_Float &pos);
void Throw(const Vec3_Float &pos);
void Scissors(const Vec3_Float &pos);
void Unk2(const Vec3_Float &pos);
void Boom(const Vec3_Float &pos);
void Fire(const Vec3_Float &pos);
void Ignition(const Vec3_Float &pos);
void ZombieCure(const Vec3_Float &pos);
void Horror(const Vec3_Float &pos);
void Arrow(const Vec3_Float &pos);
void ShulkerBullet(const Vec3_Float &pos);
void Hiss3(const Vec3_Float &pos);
void Chest(const Vec3_Float &pos, bool close);
void ShulkerBox(const Vec3_Float &pos, bool close);
void Lever(const Vec3_Float &pos, bool off);
void WoodenPressurePlate(const Vec3_Float &pos);
void ArrowHit(const Vec3_Float &pos);
void Unk3(const Vec3_Float &pos);    // IronBlock?
void PickUp(const Vec3_Float &pos);
void Drop(const Vec3_Float &pos);
void SoundBlock(const Vec3_Float &pos, Instruments instr, u32 scale);
void Piston(const Vec3_Float &pos, bool push);
void NetherGate(const Vec3_Float &pos);
void WaterFlow(const Vec3_Float &pos);
void Magma1(const Vec3_Float &pos);
void Magma2(const Vec3_Float &pos);
void Burp(const Vec3_Float &pos);
void WaterBucket(const Vec3_Float &pos, bool out);
void MagmaBucket(const Vec3_Float &pos, bool out);
void Unk4(const Vec3_Float &pos);
void Unk5(const Vec3_Float &pos);
void PotionBreak(const Vec3_Float &pos);

};    // namespace GameSound
}    // namespace MC3DSPluginFramework

#endif