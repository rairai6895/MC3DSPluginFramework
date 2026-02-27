#pragma once

#include "gstd_alloc.hpp"

namespace MC3DSPluginFramework::gstd
{
    template <typename T>
    class unique_ptr
    {
    public:
        unique_ptr() :
            mPtr(nullptr) {}

        explicit unique_ptr(T *ptr) :
            mPtr(ptr) {}

        unique_ptr(unique_ptr &&other)
        {
            mPtr       = other.mPtr;
            other.mPtr = nullptr;
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        unique_ptr(unique_ptr<O> &&other) noexcept
        {
            mPtr = other.release();
        }

        ~unique_ptr()
        {
            if (mPtr)
                delete mPtr;
        }

        T *get(void) const { return mPtr; }

        T *release(void)
        {
            T *tmp = mPtr;
            mPtr   = nullptr;
            return tmp;
        }

        unique_ptr &operator=(unique_ptr &&other)
        {
            if (this != &other) {
                if (mPtr)
                    delete mPtr;

                mPtr       = other.mPtr;
                other.mPtr = nullptr;
            }

            return *this;
        }

        unique_ptr &operator=(T *ptr)
        {
            if (this->mPtr != ptr) {
                if (mPtr)
                    delete mPtr;

                mPtr = ptr;
            }

            return *this;
        }

        explicit operator bool(void) const
        {
            return mPtr;
        }

        T operator*(void) const
        {
            return *mPtr;
        }

        T *operator->(void) const
        {
            return mPtr;
        }

    private:
        T *mPtr;
    };

    // 基本的にgstd::mallocを使用するoperator newを持たないオブジェクトで使う用
    template <typename T, typename... Args>
    inline gstd::unique_ptr<T> make_unique(Args &&...args)
    {
        void *mem = gstd::malloc(sizeof(T));

        if (mem)
            new (mem) T(std::forward<Args>(args)...);

        return gstd::unique_ptr<T>(reinterpret_cast<T *>(mem));
    }

}    // namespace MC3DSPluginFramework::gstd