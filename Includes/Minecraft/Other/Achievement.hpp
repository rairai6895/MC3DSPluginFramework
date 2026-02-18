#pragma once

#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/Helper/GameEnums.hpp"

namespace MC3DSPluginFramework
{
    class Achievement
    {
    public:
        static inline Achievement *&SingletonInstance = *(Achievement **)0xA30FD0;

        enum : u32 {
            Unk0x26         = 0x26,
            TakingInventory = 0x27,
        };

        /*
        // FUN_0x228EB8
        static Achievement *GetInstance(void) {
            return mSingleton;
        }
        */

        void unlock(u32 id)
        {
            reinterpret_cast<void (*)(Achievement *, u32)>(0x42BFD0)(this, id);
        }

        void save(void)
        {
            mChanged = true;
            reinterpret_cast<void (*)(Achievement *)>(0x42C320)(this);
        }

    private:
        struct Entry {
            u32 mNumber;
            bool mUnlocked;
            gstd::string mName;
            u32 mUnk1;
        };

        gstd::string mFileName;    // "achievements.txt"
        MinecraftGame *mMinecraftGame;
        gstd::vector<Entry> mAchievements;
        gstd::vector<void *> mUnk1;
        u32 mUnlockCount;
        bool mChanged;
    };
}    // namespace MC3DSPluginFramework