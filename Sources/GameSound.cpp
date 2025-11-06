#include "GameSound.hpp"

namespace MC3DSPluginFramework {
namespace GameSound {

void PlaySound(const Vec3_Float &pos, u32 id, u32 data1, u32 data2) {
    if (Entity *player = Player::GetInstance())
        if (gstd::vector<u32> *vec = (gstd::vector<u32> *)player->GetWorld()->Offset(0x74))
            if (u32 SoundInstance = vec[0][4])
                Function<void>(0x74A520)(SoundInstance, id, &pos, data1, data2);
}

void Walk1(const Vec3_Float &pos, u16 blockID) {
    PlaySound(pos, 0, blockID, 1);
}

void Walk2(const Vec3_Float &pos, u16 blockID) {
    PlaySound(pos, 1, blockID, 1);
}

void Walk3(const Vec3_Float &pos, u16 blockID) {
    PlaySound(pos, 2, blockID, 0x13F);
}

void Walk4(const Vec3_Float &pos, u16 blockID) {
    PlaySound(pos, 3, blockID, 0x13F);
}

void Break(const Vec3_Float &pos, u16 blockID) {
    PlaySound(pos, 4, blockID, 1);
}

void ToolBreak(const Vec3_Float &pos) {
    PlaySound(pos, 4, -1, 1);
}

void Place(const Vec3_Float &pos, u16 blockID) {
    PlaySound(pos, 5, blockID, 1);
}

void Walk5(const Vec3_Float &pos, u16 blockID) {
    PlaySound(pos, 8, blockID, 0);
}

void Cry(const Vec3_Float &pos, EntityID entity, bool child) {
    PlaySound(pos, 0x9, child ? -1 : 0, (u32)entity);
}

void Damage1(const Vec3_Float &pos, EntityID entity, bool child) {
    PlaySound(pos, 0xC, child ? -1 : 0, (u32)entity);
}

void Damage2(const Vec3_Float &pos, EntityID entity, bool child) {
    PlaySound(pos, 0xF, child ? -1 : 0, (u32)entity);
}

void Shot(const Vec3_Float &pos) {
    PlaySound(pos, 0x14, -1, 1);
}

void Fall1(const Vec3_Float &pos) {
    PlaySound(pos, 0x17, 0, 0);
}

void Fall2(const Vec3_Float &pos) {
    PlaySound(pos, 0x18, 0, 0);
}

void Hiss1(const Vec3_Float &pos) {
    PlaySound(pos, 0x1A, 0, 0);
}

void Hiss2(const Vec3_Float &pos) {
    PlaySound(pos, 0x1A, -1, 1);
}

void Drink(const Vec3_Float &pos) {
    PlaySound(pos, 0x1D, 0, 0);
}

void Eat(const Vec3_Float &pos) {
    PlaySound(pos, 0x1E, 0, 0);
}

void Spawning(const Vec3_Float &pos) {
    PlaySound(pos, 0x21, 0, (u32)EntityID::Chicken);
}

void Unk1(const Vec3_Float &pos) {
    PlaySound(pos, 0x23, -1, 1);
}

void Throw(const Vec3_Float &pos) {
    PlaySound(pos, 0x26, 0, 0x13F);
}

void Scissors(const Vec3_Float &pos) {
    PlaySound(pos, 0x2A, -1, 1);
}

void Unk2(const Vec3_Float &pos) {
    PlaySound(pos, 0x2B, -1, 1);
}

void Boom(const Vec3_Float &pos) {
    PlaySound(pos, 0x2D, -1, 1);
}

void Fire(const Vec3_Float &pos) {
    PlaySound(pos, 0x2E, -1, 1);
}

void Ignition(const Vec3_Float &pos) {
    PlaySound(pos, 0x2F, -1, 1);
}

void ZombieCure(const Vec3_Float &pos) {
    PlaySound(pos, 0x35, -1, 1);
}

void Horror(const Vec3_Float &pos) {
    PlaySound(pos, 0x36, -1, 1);
}

void Arrow(const Vec3_Float &pos) {
    PlaySound(pos, 0x38, -1, 1);
}

void ShulkerBullet(const Vec3_Float &pos) {
    PlaySound(pos, 0x39, -1, 1);
}

void Hiss3(const Vec3_Float &pos) {
    PlaySound(pos, 0x3A, -1, 1);
}

void Chest(const Vec3_Float &pos, bool close) {
    PlaySound(pos, close ? 0x3D : 0x3C, -1, 1);
}

void ShulkerBox(const Vec3_Float &pos, bool close) {
    PlaySound(pos, close ? 0x3F : 0x3E, -1, 1);
}

void Lever(const Vec3_Float &pos, bool off) {
    PlaySound(pos, off ? 0x41 : 0x40, -1, 1);
}

void WoodenPressurePlate(const Vec3_Float &pos) {
    PlaySound(pos, 0x42, -1, 1);
}

void ArrowHit(const Vec3_Float &pos) {
    PlaySound(pos, 0x43, -1, 1);
}

void Unk3(const Vec3_Float &pos) {
    PlaySound(pos, 0x45, -1, 1);
}

void PickUp(const Vec3_Float &pos) {
    PlaySound(pos, 0x46, -1, 1);
}

void Drop(const Vec3_Float &pos) {
    PlaySound(pos, 0x47, -1, 1);
}

void SoundBlock(const Vec3_Float &pos, Instruments instr, u32 scale) {
    PlaySound(pos, 0x48, (u32)instr, scale);
}

void Piston(const Vec3_Float &pos, bool push) {
    PlaySound(pos, push ? 0x4B : 0x4A, -1, 1);
}

void NetherGate(const Vec3_Float &pos) {
    PlaySound(pos, 0x4C, -1, 1);
}

void WaterFlow(const Vec3_Float &pos) {
    PlaySound(pos, 0x4D, -1, 1);
}

void Magma1(const Vec3_Float &pos) {
    PlaySound(pos, 0x4E, -1, 1);
}

void Magma2(const Vec3_Float &pos) {
    PlaySound(pos, 0x4F, -1, 1);
}

void Burp(const Vec3_Float &pos) {
    PlaySound(pos, 0x50, -1, 1);
}

void WaterBucket(const Vec3_Float &pos, bool out) {
    PlaySound(pos, out ? 0x53 : 0x51, -1, 1);
}

void MagmaBucket(const Vec3_Float &pos, bool out) {
    PlaySound(pos, out ? 0x54 : 0x52, -1, 1);
}

void Unk4(const Vec3_Float &pos) {
    PlaySound(pos, 0x61, -1, 1);
}

void Unk5(const Vec3_Float &pos) {
    PlaySound(pos, 0x62, -1, 1);
}

void PotionBreak(const Vec3_Float &pos) {
    PlaySound(pos, 0x63, -1, 1);
}

}    // namespace GameSound
}    // namespace MC3DSPluginFramework