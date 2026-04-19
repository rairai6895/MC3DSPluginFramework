#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Util/ControllBlock.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework::BoxedPtr
{
    template <typename T>
    class Weak;

    // C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\util/BoxedPtr.h
    template <typename T>
    class Shared
    {
    private:
        static void _strongRelease(ControllBlock *base, T *ptr)
        {
            if (base)
            {
                base->lock();

                if (base->strongRelease() && ptr)
                    delete ptr;

                base->unlock();
            }
        }

        void _strongReference(ControllBlock *base, T *ptr)
        {
            if (base)
            {
                base->lock();

                if (base->isAlloced())
                {
                    this->mBase = base;
                    this->mPtr  = ptr;
                    base->strongReference();
                }

                base->unlock();
            }
        }

        void init(ControllBlock *base, T *ptr)
        {
            T             *old_ptr  = this->mPtr;
            ControllBlock *old_base = this->mBase;
            this->mPtr              = nullptr;
            this->mBase             = nullptr;
            _strongReference(base, ptr);
            _strongRelease(old_base, old_ptr);
        }

    public:
        friend Weak<T>;

        template <typename O>
        friend class Shared;

        Shared() noexcept
        {
            mPtr  = nullptr;
            mBase = nullptr;
        }

        Shared(std::nullptr_t) noexcept :
            Shared() {}

        explicit Shared(T *ptr) :
            Shared()
        {
            _strongReference(ControllBlock::alloc(), ptr);
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        Shared(gstd::unique_ptr<O> unique) :
            Shared()
        {
            _strongReference(ControllBlock::alloc(), unique.release());
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        Shared(const Shared<O> &other) :
            Shared()
        {
            _strongReference(other.mBase, other.mPtr);
        }

        Shared(const Shared &other) :
            Shared()
        {
            _strongReference(other.mBase, other.mPtr);
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        Shared(Shared<O> &&other)
        {
            mPtr        = other.mPtr;
            mBase       = other.mBase;
            other.mPtr  = nullptr;
            other.mBase = nullptr;
        }

        Shared(const Weak<T> &weak) :
            Shared()
        {
            if (weak.mBase && weak.mBase->isValid())
                _strongReference(weak.mBase, weak.mPtr);
        }

        ~Shared()
        {
            T             *ptr  = mPtr;
            ControllBlock *base = mBase;
            mPtr                = nullptr;
            mBase               = nullptr;
            _strongRelease(base, ptr);
        }

        bool unique() const noexcept
        {
            return mBase->unique();
        }

        T *get() const noexcept
        {
            if (mBase && mBase->isValid())
                return mPtr;

            return nullptr;
        }

        void reset()
        {
            init(nullptr, nullptr);
        }

        explicit operator bool() const noexcept
        {
            return get();
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        bool operator==(const Shared<O> &other) const noexcept
        {
            return this->get() == other.get();
        }

        bool operator==(std::nullptr_t) const noexcept
        {
            return !get();
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        Shared &operator=(const Shared<O> &other)
        {
            if (this != &other)
                this->init(other.mBase, other.mPtr);

            return *this;
        }

        Shared &operator=(const Shared &other)
        {
            if (this != &other)
                this->init(other.mBase, other.mPtr);

            return *this;
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        Shared &operator=(Shared<O> &&other)
        {
            if (this != &other)
            {
                mPtr        = other.mPtr;
                mBase       = other.mBase;
                other.mPtr  = nullptr;
                other.mBase = nullptr;
            }

            return *this;
        }

        Shared &operator=(Shared &&other)
        {
            if (this != &other)
            {
                mPtr        = other.mPtr;
                mBase       = other.mBase;
                other.mPtr  = nullptr;
                other.mBase = nullptr;
            }

            return *this;
        }

        T *operator->() const
        {
            if (!mBase)
            {
                LOG("Cannot dereference an empty pointer", mBase, 0);
                return nullptr;
            }

            if (!mBase->isValid())
                return nullptr;

            return mPtr;
        }

        T &operator*() const
        {
            if (!mBase)
            {
                LOG("Cannot dereference an empty pointer", mBase, 0);
                return *(T *)nullptr;
            }

            if (!mBase->isValid())
                return *(T *)nullptr;

            return *mPtr;
        }

    private:
        T             *mPtr;
        ControllBlock *mBase;
    };

    // C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\util/BoxedPtr.h
    template <typename T>
    class Weak
    {
    public:
        friend Shared<T>;

        Weak(const Shared<T> &shared)
        {
            this->mPtr  = nullptr;
            this->mBase = nullptr;

            if (shared.mBase)
            {
                shared.mBase->lock();

                if (shared.mBase->isValid())
                {
                    this->mBase = shared.mBase;
                    this->mPtr  = shared.mPtr;
                    shared.mBase->weakReference();
                }

                shared.mBase->unlock();
            }
        }

        ~Weak()
        {
            ControllBlock *base = mBase;
            mBase               = nullptr;
            mPtr                = nullptr;

            if (base)
            {
                base->lock();
                base->weakRelease();
                base->unlock();
            }
        }

        Shared<T> lock() const
        {
            return Shared<T>(*this);
        }

        // そのうちoperator->とか追加する

    private:
        ControllBlock *mBase;
        T             *mPtr;
    };
}    // namespace MC3DSPluginFramework::BoxedPtr