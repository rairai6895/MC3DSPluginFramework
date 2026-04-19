#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Thread.hpp"
#include "Minecraft/gctr/gctr.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // 使い道不明
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\util\\PoolAllocator.cpp"
    class PoolAllocator
    {
    public:
        virtual ~PoolAllocator();
        virtual void Unknown1() = delete;
        virtual void Unknown2() = delete;
        virtual void Unknown3() = delete;

        // FUN_0x237774
        void *alloc()
        {
            mUnk16++;
            return gstd::malloc(BLOCK_SIZE);
        }

        void free(void *mem)
        {
            mUnk16--;
            return gstd::free(mem);
        }

        bool trim()
        {
            if (gstd::this_thread::get_id() != gMainThread)
                LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

            mMutex.lock();

            if (!mUnk13)
            {
                mMutex.unlock();
                return 0;
            }

            do
            {
                if (*mUnk5)
                    gstd::free(*mUnk5);

                reinterpret_cast<void (*)(u32 ***)>(0x8E8E34)(&mUnk5);
                mUnk16--;
            } while (mUnk13);

            mMutex.unlock();
            return 1;
        }

    private:
        // vtable 0x9A71CC

        gstd::string              mUnk1;
        u32                       mUnk2;
        gstd::map<void *, void *> mUnk3;
        size_t                    BLOCK_SIZE;
        u32                       mUnk4;    // bool?

        // ここから別のstructっぽい

        u32               **mUnk5;
        u32                 mUnk6;
        u32                 mUnk7;
        u32                 mUnk8;
        u32                 mUnk9;
        u32                 mUnk10;
        u32                 mUnk11;
        u32                 mUnk12;
        u32                 mUnk13;
        u32                 mUnk14;
        u32                 mUnk15;
        u32                 mUnk16;
        gctr::RecursiveLock mMutex;
    };
}    // namespace MC3DSPluginFramework