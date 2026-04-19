#pragma once

#include "gstd_unique_ptr.hpp"
#include <memory>

namespace MC3DSPluginFramework::gstd
{
    // 所有権を持たない(勝手にdeleteをしたらいけない)ポインタを表す仮クラス
    // 実態はただのポインタ
    template <typename T>
    class reference_ptr
    {
    public:
        reference_ptr() :
            mPtr(nullptr) {}

        reference_ptr(std::nullptr_t) :
            reference_ptr() {}

        explicit reference_ptr(const gstd::unique_ptr<T> &unique) :
            mPtr(unique.get()) {}

        ~reference_ptr() = default;

        void borrow_from(const gstd::unique_ptr<T> &unique)
        {
            mPtr = unique.get();
        }

        T *get() const
        {
            return mPtr;
        }

        explicit operator bool() const
        {
            return mPtr;
        }

        T *operator*() const
        {
            return mPtr;
        }

        T *operator->() const
        {
            return mPtr;
        }

    private:
        T *mPtr;
    };
}    // namespace MC3DSPluginFramework::gstd