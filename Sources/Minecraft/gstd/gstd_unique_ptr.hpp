#pragma once

#include <cstddef>
#include <type_traits>
#include <utility>

namespace MC3DSPluginFramework::gstd
{
    template <typename _Tp>
    class unique_ptr
    {
    public:
        template <typename>
        friend class unique_ptr;

        unique_ptr() :
            mPtr(nullptr) {}

        unique_ptr(std::nullptr_t) :
            unique_ptr() {}

        explicit unique_ptr(_Tp *p) :
            mPtr(p) {}

        template <typename _Up, typename = std::enable_if_t<std::is_convertible_v<_Up *, _Tp *>>>
        explicit unique_ptr(_Up *p) :
            mPtr(p) {}

        unique_ptr(unique_ptr &&other)
        {
            mPtr       = other.mPtr;
            other.mPtr = nullptr;
        }

        template <typename _Up, typename = std::enable_if_t<std::is_convertible_v<_Up *, _Tp *>>>
        unique_ptr(unique_ptr<_Up> &&other)
        {
            mPtr       = other.mPtr;
            other.mPtr = nullptr;
        }

        ~unique_ptr()
        {
            delete mPtr;
        }

        void reset()
        {
            delete mPtr;

            mPtr = nullptr;
        }

        _Tp *release()
        {
            _Tp *tmp = mPtr;
            mPtr     = nullptr;
            return tmp;
        }

        _Tp *get() const
        {
            return mPtr;
        }

        unique_ptr &operator=(unique_ptr &&other)
        {
            if (this != &other)
            {
                this->reset();

                mPtr       = other.mPtr;
                other.mPtr = nullptr;
            }

            return *this;
        }

        template <typename _Up, typename = std::enable_if_t<std::is_convertible_v<_Up *, _Tp *>>>
        unique_ptr &operator=(unique_ptr<_Up> &&other)
        {
            this->reset();

            mPtr       = other.mPtr;
            other.mPtr = nullptr;

            return *this;
        }

        unique_ptr &operator=(std::nullptr_t)
        {
            this->reset();
            return *this;
        }

        _Tp &operator*() const
        {
            return *mPtr;
        }

        _Tp *operator->() const
        {
            return mPtr;
        }

        bool operator==(_Tp *p) const
        {
            return mPtr == p;
        }

        explicit operator bool() const
        {
            return mPtr != nullptr;
        }

    private:
        _Tp *mPtr;
    };

    template <typename _Tp, typename... _Args>
    inline unique_ptr<_Tp> make_unique(_Args &&...args)
    {
        return unique_ptr<_Tp>(new _Tp(std::forward<_Args>(args)...));
    }

}    // namespace MC3DSPluginFramework::gstd