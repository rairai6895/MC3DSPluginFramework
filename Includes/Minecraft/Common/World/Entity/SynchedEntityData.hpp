#pragma once

#include "Minecraft/Common/World/Item/ItemInstance.hpp"
#include "Minecraft/Helper/Structs.hpp"
#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
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

        enum class DataType : u8 {
            Byte       = 0,
            Short      = 1,
            Int        = 2,
            Float      = 3,
            String     = 4,
            Vec3_Int   = 6,    // 多分
            Int64      = 7,
            Vec3_Float = 8,    // 多分
        };

        class DataItemBase
        {
        public:
            DataItemBase(DataType type, u16 id) :
                mType(type), mId(id) {}

            virtual ~DataItemBase() = default;
            inline DataType getType(void) { return mType; }

        private:
            DataType mType;
            u16 mId;    // vectorのどの位置にあるか
        };

        template <typename T>
        class DataItem : public DataItemBase
        {
        public:
            DataItem(DataType type, short id, const T &data) :
                DataItemBase(type, id), mIsDirty(true), mData(data) {}

            DataItem(const DataItem &other) :
                DataItemBase(other.type, other.id), mIsDirty(true), mData(other.mData) {}

            void *operator new(size_t size) { return gstd::malloc(size); }

            T &data(void) { return mData; }

            virtual ~DataItem() override = default;
            virtual void Unknown1(void);    // null

            virtual gstd::unique_ptr<DataItem> copy(void) { return new DataItem(*this); }

            virtual void Unknown2(void);    // null
            virtual void Unknown3(void);    // null

        private:
            bool mIsDirty;
            T mData;
        };

        // using ByteData      = DataItem<char>;
        // using ShortData     = DataItem<short>;
        // using IntData       = DataItem<int>;
        // using FloatData     = DataItem<float>;
        // using StringData    = DataItem<gstd::string>;
        // using Vec3IntData   = DataItem<Vec3_Int>;
        // using Int64Data     = DataItem<long long>;
        // using Vec3FloatData = DataItem<Vec3_Float>;

        DataItemBase *_find(u16 id) const
        {
            return reinterpret_cast<DataItemBase *(*)(const SynchedEntityData *, u16)>(0x38601C)(this, id);
        }

        /*
        inline void PutInt(short pos, const int &value) {
            reinterpret_cast<void (*)(SynchedEntityData *, short, const int &)>(0x7DF70C)(this, pos, value);
        }

        inline void PutString(short pos, gstd::string str) {
            reinterpret_cast<void (*)(SynchedEntityData *, short, gstd::string)>(0x7DF238)(this, pos, str);
        }
        */

    private:
        gstd::vector<gstd::unique_ptr<DataItemBase>> mDataList;
        u16 mUnk1;
        u16 mUnk2;
    };
}    // namespace MC3DSPluginFramework