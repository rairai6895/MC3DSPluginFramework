#include "SynchedEntityData.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x386194
    SynchedEntityData::SynchedEntityData() :
        mMinDirty(0xFFFF),
        mMaxDirty(0)
    {
    }

    void SynchedEntityData::setDirty(DataItemBase &item)
    {
        item.setDirty();
        mMinDirty = std::min(mMinDirty, item.getId());
        mMaxDirty = std::max(mMaxDirty, item.getId());
    }

    void SynchedEntityData::resetDirty()
    {
        for (int i = mMinDirty; i <= mMaxDirty; ++i)
            mDataItems[i]->resetDirty();

        mMinDirty = 0xFFFF;
        mMaxDirty = 0;
    }

    // FUN_0x6F2CEC
    SynchedEntityData::DataItemBase *SynchedEntityData::_find(u16 id) const
    {
        // 未初期化値を避けるため？
        return id < mDataItems.size() ? mDataItems[id].get() : nullptr;
    }

    // FUN_0x38601C
    SynchedEntityData::DataItemBase &SynchedEntityData::_get(u16 id) const
    {
        if (!_find(id))
            LOG("Data item not found", _find(id), 0);

        return *_find(id);
    }

    gstd::string &SynchedEntityData::getString(u16 id) const
    {
        DataItemBase *item = _find(id);

        if (!item || item->getType() != DataTypeMap::typeFor<gstd::string>())
            return Util::EMPTY_STRING;

        return reinterpret_cast<DataItem<gstd::string> *>(item)->mData;
    }
}    // namespace MC3DSPluginFramework