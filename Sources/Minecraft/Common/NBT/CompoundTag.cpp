#include "Minecraft/Common/NBT/CompoundTag.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x6A0A4C
    bool CompoundTag::getBool(const gstd::string &name) const
    {
        return contains(name, Type::Byte) ? reinterpret_cast<ByteTag *>(get(name))->mValue : false;
    }

    // FUN_0x6A1080
    char CompoundTag::getByte(const gstd::string &name) const
    {
        return contains(name, Type::Byte) ? reinterpret_cast<ByteTag *>(get(name))->mValue : 0;
    }

    // FUN_0x6A11E0
    short CompoundTag::getShort(const gstd::string &name) const
    {
        return contains(name, Type::Short) ? reinterpret_cast<ShortTag *>(get(name))->mValue : 0;
    }

    // FUN_0x6A1038
    int CompoundTag::getInt(const gstd::string &name) const
    {
        return contains(name, Type::Int) ? reinterpret_cast<IntTag *>(get(name))->mValue : 0;
    }

    // FUN_0x6A1194
    int64_t CompoundTag::getInt64(const gstd::string &name) const
    {
        return contains(name, Type::Int64) ? reinterpret_cast<Int64Tag *>(get(name))->mValue : 0;
    }

    // FUN_0x6A1148
    float CompoundTag::getFloat(const gstd::string &name) const
    {
        return contains(name, Type::Float) ? reinterpret_cast<FloatTag *>(get(name))->mValue : 0;
    }

    // FUN_0x6A0BBC
    std::pair<size_t, gstd::string> CompoundTag::getByteArray(const gstd::string &name) const
    {
        return contains(name, Type::ByteArray) ? reinterpret_cast<ByteArrayTag *>(get(name))->mArray : std::pair<size_t, gstd::string>();
    }

    // FUN_0x6A1228
    gstd::string &CompoundTag::getString(const gstd::string &name) const
    {
        return contains(name, Type::String) ? reinterpret_cast<StringTag *>(get(name))->mString : Util::EMPTY_STRING;
    }

    // FUN_0x6A0C30
    ListTag *CompoundTag::getList(const gstd::string &name) const
    {
        return contains(name, Type::List) ? reinterpret_cast<ListTag *>(get(name)) : nullptr;
    }

    // 恐らく読み取り専用
    // FUN_0x6A0A9C
    const CompoundTag *CompoundTag::getCompound(const gstd::string &name) const
    {
        if (!contains(name, Type::Compound))
            return nullptr;

        Tag *tag = get(name);

        if (!tag)
            LOG("Not found anyway?", tag, 0);

        return reinterpret_cast<CompoundTag *>(tag);
    }

    // FUN_0x6A0B48
    std::pair<size_t, gstd::string> CompoundTag::getIntArray(const gstd::string &name) const
    {
        return contains(name, Type::IntArray) ? reinterpret_cast<IntArrayTag *>(get(name))->mArray : std::pair<size_t, gstd::string>();
    }

}    // namespace MC3DSPluginFramework