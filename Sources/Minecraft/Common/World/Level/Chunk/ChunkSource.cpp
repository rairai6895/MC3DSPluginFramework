#include "ChunkSource.hpp"
#include "../Dimension/Dimension.hpp"

namespace MC3DSPluginFramework
{
    u32 ChunkSource::getFeatureId(gstd::string featureName)
    {
        return reinterpret_cast<u32 (*)(gstd::string)>(0x17C654)(featureName);
    }

    gstd::string ChunkSource::getFeatureName(u32 featureId)
    {
        return reinterpret_cast<gstd::string (*)(u32)>(0x17D524)(featureId);
    }

    // FUN_0x17F370
    ChunkSource::ChunkSource(Dimension *dimension, int p1) :
        mUnk1(p1),
        mParent(nullptr),
        mLevel(dimension ? dimension->getLevel() : nullptr),
        mDimension(dimension),
        mUnk2(nullptr)
    {
    }

    // FUN_0x17F3B0
    ChunkSource::ChunkSource(ChunkSource *parent) :
        mUnk1(parent->mUnk1),
        mParent(parent),
        mLevel(parent->mLevel),
        mDimension(parent->mDimension),
        mUnk2(nullptr)
    {
    }

    // FUN_0x17F3E4
    ChunkSource::ChunkSource(gstd::unique_ptr<ChunkSource> &&parent) :
        mUnk1(parent->mUnk1),
        mLevel(parent->mLevel),
        mDimension(parent->mDimension),
        mParent(parent.get()),
        mUnk2(nullptr)
    {
        if (!parent)
            LOG("Don't pass an empty pointer dude", parent, 0);

        this->mUnk2 = std::move(parent);
    }

    // FUN_0x17E660
    // +0x8
    LevelChunk *ChunkSource::getChunk(const ChunkPos &pos)
    {
        return nullptr;
    }

    // FUN_0x17CED8
    // +0xC
    LevelChunk *ChunkSource::requestChunk(const ChunkPos &pos, u32 unknown)
    {
        return mParent ? mParent->requestChunk(pos, unknown) : nullptr;
    }

    // FUN_0x17CEBC
    // +0x10
    bool ChunkSource::releaseChunk(LevelChunk *chunk)
    {
        return mParent ? mParent->releaseChunk(chunk) : false;
    }

    // FUN_0x17C5CC
    // +0x14
    bool ChunkSource::postProcess()
    {
        LOG("This chunk source can't postprocess, but can load?", false, 0);
        return true;
    }

    // FUN_0x17F354
    // +0x18
    void ChunkSource::Unknown2()
    {
        if (mParent)
            return mParent->Unknown2();
    }

    // FUN_0x17E86C
    // +0x1C
    void ChunkSource::loadChunk()
    {
        if (mParent)
            return mParent->loadChunk();
    }

    // FUN_0x17F330
    // +0x20
    void ChunkSource::Unknown3()
    {
        if (mParent)
            return mParent->Unknown3();
    }

    // FUN_0x17E668
    // +0x24
    void ChunkSource::Unknown4()
    {
        if (mParent)
            return mParent->Unknown4();
    }

    // FUN_0x6A01A8
    // +0x28
    gstd::unique_ptr<CompoundTag> ChunkSource::getStructureTag()
    {
        if (mParent)
            return mParent->getStructureTag();

        LOG("Invalid call: this top-level ChunkSource has no parent but can't load structure tags", false, 0);

        return gstd::make_unique<CompoundTag>();
    }

    // FUN_0x17E684
    // +0x2C
    void ChunkSource::readStructureTag(CompoundTag *tag)
    {
        if (mParent)
        {
            mParent->readStructureTag(tag);
            return;
        }

        LOG("Invalid call: this top-level ChunkSource has no parent but can't save structure tags", mParent, 0);
    }

    // FUN_0x17D508
    // +0x30
    void ChunkSource::saveLiveChunk(LevelChunk *lc)
    {
        if (mParent)
            return mParent->saveLiveChunk(lc);
    }

    // FUN_0x17EF30
    // +0x34
    void ChunkSource::hintDiscardBatchBegin()
    {
        if (mParent)
            return mParent->hintDiscardBatchBegin();
    }

    // FUN_0x17E92C
    // +0x38
    void ChunkSource::hintDiscardBatchEnd()
    {
        if (mParent)
            return mParent->hintDiscardBatchEnd();
    }

    // FUN_0x17E644
    // +0x3C
    void ChunkSource::acquireDiscarded(gstd::unique_ptr<LevelChunk> &lc)
    {
        if (mParent)
            return mParent->acquireDiscarded(lc);
    }

    // FUN_0x17E4F8
    // +0x44
    gstd::map<ChunkPos, ChunkRefCount> &ChunkSource::getStoredChunks()
    {
        if (!(mParent != nullptr))
            LOG("Method not implementable here", mParent != nullptr, 0);

        return mParent->getStoredChunks();
    }

    // FUN_0x17F158
    // +0x48
    void ChunkSource::Unknown6()
    {
        if (mParent)
            return mParent->Unknown6();
    }

    // FUN_0x17E8C0
    // +0x4C
    void ChunkSource::flushPendingWrites()
    {
        if (mParent)
            return mParent->flushPendingWrites();
    }

    // FUN_0x17E898
    // +0x54
    void ChunkSource::Unknown8()
    {
        if (mParent)
            return mParent->Unknown8();
    }
}    // namespace MC3DSPluginFramework