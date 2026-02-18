#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    class Tag
    {
    public:
        static inline gstd::string
            RepairCost,
            BlockEntityTag,
            EntityId,
            Delay,
            MinSpawnDelay,
            MaxSpawnDelay,
            SpawnCount,
            MaxNearbyEntities,
            RequiredPlayerRange,
            SpawnRange,
            CustomName,
            Unbreakable,
            customColor,
            ench,
            id,
            lvl,
            display,
            Name,
            Text1,
            Text2,
            Text3,
            Text4,
            Count,
            Damage,
            Slot,
            Items,
            Item,
            tag,
            ItemRotation;

        enum class Type {
            End,
            Byte,
            Short,
            Int,
            Int64,    // Long
            Float,
            Double,
            ByteArray,
            String,
            List,
            Compound,
            IntArray,
            Int64Array,    // 見つからなかった
        };

    public:
        Tag()
        {
            *(u32 *)this = 0x9C772C;
        }

    public:
        virtual ~Tag() = default;    // +0x0
        // deletingDestructor +0x4

        virtual void Unknown1() = delete;    // +0x8

        virtual void save(void *unknown1) {};    // +0xC
        virtual void load(void *unknown1) {};    // +0x10

        virtual void Unknown2() = delete;    // +0x14

        // +0x18
        virtual Type getType() const
        {
            return Type::End;
        };

        // +0x1C
        virtual bool operator==(const Tag &other) const
        {
            return (this->getType() == other.getType()) && (this->getTag() == other.getTag());
        }

        virtual void Unknown3() = delete;    // +0x20
        virtual void Unknown4() = delete;    // +0x24

        // +0x28
        virtual void setTag(gstd::string tag) {}

        // +0x2C
        virtual gstd::string getTag() const
        {
            return "";
        }

        // +0x30
        virtual gstd::unique_ptr<Tag> copy()
        {
            return gstd::unique_ptr<Tag>();
        };

    private:
    };
}    // namespace MC3DSPluginFramework