#pragma once

#include "Minecraft/Common/Util/Util.hpp"

namespace MC3DSPluginFramework
{

    class LanguageTable
    {
    public:
        // FUN_0x12DD18
        const char *operator[](u32 hash)
        {
            if (hash == 0)
                return nullptr;

            int i = 0;
            if (size_t range = mSize)
                while (i < mSize)
                {
                    int    step   = range >> 1;
                    Entry &target = mEntries[i];

                    if (target.hash > hash)
                        i -= step;
                    else if (target.hash < hash)
                        i += step;
                    else
                    {
                        // found
                        i = 0;
                        while (char &c = target.str[i])
                        {
                            if (c == '^')
                                c = '\n';

                            i++;
                        }
                        return target.str;
                    }

                    if (step == 0 || i < 0)
                    {
                        return nullptr;
                    }

                    range -= step;
                }
            return nullptr;
        }

        const char *get(u32 hash)
        {
            return operator[](hash);
        }

    private:
        struct Entry
        {
            u32   hash;
            char *str;
        };

        Entry *mEntries;    // +0x0
        size_t mSize;    // +0x4
        char  *mBegin;    // +0x8
        u32    mUnk2;    // +0xC mem size?
        u32    mUnk3;    // +0x10
    };

    class Language
    {
    public:
        static inline Language *&Current = *(Language **)0xA32560;

        gstd::string getLocale()
        {
            return mLocale;
        }

        bool get(const gstd::string &key, gstd::string *out, const gstd::vector<const char *> *params)
        {
            return reinterpret_cast<bool (*)(Language *, const gstd::string &, gstd::string *, const gstd::vector<const char *> *)>(0x12A8A0)(this, key, out, params);
        }

    private:
        u32            mUnk1;    // 何かのフラグ
        gstd::string   mLocale;    // ja_JP、en_USとか
        LanguageTable *mTable;
    };

    class Localization
    {
    public:
        // 石だけ特殊
        // tile.stone.stone.name -> Stone / 石
        // tile.dirt.name -> Dirt / 土
        // params = フォーマット引数
        // FUN_0x11D954
        static gstd::string get(const gstd::string &key, const gstd::vector<const char *> *params = nullptr)
        {
            gstd::string out;

            if (Language *lang = Language::Current)
                lang->get(key, &out, params);

            return out;
        }

    private:
    };
}    // namespace MC3DSPluginFramework