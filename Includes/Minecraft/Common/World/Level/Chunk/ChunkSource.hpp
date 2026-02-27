#pragma once

#include "Minecraft/Common/NBT/CompoundTag.hpp"
#include "Minecraft/Common/World/Level/Chunk/ChunkRefCount.hpp"
#include "Minecraft/Common/World/Level/Dimension/Dimension.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\world\\level\\chunk\\ChunkSource.cpp"
    class ChunkSource
    {
    public:
        static u32 getFeatureId(gstd::string featureName)
        {
            return reinterpret_cast<u32 (*)(gstd::string)>(0x17C654)(featureName);
        }

        static gstd::string getFeatureName(u32 featureId)
        {
            return reinterpret_cast<gstd::string (*)(u32)>(0x17D524)(featureId);
        }

        void *operator new(size_t s)
        {
            return gstd::malloc(s);
        }

        // FUN_0x17F370
        ChunkSource(Dimension *dimension, u32 unknown)
        {
            *(u32 *)this     = 0x99A150;
            this->mUnk1      = unknown;
            this->mParent    = nullptr;
            this->mLevel     = dimension ? dimension->getLevel() : nullptr;
            this->mDimension = dimension;
            this->mUnk2      = nullptr;
        }

        // FUN_0x17F3B0
        ChunkSource(ChunkSource *parent)
        {
            *(u32 *)this     = 0x99A150;
            this->mUnk1      = parent->mUnk1;
            this->mParent    = parent;
            this->mLevel     = parent->mLevel;
            this->mDimension = parent->mDimension;
            this->mUnk2      = nullptr;
        }

        // FUN_0x17F3E4
        ChunkSource(gstd::unique_ptr<ChunkSource> &&parent) :
            mUnk1(parent->mUnk1), mLevel(parent->mLevel), mDimension(parent->mDimension), mParent(parent.get()), mUnk2(nullptr)
        {
            *(u32 *)this = 0x99A150;

            if (!parent)
                LOG("Don't pass an empty pointer dude", parent, 0);

            this->mUnk2 = std::move(parent);
        }

    public:
        virtual ~ChunkSource() = default;    // +0x0
        // deleteing destructor +0x4

        // +0x8
        virtual LevelChunk *getChunk(const ChunkPos &pos)
        {
            return nullptr;
        }

        // +0xC
        virtual LevelChunk *requestChunk(const ChunkPos &pos, u32 unknown)
        {
            if (mParent)
                return mParent->requestChunk(pos, unknown);

            return nullptr;
        }

        // +0x10
        virtual bool releaseChunk(LevelChunk *chunk)
        {
            if (mParent)
                return mParent->releaseChunk(chunk);

            return false;
        }

        // +0x14
        virtual bool postProcess(void)
        {
            LOG("This chunk source can't postprocess, but can load?", false, 0);

            return true;
        }

        // +0x18
        virtual void Unknown2()
        {
            if (mParent)
                return mParent->Unknown2();
        }

        // +0x1C
        virtual void loadChunk()
        {
            if (mParent)
                return mParent->loadChunk();
        }

        // +0x20
        virtual void Unknown3()
        {
            if (mParent)
                return mParent->Unknown3();
        }

        // +0x24
        virtual void Unknown4()
        {
            if (mParent)
                return mParent->Unknown4();
        }

        // +0x28
        virtual gstd::unique_ptr<CompoundTag> getStructureTag()
        {
            if (mParent)
                return mParent->getStructureTag();

            LOG("Invalid call: this top-level ChunkSource has no parent but can't load structure tags", false, 0);

            return gstd::make_unique<CompoundTag>();
        }

        // +0x2C
        virtual void readStructureTag(CompoundTag *tag)
        {
            if (mParent) {
                mParent->readStructureTag(tag);
                return;
            }

            LOG("Invalid call: this top-level ChunkSource has no parent but can't save structure tags", mParent, 0);
        }

        // +0x30
        virtual void saveLiveChunk(LevelChunk *lc)
        {
            if (mParent)
                return mParent->saveLiveChunk(lc);
        }

        // +0x34
        virtual void hintDiscardBatchBegin()
        {
            if (mParent)
                return mParent->hintDiscardBatchBegin();
        }

        // +0x38
        virtual void hintDiscardBatchEnd()
        {
            if (mParent)
                return mParent->hintDiscardBatchEnd();
        }

        // +0x3C
        virtual void acquireDiscarded()
        {
            if (mParent)
                return mParent->acquireDiscarded();
        }

        virtual void Unknown5(void) = delete;    // +0x40

        // vtable 0x9AF314 FUN_0x17E4F8
        // vtable 0x9C06B0 FUN_0x17E4F8

        // +0x44
        virtual gstd::map<ChunkPos, ChunkRefCount> &getStoredChunks()
        {
            if (!(mParent != nullptr))
                LOG("Method not implementable here", mParent != nullptr, 0);

            return mParent->getStoredChunks();
        }

        // +0x48
        virtual void Unknown6(void)
        {
            if (mParent)
                return mParent->Unknown6();
        }

        // +0x4C
        virtual void flushPendingWrites()
        {
            if (mParent)
                return mParent->flushPendingWrites();
        }

        virtual void Unknown7(void);    // +0x50

        // +0x54
        virtual void Unknown8(void)
        {
            if (mParent)
                return mParent->Unknown8();
        }

        virtual void Unknown9(void) = delete;    // +0x58

    protected:
        u32 mUnk1;
        Level *mLevel;
        Dimension *mDimension;
        ChunkSource *mParent;
        gstd::unique_ptr<ChunkSource> mUnk2;
    };
}    // namespace MC3DSPluginFramework