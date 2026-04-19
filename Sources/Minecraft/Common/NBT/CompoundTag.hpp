#pragma once

#include "Helpers/Macro.hpp"
#include "Minecraft/Common/Logger.hpp"
#include "Minecraft/Common/NBT/ByteArrayTag.hpp"
#include "Minecraft/Common/NBT/ByteTag.hpp"
#include "Minecraft/Common/NBT/DoubleTag.hpp"
#include "Minecraft/Common/NBT/EndTag.hpp"
#include "Minecraft/Common/NBT/FloatTag.hpp"
#include "Minecraft/Common/NBT/Int64Tag.hpp"
#include "Minecraft/Common/NBT/IntArrayTag.hpp"
#include "Minecraft/Common/NBT/IntTag.hpp"
#include "Minecraft/Common/NBT/ListTag.hpp"
#include "Minecraft/Common/NBT/NamedTag.hpp"
#include "Minecraft/Common/NBT/ShortTag.hpp"
#include "Minecraft/Common/NBT/StringTag.hpp"
#include "Minecraft/Common/NBT/Tag.hpp"
#include "Minecraft/Common/Util/StringUtils.hpp"
#include "TagMap.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\nbt\\CompoundTag.cpp"
    class CompoundTag : public NamedTag
    {
        USE_GAME_ALLOCATOR
    public:
        MACRO_MAKE_PAIR(TagData, gstd::string, name, gstd::unique_ptr<Tag>, tag);
        using Tags = gstd::vector<TagData>;

        // FUN_0x182464
        CompoundTag() :
            NamedTag(""),
            mTagMap()
        {
            *(u32 *)this = 0x99A3F4;
        }

        CompoundTag(gstd::string parent) :
            NamedTag(parent)
        {
            *(u32 *)this = 0x99A3F4;
        }

        CompoundTag(gstd::string parent, Tags &&tags) :
            NamedTag(parent)
        {
            for (auto &data : tags)
                mTagMap[data.name] = std::move(data.tag);

            *(u32 *)this = 0x99A3F4;
        }

        gstd::unique_ptr<CompoundTag> _copy() const
        {
            return reinterpret_cast<gstd::unique_ptr<CompoundTag> (*)(const CompoundTag *)>(0x6A0CF4)(this);
        }

        void put(TagData &&put)
        {
            mTagMap[put.name] = std::move(put.tag);
        }

        // FUN_0x6A0C74
        Tag *get(const gstd::string &name) const
        {
            return mTagMap.get(name);
        }

        // FUN_0x6A10E0
        bool contains(const gstd::string &name) const
        {
            return !(mTagMap.find(name) == mTagMap.size());
        }

        // FUN_0x6A1114
        bool contains(const gstd::string &name, Tag::Type type) const
        {
            Tag *tag = get(name);
            return tag ? tag->getType() == type : false;
        }

        // FUN_0x1818C8
        bool remove(const gstd::string &name)
        {
            if (contains(name))
            {
                mTagMap.erase(name);
                return true;
            }

            return false;
        }

        // FUN_0x18184C
        void putByte(const gstd::string &name, char value)
        {
            mTagMap[name] = gstd::make_unique<ByteTag>(value);
        }

        // FUN_
        void putShort(const gstd::string &name, short value)
        {
            mTagMap[name] = gstd::make_unique<ShortTag>(value);
        }

        // FUN_0x181EA0
        void putInt(const gstd::string &name, int value)
        {
            mTagMap[name] = gstd::make_unique<IntTag>(value);
        }

        // FUN_0x182130
        void putString(const gstd::string &name, const gstd::string &value)
        {
            mTagMap[name] = gstd::make_unique<StringTag>(value);
        }

        // FUN_0x181978
        void putByteArray(const gstd::string &name, const std::pair<size_t, gstd::string> &array)
        {
            mTagMap[name] = gstd::make_unique<ByteArrayTag>(array);
        }

        // FUN_0x181914
        void putCompound(const gstd::string &name, gstd::unique_ptr<CompoundTag> compound)
        {
            compound->setTag(name);
            mTagMap[name] = std::move(compound);
        }

        // FUN_
        void putList(const gstd::string &name, gstd::unique_ptr<ListTag> list)
        {
            mTagMap[name] = std::move(list);
        }

        bool                            getBool(const gstd::string &name) const;
        char                            getByte(const gstd::string &name) const;
        short                           getShort(const gstd::string &name) const;
        int                             getInt(const gstd::string &name) const;
        int64_t                         getInt64(const gstd::string &name) const;
        float                           getFloat(const gstd::string &name) const;
        std::pair<size_t, gstd::string> getByteArray(const gstd::string &name) const;
        gstd::string                   &getString(const gstd::string &name) const;
        ListTag                        *getList(const gstd::string &name) const;
        const CompoundTag              *getCompound(const gstd::string &name) const;
        std::pair<size_t, gstd::string> getIntArray(const gstd::string &name) const;

    private:
        TagMap mTagMap;
    };
}    // namespace MC3DSPluginFramework