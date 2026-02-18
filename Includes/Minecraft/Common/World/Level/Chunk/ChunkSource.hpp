#pragma once

#include "Minecraft/Common/NBT/CompoundTag.hpp"
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

        // FUN_0x17F3E4
        ChunkSource(gstd::unique_ptr<ChunkSource> &&parent)
        {
            ChunkSource *_parent = parent.get();

            *(u32 *)this     = 0x99A150;
            this->mUnk1      = _parent->mUnk1;
            this->mLevel     = _parent->mLevel;
            this->mDimension = _parent->mDimension;
            this->mParent    = _parent;
            this->mUnk2      = nullptr;

            if (!parent)
                LOG("Don't pass an empty pointer dude", parent, 0);

            this->mUnk2 = std::move(parent);
        }

    public:
        virtual ~ChunkSource();    // +0x0
        // deleteing destructor +0x4

        virtual LevelChunk *getChunk(const ChunkPos &pos);    // +0x8
        virtual LevelChunk *requestChunk(const BlockPos &pos, u32 unknown);    // +0xC
        virtual bool releaseChunk(LevelChunk *chunk);    // +0x10
        virtual bool postProcess(void);    // +0x14
        virtual void Unknown2();    // +0x18
        virtual void loadChunk();    // +0x1C
        virtual void Unknown3();    // +0x20
        virtual void Unknown4();    // +0x24
        virtual gstd::unique_ptr<CompoundTag> getStructureTag(void);    // +0x28
        virtual void readStructureTag(CompoundTag *);    // +0x2C
        virtual void saveLiveChunk(LevelChunk *);    // +0x30
        virtual void hintDiscardBatchBegin();    // +0x34
        virtual void hintDiscardBatchEnd();    // +0x38
        virtual void acquireDiscarded();    // +0x3C
        virtual void Unknown4(void) = delete;    // +0x40

        // vtable 0x9AF314 FUN_0x17E4F8
        // vtable 0x9C06B0 FUN_0x17E4F8
        virtual gstd::map<Vec3_Int, LevelChunk *> &getStoredChunks(void);    // +0x44
        virtual void Unknown5(void);    // +0x48
        virtual void flushPendingWrites();    // +0x4C
        virtual void Unknown6(void);    // +0x50
        virtual void Unknown7(void);    // +0x54
        virtual void Unknown8(void) = delete;    // +0x58
        // virtual void Unknown9(void)  = delete;    // +0x5C
        // virtual void Unknown10(void) = delete;    // +0x60

    private:
        u32 mUnk1;
        Level *mLevel;
        Dimension *mDimension;
        ChunkSource *mParent;
        gstd::unique_ptr<ChunkSource> mUnk2;
    };
}    // namespace MC3DSPluginFramework