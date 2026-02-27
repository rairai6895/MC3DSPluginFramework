#pragma once

#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/Util/ControllBlock.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework::Util::BoxedPtr
{
    template <typename T>
    class Weak;
    // C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\util/BoxedPtr.h
    template <typename T>
    class Shared
    {
    public:
        friend Weak<T>;

        Shared() noexcept
        {
            mPtr  = nullptr;
            mBase = nullptr;

            /*
            if (ControllBlock *base = ControllBlock::alloc()) {
                base->lock();

                if (base->isAlloced()) {
                    mPtr  = nullptr;
                    mBase = base;
                    base->strongReference();
                }

                base->unlock();
            }
            */
        }

        Shared(std::nullptr_t) noexcept :
            Shared() {}

        explicit Shared(T *ptr)
        {
            mPtr  = nullptr;
            mBase = nullptr;

            if (ControllBlock *base = ControllBlock::alloc()) {
                base->lock();

                if (base->isAlloced()) {
                    mPtr  = ptr;
                    mBase = base;
                    base->strongReference();
                }

                base->unlock();
            }
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        Shared(gstd::unique_ptr<O> &&unique)
        {
            mPtr  = nullptr;
            mBase = nullptr;

            if (ControllBlock *base = ControllBlock::alloc()) {
                base->lock();

                if (base->isAlloced()) {
                    mPtr  = unique.release();
                    mBase = base;
                    base->strongReference();
                }

                base->unlock();
            }
        }

        Shared(const Shared &other)
        {
            this->mPtr  = nullptr;
            this->mBase = nullptr;

            if (other.mBase) {
                other.mBase->lock();

                if (other.mBase->isAlloced()) {
                    this->mPtr  = other.mPtr;
                    this->mBase = other.mBase;
                    other.mBase->strongReference();
                }

                other.mBase->unlock();
            }
        }

        template <typename O, typename = std::enable_if_t<std::is_convertible_v<O *, T *>>>
        Shared(Shared<O> &&other)
        {
            this->mPtr  = nullptr;
            this->mBase = nullptr;

            if (other.mBase) {
                other.mBase->lock();

                if (other.mBase->isValid()) {
                    this->mPtr  = other.mPtr;
                    this->mBase = other.mBase;
                    other.mBase->strongReference();
                }

                other.mBase->unlock();
            }

            other.mPtr  = nullptr;
            other.mBase = nullptr;
        }

        Shared(const Weak<T> &weak)
        {
            this->mPtr  = nullptr;
            this->mBase = nullptr;

            if (weak.mBase) {
                weak.mBase->lock();

                if (weak.mBase->isAlloced()) {
                    this->mPtr  = weak.mPtr;
                    this->mBase = weak.mBase;
                    weak.mBase->strongReference();
                }

                weak.mBase->unlock();
            }
        }

        ~Shared()
        {
            T *ptr              = mPtr;
            ControllBlock *base = mBase;
            mPtr                = nullptr;
            mBase               = nullptr;

            if (base) {
                base->lock();

                if (base->strongRelease() && ptr)
                    delete ptr;

                base->unlock();
            }
        }

        Shared &init(ControllBlock *base, T *ptr)
        {
            mPtr  = nullptr;
            mBase = nullptr;

            if (base) {
                base->lock();

                if (base->mAlloced) {
                    mPtr  = ptr;
                    mBase = base;
                    base->strongReference();
                }

                base->unlock();
            }

            return *this;
        }

        Shared &destroy()
        {
            T *ptr              = mPtr;
            ControllBlock *base = mBase;
            mPtr                = nullptr;
            mBase               = nullptr;

            if (base) {
                base->lock();

                if (base->strongRelease() && ptr)
                    delete ptr;

                base->unlock();
            }

            return *this;
        }

        bool unique() const noexcept
        {
            return mBase->isAlloced() && mBase->strongCount() == 1 && mBase->weakCount() == 1;
        }

        explicit operator bool() const noexcept
        {
            return mBase && mPtr;
        }

        T *operator->() const
        {
            if (!mBase) {
                LOG("Cannot dereference an empty pointer", mBase, 0);
                return nullptr;
            }

            if (!mBase->isValid())
                return nullptr;

            return mPtr;
        }

        T &operator*() const
        {
            if (!mBase) {
                LOG("Cannot dereference an empty pointer", mBase, 0);
                return *(T *)nullptr;
            }

            if (!mBase->isValid())
                return *(T *)nullptr;

            return *mPtr;
        }

        T *get() const noexcept
        {
            return mPtr;
        }

    private:
        T *mPtr;
        ControllBlock *mBase;
    };

    /*
    template <typename T, typename... Args>
    inline Shared<T> make_shared(Args &&...args)
    {
        void *mem = gstd::malloc(sizeof(T));

        if (mem)
            new (mem) T(std::forward<Args>(args)...);

        return Shared<T>(reinterpret_cast<T *>(mem));
    }
    */

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

            if (shared.mBase) {
                shared.mBase->lock();

                if (shared.mBase->isValid()) {
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

            if (base) {
                base->lock();

                // Sharedから先に破棄すると未定義動作になるので注意
                base->weakRelease();

                base->unlock();
            }
        }

    private:
        ControllBlock *mBase;
        T *mPtr;
    };
}    // namespace MC3DSPluginFramework::Util::BoxedPtr