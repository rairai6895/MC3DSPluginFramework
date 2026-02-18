#include "Minecraft/Common/NBT/CompoundTag.hpp"

namespace MC3DSPluginFramework
{

    gstd::reference_ptr<EndTag> CompoundTag::getEnd(gstd::string tagName) const
    {
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::End)
                return *(gstd::reference_ptr<EndTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<ByteTag> CompoundTag::getByte(gstd::string tagName) const
    {
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::Byte)
                return *(gstd::reference_ptr<ByteTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<ShortTag> CompoundTag::getShort(gstd::string tagName) const
    {
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::Short)
                return *(gstd::reference_ptr<ShortTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<IntTag> CompoundTag::getInt(gstd::string tagName) const
    {
        // FUN_0x6A1038
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::Int)
                return *(gstd::reference_ptr<IntTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<Int64Tag> CompoundTag::getInt64(gstd::string tagName) const
    {
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::Int64)
                return *(gstd::reference_ptr<Int64Tag> *)&tag;

        return {};
    }

    gstd::reference_ptr<FloatTag> CompoundTag::getFloat(gstd::string tagName) const
    {
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::Float)
                return *(gstd::reference_ptr<FloatTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<DoubleTag> CompoundTag::getDouble(gstd::string tagName) const
    {
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::Double)
                return *(gstd::reference_ptr<DoubleTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<ByteArrayTag> CompoundTag::getByteArray(gstd::string tagName) const
    {
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::ByteArray)
                return *(gstd::reference_ptr<ByteArrayTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<StringTag> CompoundTag::getString(gstd::string tagName) const
    {
        // return reinterpret_cast<const gstd::string &(*)(const CompoundTag *, const gstd::string &)>(0x6A1228)(this, tagName);
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::String)
                return *(gstd::reference_ptr<StringTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<ListTag> CompoundTag::getList(gstd::string tagName) const
    {
        // return reinterpret_cast<ListTag *(*)(const CompoundTag *, const gstd::string &)>(0x6A0C30)(this, tagName);
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::List)
                return *(gstd::reference_ptr<ListTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<CompoundTag> CompoundTag::getCompound(gstd::string tagName) const
    {
        // return reinterpret_cast<CompoundTag *(*)(const CompoundTag *, const gstd::string &)>(0x6A0A9C)(this, tagName);
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::Compound)
                return *(gstd::reference_ptr<CompoundTag> *)&tag;

        return {};
    }

    gstd::reference_ptr<IntArrayTag> CompoundTag::getIntArray(gstd::string tagName) const
    {
        // reinterpret_cast<ListTag *(*)(std::pair<size_t, gstd::string> *, const CompoundTag *, const gstd::string &)>(0x6A0B48)(out, this, tagName);
        if (gstd::reference_ptr<Tag> tag = this->get(tagName))
            if (tag->getType() == Type::IntArray)
                return *(gstd::reference_ptr<IntArrayTag> *)&tag;

        return {};
    }

}    // namespace MC3DSPluginFramework