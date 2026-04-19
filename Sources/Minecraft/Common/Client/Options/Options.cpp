#include "Options.hpp"

namespace MC3DSPluginFramework
{
    Options::Options(gstd::string unknown1 /* "extdata:/" */, u8 unknown2, gstd::unique_ptr<MinecraftOptionValue> &&unknown3, u32 unknown4)
    {
        reinterpret_cast<Options *(*)(Options *, gstd::string, u8, gstd::unique_ptr<MinecraftOptionValue> &&, u32)>(0x63547C)(this, unknown1, unknown2, std::move(unknown3), unknown4);
    }

    void Options::setFloat(const Option &option, float value)
    {
        reinterpret_cast<void (*)(Options *, const Option &, float)>(0x6329B8)(this, option, value);
    }

    float Options::getFloat(const Option &option)
    {
        return reinterpret_cast<float (*)(Options *, const Option &)>(0x630718)(this, option);
    }

    void Options::setByte(const Option &option, u8 value)
    {
        reinterpret_cast<void (*)(Options *, const Option &, u8)>(0x632644)(this, option, value);
    }

    u8 Options::getByte(const Option &option)
    {
        return reinterpret_cast<char (*)(Options *, const Option &)>(0x63019C)(this, option);
    }

    void Options::setInt(const Option &option, int value)
    {
        reinterpret_cast<void (*)(Options *, const Option &, int)>(0x632AEC)(this, option, value);
    }

    int Options::getInt(const Option &option)
    {
        return reinterpret_cast<int (*)(Options *, const Option &)>(0x62FCDC)(this, option);
    }
}    // namespace MC3DSPluginFramework