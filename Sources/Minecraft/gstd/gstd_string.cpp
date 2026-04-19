#include "Minecraft/gstd/gstd_string.hpp"

namespace MC3DSPluginFramework::gstd
{

    const string string::null("");

    int string::compare(const string &other) const
    {
        if (int r = memcmp(mStr, other.mStr, std::min(this->size(), other.size())))
            return r;

        if (this->size() < other.size())
            return -1;

        if (this->size() > other.size())
            return 1;

        return 0;
    }

    bool string::operator==(const string &other) const
    {
        // return (strcmp(mStr, other.mStr) == 0);
        return this->compare(other) == 0 && this->length() == other.length();
    }

    bool string::operator==(const char *other) const
    {
        return (strcmp(mStr, other) == 0);
    }

    bool string::operator<(const string &other) const
    {
        return this->compare(other) < 0;
    }

    string string::operator+(const char *str) const
    {
        return reinterpret_cast<string (*)(const string *, const char *)>(0x10F154)(this, str);
    }

    // FUN_0x121538
    string string::operator+(const string &other) const
    {
        string res(*this);
        return reinterpret_cast<string &(*)(string *, const string &)>(0x11839C)(&res, other);
    }

    string &string::operator+=(const string &other)
    {
        // assignedが足りない場合はデストラクタを呼び、再確保する
        // どこも参照してなければ再確保せず、既存のメモリにcharを追加する
        return reinterpret_cast<string &(*)(string *, const string &)>(0x11839C)(this, other);
    }

    string &string::operator=(const string &other)
    {
        return reinterpret_cast<string &(*)(string *, const string &)>(0x2FFFD8 | 1)(this, other);
    }

    string &string::operator=(const char *str)
    {
        this->_destroy();
        return this->_init(str);
    }

}    // namespace MC3DSPluginFramework::gstd