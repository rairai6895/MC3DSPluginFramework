#ifndef GAMEENUMS_HPP
#define GAMEENUMS_HPP

#include "types.h"

enum GameModes : u8 {
    Survival,
    Creative,
    Adventure,
    Spectator_S,
    Spectator_C,
};

enum class TargetType : u8 {
    Block  = 0,
    Entity = 1,
    None   = 3,
};

enum Dimensions : u8 {
    OverWorld,
    Nether,
    End,
};

enum class Ability : u32 {
    CanFly        = 0xA33AD4,
    IsInvincible  = 0xA33AE0,
    IsFlying      = 0xA33AE4,
    InfiniteItems = 0xA33AE8,
    Lightning     = 0xA33AEC,
    FlySpeed      = 0xA33AF0,
    WalkSpeed     = 0xA33AF4,
    NoClip        = 0xA33AF8,
};

enum class Status : u32 {
    Health              = 0xA33338,
    FollowRange         = 0xA33340,
    KnockbackResistance = 0xA33348,
    Movement            = 0xA33350,    // Speed
    AtackDamage         = 0xA33358,
    Absorption          = 0xA33360,
    Luck                = 0xA33368,
    FallDamage          = 0xA33370,
    HorseJumpStrength   = 0xA33378,
    Hunger              = 0xA33B5C,
    Saturation          = 0xA33B64,
    Exhaustion          = 0xA33B6C,    // 空腹ゲージが減るまでの時間
    Level               = 0xA33B74,
    XP                  = 0xA33B7C,
};

enum class Effects : u32 {
    Speed           = 0xA33560,    // 1
    Slowness        = 0xA33564,    // 2
    Haste           = 0xA33568,    // 3
    Mining_Fatigue  = 0xA3356C,    // 4
    Strength        = 0xA33570,    // 5
    Instant_Health  = 0xA33574,    // 6
    Instant_Damage  = 0xA33578,    // 7
    Jump_boost      = 0xA3357C,    // 8
    Nausea          = 0xA33580,    // 9
    Regeneration    = 0xA33584,    // 10
    Resistance      = 0xA33588,    // 11
    Fire_Resistance = 0xA3358C,    // 12
    Water_Breathing = 0xA33590,    // 13
    Invisibility    = 0xA33594,    // 14
    Blindness       = 0xA33598,    // 15
    Night_Vision    = 0xA3359C,    // 16
    Hunger          = 0xA335A0,    // 17
    Weakness        = 0xA335A4,    // 18
    Poison          = 0xA335A8,    // 19
    Wither          = 0xA335AC,    // 20
    Health_Boost    = 0xA335B0,    // 21
    Absorption      = 0xA335B4,    // 22
    Saturation      = 0xA335B8,    // 23
    Levitation      = 0xA335BC,    // 24
};

enum class ActionFlags : u32 {
    None      = 0,
    Burning   = 1 << 0,     // 0x1, 燃えている
    Sneak     = 1 << 1,     // 0x2, スニーク
    Sprint    = 1 << 3,     // 0x8, ダッシュ
    Eating    = 1 << 4,     // 0x10, 食べる
    Invisible = 1 << 5,     // 0x20, 透明化
    ElytraFly = 1 << 30,    // 0x40000000, エリトラ飛行中
};

enum class EntityVtable : u32 {
    CaveSpider           = 0x9952CC,
    EnderEye             = 0x996078,
    Item                 = 0x996C54,
    SilverFish           = 0x997CCC,
    Wither               = 0x998E98,
    EnderDragon          = 0x99A8C4,
    FishingHook          = 0x99B120,
    Player               = 0x99C31C,
    TNT_Trolley          = 0x99C9B8,
    Mooshroom            = 0x99CF50,
    WitherHead           = 0x99F0A8,
    EndCrystal           = 0x9A002C,
    FallingBlock         = 0x9A0424,
    Potion               = 0x9A2A80,
    XpOrb                = 0x9A48F4,
    FireCharge           = 0x9A5684,
    Thunder              = 0x9A5D98,
    Chest_Trolley        = 0x9A62FC,
    ShulkerBullet        = 0x9A77C0,
    FireCharge_Mini      = 0x9A7B60,
    DragonBreathBullet   = 0x9A97EC,
    Hopper_Trolley       = 0x9AB598,
    Zombie_Villager      = 0x9ADDD4,
    Unknown1             = 0x9AE50C,
    Evoker               = 0x9B2C4C,
    XpBottle             = 0x9B30D4,
    Trolley              = 0x9B3C4C,
    Enderpearl           = 0x9B5D3C,
    Vindicator           = 0x9BAE74,
    Lead                 = 0x9BE774,
    CommandBlock_Trolley = 0x9BECD8,
    Bat                  = 0x9C651C,
    Cow                  = 0x9C69A0,
    Pig                  = 0x9C72A8,
    Vex                  = 0x9C7768,
    Boat                 = 0x9C7C30,
    Wolf                 = 0x9C80DC,
    Arrow                = 0x9C8560,
    Blaze                = 0x9C88C4,
    Ghast                = 0x9C8F2C,
    Horse                = 0x9C93B0,
    Llama                = 0x9C9A5C,
    Sheep                = 0x9C9F2C,
    Slime                = 0x9CA3B0,
    Squid                = 0x9CA85C,
    Witch                = 0x9CAD00,
    Unknown2             = 0x9CB70C,
    Cat                  = 0x9CBA2C,
    Rabbit               = 0x9CC538,
    Spider               = 0x9CCCB0,
    Zombie               = 0x9CD140,
    Chicken              = 0x9CD860,
    Creeper              = 0x9CDCF4,
    Shulker              = 0x9CEC14,
    Enderman             = 0x9CFC9C,
    Guardian             = 0x9D04F8,
    Skeleton             = 0x9D19B4,
    Snowball             = 0x9D1E8C,
    Villager             = 0x9D241C,
    EnderMite            = 0x9D3D94,
    Golem                = 0x9D49C4,
    MagmaCube            = 0x9D4E78,
    LlamaBreath          = 0x9D5558,
    Pigman               = 0x9D5AEC,
    PolarBear            = 0x9D5F74,
    TNT                  = 0x9D63F8,
    SnowGolem            = 0x9D7418,
    Egg                  = 0x9D8030,
};

enum class EntityID {
    Chicken                = 0x130A,
    Cow                    = 0x130B,
    Pig                    = 0x130C,
    Sheep                  = 0x130D,
    Wolf                   = 0x530E,
    Villager               = 0x30F,
    Mooshroom              = 0x1310,
    Squid                  = 0x2311,
    Rabbit                 = 0x1312,
    Bat                    = 0x8113,
    Iron_Golem             = 0x314,
    Snow_Golem             = 0x315,
    Ocelot                 = 0x5316,
    Horse                  = 0x205317,
    Llama                  = 0x131D,
    PolarBear              = 0x131C,
    Donkey                 = 0x205318,
    Mule                   = 0x205319,
    Skelton_Horse          = 0x215B1A,
    Zombie_Horse           = 0x215B1B,
    Zombie                 = 0x30B20,
    Creeper                = 0xB21,
    Skelton                = 0x110B22,
    Spider                 = 0x40B23,
    Zombie_Pigman          = 0x10B24,
    Slime                  = 0xB25,
    EnderMan               = 0xB26,
    SilverFish             = 0x40B27,
    CaveSpider             = 0x40B28,
    Ghast                  = 0xB29,
    MagmaCube              = 0xB2A,
    Blaze                  = 0xB2B,
    Zombie_Villager        = 0x30B2C,
    Witch                  = 0xB2D,
    Stray                  = 0x110B2E,
    Husk                   = 0x30B2F,
    Wither_Skelton         = 0x110B30,
    Guardian               = 0xB31,
    Elder_Guardian         = 0xB32,
    Vindicator             = 0xB39,
    Wither                 = 0x10B34,
    Ender_Dragon           = 0xB35,
    Shulker                = 0xB36,
    Ender_Mite             = 0x40B37,
    Player                 = 0x13F,
    Item                   = 0x40,
    TNT                    = 0x41,
    UNK1                   = 0x42,
    XPbottle               = 0x400044,
    XPOrb                  = 0x45,
    EyeOfEnder             = 0x46,
    EnderCrystal           = 0x47,
    ShulkerBullet          = 0x40004C,
    UNK2                   = 0x4D,
    DragonBreath           = 0x40004F,
    Arrow                  = 0x400050,
    SnowBall               = 0x400051,
    Egg                    = 0x400052,
    UNK3                   = 0x400053,
    Minecart               = 0x80054,
    FireCharge             = 0x400055,
    Potion                 = 0x400056,
    Enderpearl             = 0x400057,
    Lead                   = 0x400058,
    WitherHead             = 0x400059,
    Boat                   = 0x5A,
    WitherHead_Blue        = 0x5B,
    Thunder                = 0x5D,
    Blaze_Bullet           = 0x40005E,
    UNK4                   = 0x5F,
    Hopper_Minecart        = 0x80060,
    TNT_Minecart           = 0x80061,
    Chest_Minecart         = 0x80062,
    Command_Block_Minecart = 0x80064,
    Potion2                = 0x400065,
    LlamaBreath            = 0x400066,
    UNK5                   = 0x400067,
    Evocation_Illager      = 0xB68,
    Vex                    = 0xB69,
};

enum class CreativeMenuCategory : u16 {
    Building_Blocks        = 1,
    Decorations            = 2,
    RedStone_and_Transport = 3,
    Food_and_Materials     = 4,
    Tools                  = 5,
    Brewing                = 6,
    Miscellaneous          = 7,
};

enum class Enchants {
    Protection,
    Fire_Protection,
    Feather_Falling,
    Blast_Protection,
    Projectile_Protection,
    Thorns,
    Respiration,
    Depth_Strider,
    Aqua_Affinity,
    Sharpness,
    Smite,
    Bane_of_Afthropods,
    Knockback,
    Fire_Aspect,
    Looting,
    Efficiency,
    Silk_Touch,
    Unbreaking,
    Fortune,
    Power,
    Punch,
    Flame,
    Infinity,
    Luck_of_the_Sea,
    Lure,
    Frost_Walker,
    Mending,
};

enum class ParticleID {
    bubble                              = 1,    // 色付け可能
    basic_crit_particle                 = 2,
    black_block                         = 3,    // 雲？
    basic_smoke_particle1               = 4,
    elephant_tooth_paste_vapor_particle = 5,
    misc_fire_vapor_particle            = 6,
    basic_flame_particle                = 7,
    lava_particle                       = 8,
    basic_smoke_particle2               = 9,
    redstone_ore_dust_particle          = 0xA,
    falling_border_dust_particle        = 0xB,
    egg                                 = 0xC,
    snowball                            = 0xD,
    large_explosion                     = 0xE,
    huge_explosion_emitter              = 0xF,
    mobflame_single                     = 0x10,
    heart_particle                      = 0x11,
    block_fragment                      = 0x12,
    Water                               = 0x13,
    basic_portal_particle               = 0x14,
    water_splash_particle               = 0x15,
    water_splash_particle_manual        = 0x16,
    water_wake_particle                 = 0x17,
    lava_drip_particle                  = 0x18,
    falling_dust                        = 0x19,    // 色付け可能
    arrow_spell_emitter                 = 0x1A,    // 色付け可能
    mobspell_emitter                    = 0x1B,    // 色付け可能
    rising_border_dust_particle         = 0x1C,    // 色付け可能
    falling_dust_black                  = 0x1D,
    oozing_ambient                      = 0x1E,
    // water_splash_particle_manual        = 0x1F,
    villager_angry                    = 0x20,
    villager_happy                    = 0x21,
    lab_table_misc_mystical_particle  = 0x22,
    note_particle                     = 0x24,
    infested_emitter                  = 0x25,    // ウィッチが出すモヤモヤ？
    carrot                            = 0x26,
    endrod                            = 0x28,
    eyeofender_death_explode_particle = 0x29,
    explosion_particle                = 0x2A,
    totem_manual                      = 0x2B,
};

enum class EntityActionSet {
    BlockBreaking    = 0x7D1,    // ブロック破壊パーティクル
    Potion           = 0x7D2,    // ポーションが割れる
    DeathDust1       = 0x7D3,
    DeathDust2       = 0x7D4,
    Guardian         = 0x7D6,    // ガーディアンの呪いモーション
    EnderDust1       = 0x7DA,
    EnderDust2       = 0x7DD,
    Dust             = 0x7DF,
    Door             = 0x3EB,
    Ignition         = 0x3ED,
    Anvil            = 0x3FE,
    Drop             = 0x406,    // ドロップ音
    EndermanTeleport = 0x407,    // テレポート音
    PickXP           = 0x41B,
    Lever            = 0xDAC,    // data = 258 or 1F4
};

// A3472C~ BlockTileData

#endif