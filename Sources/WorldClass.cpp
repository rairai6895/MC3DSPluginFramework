#include "WorldClass.hpp"

namespace MC3DSPluginFramework {

u32 World::Offset(u32 offset) const {
    return (u32)this + offset;
}

WeatherState *World::Weather(void) const {
    return (WeatherState *)*(u32 *)(*(u32 *)(*(u32 *)(*(u32 *)(Offset(0x1F0)) + 0x8) + 0x14) + 0xD0);
}

u32 WeatherState::Get(void) const {
    u32 res = 0;

    if (rain)
        res |= Weathers::Rain;

    if (thunder)
        res |= Weathers::Thunder;

    if (!rain && !thunder)
        res = Weathers::Clear;

    return res;
}

void WeatherState::Set(u32 weather) {
    if (weather & Weathers::Clear) {
        rain    = 0;
        thunder = 0;
    }

    if (weather & Weathers::Rain)
        rain = 1;

    if (weather & Weathers::Thunder)
        thunder = 1;
}

u32 &World::Seed(void) const {
    return *(u32 *)Offset(0xC0);
}

Vec3_Int &World::SpawnCoords(void) {
    return *(Vec3_Int *)Offset(0xC4);
}

TargetType World::GetTargetType(void) {
    return *(TargetType *)Offset(0x248);
}

Vec3_Int &World::TargetBlock(void) {
    return *(Vec3_Int *)Offset(0x250);
}

/*
bool World::IsEntityInsideBlock(const Entity *entity, const u8 block) {
    if (entity)
        return Function(0x5CB608).Call<bool>(this, (Vec3_Float *)entity->Offset(0x288), block, entity);
    return false;
}
*/

/*
NAKED void World::PlaySoundImpl(const u32 SoundID, const Vec3_Float *pos, const u32 data1, const u32 data2, const u32 data3) {
    // (忘備録) メンバ関数の場合勝手にr0にthisが入るので引数が入っているレジスタが1つずれる。
    asm volatile(
        "push {r4-r5, lr}   \n"    // r4とr5を使用するので念のため保存しておく
        "ldr r4, [sp, #0xC] \n"    // 3つのレジスタをpushしたので元のスタックより0xC(4byte * 3)下がっているため、+0xCした位置から取り出す。
        "ldr r5, [sp, #0x10]\n"    // 引数5以降はスタックに置かれる仕様なのでdata2,3はスタックから取り出す必要がある。
        "sub sp, sp, #0xC   \n"    // pushしたlrを破壊しないようにスタックを下げて確保
        "str r4, [sp]       \n"
        "str r5, [sp, #0x4] \n"
        "str r5, [sp, #0x8] \n"
        "bl 0x5CF324        \n"    // 0x5CF324(this, soundID, position, data1, sp[0] = data2, sp[1] = data3, sp[2] = data3)
        "add sp, sp, #0xC   \n"    // スタックからlrを戻すためにスタックを上げて元の位置に戻す
        "pop  {r4-r5, lr}   \n"
        "bx   lr            \n"
    );
}
*/

}    // namespace MC3DSPluginFramework