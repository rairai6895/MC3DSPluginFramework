#pragma once

#include "Helpers/Macro.hpp"
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

namespace MC3DSPluginFramework
{

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\nbt\\CompoundTag.cpp"
    class CompoundTag : public NamedTag
    {
    public:
        MACRO_MAKE_PAIR(TagData, gstd::string, name, gstd::unique_ptr<Tag>, tag);
        using Tags = gstd::vector<TagData>;

        // FUN_0x182464
        CompoundTag() :
            NamedTag(""), mTagList(1)
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
            for (auto &data : tags) {
                mTagList.push_back({ mTagList.size(), data.name });
                mTags.push_back(std::move(data.tag));
            }

            *(u32 *)this = 0x99A3F4;
        }

        void *operator new(size_t s) { return gstd::malloc(s); }

        void put(TagData &&put)
        {
            mTags.push_back(std::move(put.tag));
            mTagList.push_back({ mTagList.size(), put.name });
        }

        gstd::reference_ptr<Tag> get(gstd::string tagName) const
        {
            return reinterpret_cast<gstd::reference_ptr<Tag> (*)(const CompoundTag *, gstd::string)>(0x6A0C74)(this, tagName);
        }

        bool contains(gstd::string tagName) const
        {
            return reinterpret_cast<bool (*)(const CompoundTag *, gstd::string)>(0x6A10E0)(this, tagName);
        }

        bool contains(gstd::string tagName, Tag::Type type) const
        {
            return reinterpret_cast<bool (*)(const CompoundTag *, gstd::string, Tag::Type)>(0x6A1114)(this, tagName, type);
        }

        bool remove(gstd::string tagName)
        {
            return reinterpret_cast<bool (*)(CompoundTag *, gstd::string)>(0x1818C8)(this, tagName);
        }

        gstd::reference_ptr<EndTag> getEnd(gstd::string tagName) const;
        gstd::reference_ptr<ByteTag> getByte(gstd::string tagName) const;
        gstd::reference_ptr<ShortTag> getShort(gstd::string tagName) const;
        gstd::reference_ptr<IntTag> getInt(gstd::string tagName) const;
        gstd::reference_ptr<Int64Tag> getInt64(gstd::string tagName) const;
        gstd::reference_ptr<FloatTag> getFloat(gstd::string tagName) const;
        gstd::reference_ptr<DoubleTag> getDouble(gstd::string tagName) const;
        gstd::reference_ptr<ByteArrayTag> getByteArray(gstd::string tagName) const;
        gstd::reference_ptr<StringTag> getString(gstd::string tagName) const;
        gstd::reference_ptr<ListTag> getList(gstd::string tagName) const;
        gstd::reference_ptr<CompoundTag> getCompound(gstd::string tagName) const;
        gstd::reference_ptr<IntArrayTag> getIntArray(gstd::string tagName) const;

    private:
        gstd::vector<std::pair<size_t, gstd::string>> mTagList;
        gstd::vector<gstd::unique_ptr<Tag>> mTags;
    };
}    // namespace MC3DSPluginFramework