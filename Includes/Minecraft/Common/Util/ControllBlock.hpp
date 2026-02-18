#pragma once

#include "Minecraft/gctr/gctr_synchronization.hpp"

namespace MC3DSPluginFramework::Util
{
    class ControllBlock
    {
    public:
        static ControllBlock *alloc(void)
        {
            return reinterpret_cast<ControllBlock *(*)()>(0x110E50)();
        }

        // FUN_0x123168
        void lock(void)
        {
            mLock.lock();
        }

        // FUN_0x1231A8
        void unlock(void)
        {
            mLock.unlock();
        }

        // FUN_0x119C54
        void weakReference(void)
        {
            mWeakCount++;
        }

        // FUN_0x119C64
        void strongReference(void)
        {
            mStrongCount++;
            mWeakCount++;
        }

        // FUN_0x110D9C
        void weakRelease(void)
        {
            if (0 < mWeakCount) {
                mWeakCount--;

                if (mWeakCount) {
                    return;
                }

                if (mStrongCount == 0 && mWeakCount == 0 && mAlloced) {
                    AllocatorMutex.lock();

                    if (mFreePrev) {
                        mFreePrev->mFreeNext = mFreeNext;
                    }
                    if (mFreeNext) {
                        mFreeNext->mFreePrev = mFreePrev;
                    }
                    else {
                        *(ControllBlock **)(0xA32AAC + 8) = mFreePrev;
                    }

                    mFreePrev                         = *(ControllBlock **)(0xA32AAC + 4);
                    *(ControllBlock **)(0xA32AAC + 4) = this;

                    mAlloced = false;
                    AllocatorMutex.unlock();
                    return;
                }
            }

            // ここでFUN_0x125160を呼ぶが、ただのエラー処理なので省略
        }

        // FUN_0x119C80
        bool strongRelease(void)
        {
            // strongReferenceでStrongCountとWeakCount両方増えるからWeakCountが1以下の場合おかしい
            if (0 < mStrongCount && mWeakCount < 1) {
                // ここでFUN_0x125160を呼ぶが、ただのエラー処理なので省略
                return false;
            }

            mStrongCount--;
            mWeakCount--;

            if (mStrongCount == 0) {
                // Weakが残っている状態でStrongを消すのはおかしい
                // どこも所有してないのに、Releaseを呼ぶのはおかしい
                if (mWeakCount != 0 || !mAlloced) {
                    // ここでFUN_0x125160を呼ぶが、ただのエラー処理なので省略
                    return false;
                }

                AllocatorMutex.lock();

                if (mFreePrev) {
                    mFreePrev->mFreeNext = mFreeNext;
                }
                if (mFreeNext) {
                    mFreeNext->mFreePrev = mFreePrev;
                }
                else {
                    *(ControllBlock **)(0xA32AAC + 8) = mFreePrev;
                }
                mFreePrev                         = *(ControllBlock **)(0xA32AAC + 4);
                *(ControllBlock **)(0xA32AAC + 4) = this;

                mAlloced = false;
                AllocatorMutex.unlock();
                return true;
            }
            return false;
        }

        bool isAlloced(void) const
        {
            return mAlloced;
        }

        // FUN_0x119D4C
        bool isValid(void) const
        {
            return mAlloced && 0 < mWeakCount && 0 < mStrongCount;
        }

        u32 strongCount() const
        {
            return mStrongCount;
        }

        u32 weakCount() const
        {
            return mWeakCount;
        }

    private:
        static inline gctr::RecursiveLock &AllocatorMutex = *(gctr::RecursiveLock *)0xAC6E84;

        u32 mStrongCount;
        u32 mWeakCount;
        bool mAlloced;
        ControllBlock *mFreePrev;
        ControllBlock *mFreeNext;
        gctr::RecursiveLock mLock;
    };
}    // namespace MC3DSPluginFramework::Util