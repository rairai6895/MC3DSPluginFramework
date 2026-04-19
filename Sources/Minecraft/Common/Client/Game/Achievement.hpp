#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    struct Achievement
    {
        int          mIconNum;
        int          mId;    // 表示順関係？
        gstd::string mLocalizeKey;
        float        mUnk1;    // 表示順関係？
    };

    namespace AchievementID
    {
        // そのうちまとめる
        enum {
            Acquire_Hardware = 0,
            Dry_Spell        = 1,
            Unk0x26          = 0x26,
            TakingInventory  = 0x27,
        };
    }    // namespace AchievementID

    class MinecraftGame;

    class AchievementManager
    {
        USE_GAME_ALLOCATOR
    private:
        static inline AchievementManager *&instance = *(AchievementManager **)0xA30FD0;

    public:
        // FUN_0x228EB8
        static AchievementManager *getInstance()
        {
            return instance;
        }

        void unlock(int achievement)
        {
            reinterpret_cast<void (*)(AchievementManager *, int)>(0x42BFD0)(this, achievement);
        }

        void save()
        {
            mChanged = true;
            reinterpret_cast<void (*)(AchievementManager *)>(0x42C320)(this);
        }

    private:
        gstd::string                       mFileName;    // 　+0x0 "achievements.txt"
        MinecraftGame                     *mMinecraftGame;    // 　+0x4
        gstd::vector<Achievement>          mAchievements;    // 　+0x8
        gstd::vector<gstd::type_unknown<>> mUnk1;    // 　+0x14
        int                                mUnlockCount;
        bool                               mChanged;
    };
}    // namespace MC3DSPluginFramework