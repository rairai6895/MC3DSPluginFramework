#ifndef GAMESTRUCTS_HPP
#define GAMESTRUCTS_HPP

#include "Function.hpp"
#include "GameEnums.hpp"
#include "gstd.hpp"
#include "string"
#include "types.h"
#include <vector>

namespace MC3DSPluginFramework {

struct ItemData {
  private:
    u32 unk1;

  public:
    u8 maxStack;

  private:
    u8 unk2[3];

  public:
    char *atlasName;

  private:
    u32 unk3;
    u16 unk4;

  public:
    u16 itemID;
    char *name1;
    char *name2;

  private:
    u8 unk5[2];

  public:
    u16 durability;
    bool enchantEffect;

  private:
    u8 unk6[2];

  public:
    bool disablePlacement;

  private:
    u32 unk7[2];

  public:
    u8 blockID;
    bool canEat;

  private:
    u8 unk8[2];
    u32 unk9[5];
};

struct EnchantStatus {
    Enchants id;
    u32 level;
};

struct EnchantArgs {
  private:
    u32 data1 = 0x7FFF;

  public:
    MC3DSPluginFramework::gstd::vector<EnchantStatus> enchants;

  private:
    u32 data3[7];
};

struct SlotData {
    u8 count;

  private:
    u8 unk1;

  public:
    u16 dataValue;

  private:
    u32 unk2;

  public:
    u32 enchant;
    ItemData *itemdata;
    u32 renderID;

    u16 category;
    u16 number;

  private:
    u8 unk3[24];

    static inline Function<void>::Const<SlotData *, u16, u8, u16> constructor_default  = 0x1D2894;
    static inline Function<void>::Const<SlotData *, void *, u8, u16> constructor_block = 0x1D2704;
    static inline Function<void>::Const<SlotData *, const SlotData &> constructor_copy = 0x1D2768;
    static inline Function<void>::Const<SlotData *> destructor                         = 0x1D20E0;
    static inline Function<void>::Const<u32> destructor_enchant                        = 0x182588;
    static inline Function<void>::Const<SlotData *, const EnchantArgs &> give_enchant  = 0x1D1670;

  public:
    SlotData() {
        constructor_default(this, 0, 0, 0);
    };

    SlotData(u16 itemID, u8 count, u16 dataValue) {
        constructor_default(this, itemID, count, dataValue);
    }

    // block 0xA3472C~
    SlotData(void *block, u8 count, u16 dataValue) {
        constructor_block(this, block, count, dataValue);
    }

    SlotData(const SlotData &other) {
        constructor_copy(this, other);
    }

    SlotData(SlotData &&other) noexcept {
        memcpy(this, &other, sizeof(SlotData));
        memset(&other, 0, sizeof(SlotData));
    }

    ~SlotData() {
        destructor(this);
    }

    SlotData &operator=(const SlotData &other) {
        if (this != &other) {
            if (u32 ench = enchant) {
                constructor_copy(this, other);
                destructor_enchant(ench);
            } else
                constructor_copy(this, other);
        }
        return *this;
    }

    SlotData &operator=(SlotData &&other) noexcept {
        if (this != &other) {
            if (u32 ench = enchant) {
                memcpy(this, &other, sizeof(SlotData));
                memset(&other, 0, sizeof(SlotData));
                destructor_enchant(ench);
            } else {
                memcpy(this, &other, sizeof(SlotData));
                memset(&other, 0, sizeof(SlotData));
            }
        }
        return *this;
    }

    inline EnchantArgs GetEnchants(void) {
        EnchantArgs args{};
        Function<void>(0x6B25EC)(&args, this);
        return args;
    }

    inline void AddEnchant(Enchants id, u32 level) {
        EnchantArgs args = GetEnchants();
        args.enchants.push_back({id, level});
        give_enchant(this, args);
    }

    inline void Enchant(Enchants id, u32 level) {
        EnchantArgs args{};
        args.enchants.push_back({id, level});
        give_enchant(this, args);
    }

    inline void Enchant(const std::initializer_list<EnchantStatus> &enchants) {
        EnchantArgs args{};
        args.enchants = enchants;
        give_enchant(this, args);
    }

    inline void Enchant(const std::vector<EnchantStatus> &enchants) {
        EnchantArgs args{};
        args.enchants = std::move(MC3DSPluginFramework::gstd::vector<EnchantStatus>(enchants.begin(), enchants.end()));
        give_enchant(this, args);
    }

    inline int GetDurability(void) {
        auto data = (ItemData *)itemdata;
        if (data && data->durability)
            return data->durability - dataValue;
        return 0;
    }

    inline const std::string GetName(void) {
        if (itemdata)
            return ((ItemData *)itemdata)->name2;
        return "";
    }

    inline bool CheckName(const std::string &name) const {
        if (itemdata)
            return ((ItemData *)itemdata)->name2 == name;
        return false;
    }
};

struct StatusData {
  private:
    u32 functions;
    u32 unk1;
    u32 id;
    MC3DSPluginFramework::gstd::vector<void *> vec1;
    MC3DSPluginFramework::gstd::vector<void *> vec2;
    MC3DSPluginFramework::gstd::vector<void *> vec3;
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