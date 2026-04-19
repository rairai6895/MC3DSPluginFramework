#include "synchronization.hpp"
#include "3ds/synchronization.h"
#include "gsvc.hpp"

namespace MC3DSPluginFramework::gctr
{

    static Handle &arbiter = *(Handle *)0xA35768;

    Result __sync_init()
    {
        // return svcCreateAddressArbiter(&arbiter);
        return reinterpret_cast<Result (*)()>(0x108690)();
    }

    // FUN_0x11B53C
    LightLock::LightLock()
    {
        do
        {
            __ldrex(&mState);
        } while (__strex(&mState, 1));
    }

    void LightLock::lock()
    {
        reinterpret_cast<void (*)(LightLock *)>(0x11B554)(this);
    }

    // FUN_0x1230D8
    void LightLock::unlock()
    {
        s32 val = 0;

        while (true)
        {
            val = __ldrex(&mState);

            if (__strex(&mState, -val))
                continue;

            // 1(ロック所持+待機スレッド0) or 負数(ロック未所持)の場合リターン
            if (val <= 1)
                return;

            gsvc::ArbitrateAddress(arbiter, (u32)this, ARBITRATION_SIGNAL, 1, 0);
        }
    }

    // 本来はクラス形式ではない。
    // ゲーム内ではmCounterに初期値として0xFFFFFFFFが書き込まれる処理がある
    // FUN_0x12314C
    RecursiveLock::RecursiveLock() :
        mLock(), mThread_tag(0), mCounter(0)
    {
    }

    // FUN_0x123170
    void RecursiveLock::lock()
    {
        u32 tls = (u32)getThreadLocalStorage();

        if (mThread_tag != tls)
        {
            mLock.lock();
            mThread_tag = tls;
        }

        mCounter++;
    }

    // FUN_0x1231B0
    void RecursiveLock::unlock()
    {
        mCounter--;

        if (mCounter != 0)
            return;

        mThread_tag = 0;
        mLock.unlock();
    }

    bool RecursiveLock::isLocked()
    {
        return mThread_tag != 0;
    }

}    // namespace MC3DSPluginFramework::gctr