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

        Shared(T *ptr)
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

        Shared(const Shared &other)
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
                if (base->mAlloced != false) {
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

        bool unique()
        {
            return mBase->isAlloced() && mBase->strongCount() == 1 && mBase->weakCount() == 1;
        }

        T *operator->(void) const
        {
            if (!mBase) {
                LOG("Cannot dereference an empty pointer", mBase, 0);
                return nullptr;
            }

            if (!mBase->isValid())
                return nullptr;

            return mPtr;
        }

        T &operator*(void) const
        {
            if (!mBase) {
                LOG("Cannot dereference an empty pointer", mBase, 0);
                return *(T *)nullptr;
            }

            if (!mBase->isValid())
                return *(T *)nullptr;

            return *mPtr;
        }

    private:
        T *mPtr;
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