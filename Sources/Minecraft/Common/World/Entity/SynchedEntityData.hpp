#pragma once

#include "../Item/ItemInstance.hpp"
#include "../Level/BlockPos.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // そのうち整理する

    // C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\project\\3DS\\..\\..\\src\\common\\world/entity/SynchedEntityData.h
    class SynchedEntityData
    {
    public:
        enum ID : u16 {
            EntityState = 0,
            Oxygen      = 7,
            EffectColor = 8,
            Size        = 0x27,
            MaxOxygen   = 0x2C,
        };

        enum class EntitySharedFlag {
            Burning    = 0,
            Sneak      = 1,
            Sprint     = 3,
            Eating     = 4,
            InVisible  = 5,
            IsTempted  = 6,
            Love       = 7,
            Saddled    = 8,
            Baby       = 0xB,
            Named      = 0xE,
            Sitting    = 0x17,
            Angry      = 0x18,
            Tamed      = 0x1B,
            Sheared    = 0x1D,
            Gliding    = 0x1E,
            Chested    = 0x22,
            ShowBottom = 0x24,
        };

        enum class DataType : u8 {
            Byte     = 0,
            Short    = 1,
            Int      = 2,
            Float    = 3,
            String   = 4,
            BlockPos = 6,
            Int64    = 7,
            Vec3     = 8,
        };

        class DataTypeMap
        {
        public:
            template <typename T>
            static DataType typeFor();
        };

        class DataItemBase
        {
        public:
            DataItemBase(DataType type, u16 id) :
                mType(type),
                mId(id),
                mDirty(true)
            {
            }

            virtual ~DataItemBase() = default;

            DataType getType()
            {
                return mType;
            }

            u16 getId()
            {
                return mId;
            }

            bool isDirty()
            {
                return mDirty;
            }

            void setDirty()
            {
                mDirty = true;
            }

            void resetDirty()
            {
                mDirty = false;
            }

        private:
            DataType mType;    // +0x4
            u16      mId;    // +0x6
            bool     mDirty;    // +0x8
        };

        template <typename T>
        class DataItem : public DataItemBase
        {
            USE_GAME_ALLOCATOR
        public:
            DataItem(DataType type, short id, const T &data) :
                DataItemBase(type, id), mData(data) {}

            DataItem(const DataItem &other) :
                DataItemBase(other.mType, other.mId), mData(other.mData) {}

            virtual ~DataItem() override = default;
            virtual void Unknown1()      = delete;

            virtual gstd::unique_ptr<DataItem> copy()
            {
                return gstd::make_unique<DataItem>(*this);
            }

            virtual void Unknown2() = delete;
            virtual void Unknown3() = delete;

            T mData;
        };

        SynchedEntityData();

        void          setDirty(DataItemBase &item);
        void          resetDirty();
        DataItemBase *_find(u16 id) const;
        DataItemBase &_get(u16 id) const;

        // get系はテンプレートかもだけど、stringだけ参照返しで最適化されてるのか、別関数にしてるのかわからない

        gstd::string &getString(u16 id) const;

        template <typename T>
        bool getFlag(u16 id, int flag)
        {
            DataItemBase *item = _find(id);

            if (!item)
                return false;

            if (!(_find(id)->getType() == DataTypeMap::typeFor<T>()))
                LOG("Wrong value type for this ID!", _find(id)->getType() == DataTypeMap::typeFor<T>(), 0);

            return reinterpret_cast<DataItem<T> *>(item)->mData & (1 << flag);
        }

        template <typename T>
        void setFlag(u16 id, int flag)
        {
            if (!(_get(id).getType() == DataTypeMap::typeFor<T>()))
                LOG("Wrong value type for this ID!", _get(id).getType() == DataTypeMap::typeFor<T>(), 0);

            DataItem<T> *item     = reinterpret_cast<DataItem<T> *>(&_get(id));
            bool         prevFlag = item->mData & flag;
            item->mData |= (1 << flag);

            if ((item->mData & flag) != prevFlag)
                item->setDirty();
        }

        template <typename T>
        void clearFlag(u16 id, int flag)
        {
            if (!(_get(id).getType() == DataTypeMap::typeFor<T>()))
                LOG("Wrong value type for this ID!", _get(id).getType() == DataTypeMap::typeFor<T>(), 0);

            DataItem<T> *item     = reinterpret_cast<DataItem<T> *>(&_get(id));
            bool         prevFlag = item->mData & flag;
            item->mData &= ~(1 << flag);

            if ((item->mData & flag) != prevFlag)
                item->setDirty();
        }

    private:
        gstd::vector<gstd::unique_ptr<DataItemBase>> mDataItems;
        u16                                          mMinDirty;
        u16                                          mMaxDirty;
    };

#define MAPPING(type, enum)                                                            \
    template <>                                                                        \
    inline SynchedEntityData::DataType SynchedEntityData::DataTypeMap::typeFor<type>() \
    {                                                                                  \
        return enum;                                                                   \
    }

    MAPPING(char, SynchedEntityData::DataType::Byte)
    MAPPING(short, SynchedEntityData::DataType::Short)
    MAPPING(int, SynchedEntityData::DataType::Int)
    MAPPING(float, SynchedEntityData::DataType::Float)
    MAPPING(gstd::string, SynchedEntityData::DataType::String)
    MAPPING(BlockPos, SynchedEntityData::DataType::BlockPos)
    MAPPING(s64, SynchedEntityData::DataType::Int64)
    MAPPING(Vec3<float>, SynchedEntityData::DataType::Vec3)

}    // namespace MC3DSPluginFramework