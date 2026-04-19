#pragma once

#include "gstd_reference_ptr.hpp"

namespace MC3DSPluginFramework::gstd
{
    // 一時的所有ポインタ
    template <typename T>
    class temporary_ptr
    {
    public:
        temporary_ptr() :
            mPtr(nullptr) {}

        explicit temporary_ptr(T *ptr) :
            mPtr(ptr) {}

        ~temporary_ptr() = default;

        temporary_ptr &operator=(T *ptr)
        {
            mPtr = ptr;
            return *this;
        }

        T *get(void) { return mPtr; }

        gstd::unique_ptr<T> adopt(void)
        {
            gstd::unique_ptr<T> res(mPtr);
            mPtr = nullptr;
            return std::move(res);
        }

        explicit operator bool(void) const { return mPtr; }
        T        operator*(void) const { return *mPtr; }
        T       *operator->(void) const { return mPtr; }

    private:
        T *mPtr;
    };
}    // namespace MC3DSPluginFramework::gstd