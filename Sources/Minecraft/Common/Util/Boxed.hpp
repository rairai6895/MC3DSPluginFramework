#pragma once

#include "Minecraft/Common/Util/PoolAllocator.hpp"

namespace MC3DSPluginFramework::Util
{
    // 使い道不明
    // コンストラクタ不明
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\util/Boxed.h"
    template <typename T>
    class Boxed
    {
    public:
        void *operator new(size_t size)
        {
            if (gstd::this_thread::get_id() != gMainThread)
                LOG("This code should only be executed on the main thread", std::this_thread::get_id() == gMainThread, 0);

            if (size != mAllocator.BLOCK_SIZE)
                LOG("Wrong allocation size!", size == mAllocator.BLOCK_SIZE, 0);

            return mAllocator.alloc();
        }

        void operator delete(void *mem)
        {
            mAllocator.free(mem);
        }

        T *operator->()
        {
            if (!mPtr)
                LOG("Cannot dereference an empty pointer", mPtr, 0);

            return mPtr;
        }

        T &operator*()
        {
            if (!mPtr)
                LOG("Cannot dereference an empty pointer", mPtr, 0);

            return *mPtr;
        }

    private:
        static PoolAllocator mAllocator;

        T *mPtr;
    };
}    // namespace MC3DSPluginFramework::Util