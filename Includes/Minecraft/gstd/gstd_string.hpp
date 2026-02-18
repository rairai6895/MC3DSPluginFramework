#pragma once

#include "gstd_alloc.hpp"
#include <cstring>
#include <string>

namespace MC3DSPluginFramework::gstd
{
    inline int memcmp(const void *mem1, const void *mem2, size_t size)
    {
        return reinterpret_cast<int (*)(const void *, const void *, size_t)>(0x101B44 | 1)(mem1, mem2, size);
    }

    inline size_t strlen(const char *str)
    {
        return reinterpret_cast<size_t (*)(const char *)>(0x2FE990)(str);
    }

    inline void *memchr(const void *s, int c, size_t n)
    {
        return reinterpret_cast<void *(*)(const void *, int, size_t)>(0x101580 | 1)(s, c, n);
    }

    inline char tolower(int c)
    {
        return reinterpret_cast<char (*)(int)>(0x2FFD90 | 1)(c);
    }

    inline char *strncpy(void *dest, const void *src, size_t size)
    {
        return reinterpret_cast<char *(*)(const void *, const void *, size_t)>(0x2FEBA8 | 1)(dest, src, size);
    }

    class string
    {
    private:
        class header
        {
        public:
            // FUN_0x2FF520
            void reference(void)
            {
                if (this != null)
                    mRefcount++;
            }

            char *getBuffer()
            {
                return (char *)((u32)this + 0xC);
            }

            static inline header *null = (header *)0xB3EB04;

            u32 mRefcount;
            size_t mCapacity;
            size_t mSize;
        };

        static inline header *null_header = (header *)0xB3EB04;

        header *allocate(u32 capacity, u32 size)
        {
            // thisは使われていない
            return reinterpret_cast<header *(*)(string *, u32, u32)>(0x2FEB28 | 1)(this, capacity, size);
        }

        // FUN_0x100A6C
        char *newBuffer(u32 needCapacity, u32 capacity, u32 size)
        {
            u32 newCapacity         = (needCapacity * 1.625);
            newCapacity             = std::max(newCapacity, needCapacity + 32);
            newCapacity             = std::max(newCapacity, capacity);
            header *newStringHeader = this->allocate(newCapacity, size);

            return newStringHeader->getBuffer();
        }

        header &get_header() const
        {
            return *(header *)((u32)mStr - 0xC);
        }

        // FUN_0x2FF220
        string &_init(const char *str)
        {
            u32 len    = strlen(str);
            char *dest = null_header->getBuffer();

            if (len)
                dest = this->newBuffer(0, len, len);

            this->mStr = dest;
            strncpy(dest, str, len);

            return *this;
        }

        string &_destroy()
        {
            if (this->mStr != null_header->getBuffer()) {
                header &header = this->get_header();

                if ((header.mRefcount == -1) || ((&header != null_header && (header.mRefcount-- == -1))))
                    free(&header);
            }

            mStr = null_header->getBuffer();

            return *this;
        }

    public:
        static const string null;

        string() { this->_init(""); }

        string(const char *str) { this->_init(str); }

        // FUN_0x2FF260
        string(const string &other)
        {
            char *other_buffer   = other.mStr;
            header &other_header = other.get_header();

            // 生存チェック
            if (other_header.mRefcount == -1) {
                u32 newSize       = other_header.mSize;
                header *newHeader = this->allocate(newSize, newSize);
                this->mStr        = newHeader->getBuffer();
                strncpy(newHeader->getBuffer(), other_buffer, newSize);
            }
            else {
                this->mStr = other_buffer;
                other_header.reference();
            }
        }

        string(string &&other)
        {
            this->mStr = other.mStr;
            other.mStr = null_header->getBuffer();
        }

        // FUN_0x2FEBBC
        ~string() { this->_destroy(); }

        const char *c_str(void) const { return mStr; }

        u32 refcount(void) const { return this->get_header().mRefcount; }

        size_t assigned(void) const { return this->get_header().mCapacity; }

        size_t size(void) const { return this->get_header().mSize; }

        bool empty(void) const { return !this->size(); }

        void clear(void) { this->_destroy(); }

        operator const char *(void) const { return mStr; }

        operator std::string(void) const { return mStr; }

        bool operator==(const string &other) const;
        bool operator==(const char *other) const;
        bool operator!=(const string &other) const;
        bool operator!=(const char *other) const;

        int compare(const string &other) const;
        bool operator<(const string &other) const;

        string operator+(const string &other) const;
        string &operator+=(const string &other);
        string &operator=(const string &other);
        string &operator=(const char *str);

        using iterator       = char *;
        using const_iterator = const char *;

        iterator begin() { return mStr; }

        const_iterator begin() const { return mStr; }

        iterator end() { return mStr + this->size(); }

        const_iterator end() const { return mStr + this->size(); }

        char &front(void) const { return mStr[0]; }

        char &back(void) const { return mStr[this->size()]; }

        char &operator[](size_t index) const { return mStr[index]; }

    private:
        char *mStr;
    };
}    // namespace MC3DSPluginFramework::gstd