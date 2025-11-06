#ifndef GSTD_STRING_HPP
#define GSTD_STRING_HPP

#include "gstd.hpp"
#include <cstring>
#include <string>

namespace MC3DSPluginFramework {
/**
 *  Game standard Functions.
 *  Do not use while the game thread is stopped.
 */
namespace gstd {

class string {
  private:
    // new Data, m_str = &Data::str, ref_count = 0
    static inline Function<string &>::Const<string *, const char *> constructor = 0x2FF220 | 1;

    // ref_count--, if (ref_count == -1) delete
    static inline Function<void>::Const<string *> destructor = 0x2FEBBC | 1;

    static inline Function<string &>::Const<string *, const string &> constructor_copy = 0x2FF260 | 1;

    char *m_str = nullptr;

  public:
    /*
    struct Data {
        u32 ref_count;
        u32 unk;
        u32 size;
        char str[];
    };
    constructor = 0x2FEB28 | 1
    */

    string() {}

    string(const char *str) {
        constructor(this, str);
    }

    string(const string &other) {
        constructor_copy(this, other);
    }

    ~string() {
        if (m_str)
            destructor(this);
    }

    string(string &&other) noexcept {
        m_str       = other.m_str;
        other.m_str = nullptr;
    }

    inline const char *c_str(void) const {
        return m_str;
    }

    inline size_t size(void) const {
        if (m_str)
            return *(size_t *)((u32)m_str - 4);
        return 0;
    }

    inline bool empty(void) const {
        return !size();
    }

    inline void clear(void) {
        if (m_str)
            destructor(this);

        m_str = nullptr;
    }

    void swap(string &other) {
        std::swap(m_str, other.m_str);
    }

    inline operator const char *(void) const {
        return m_str;
    }

    inline operator std::string(void) const {
        return std::string(m_str);
    }

    inline string &operator+=(const char *other) {
        size_t this_size  = size();
        size_t other_size = std::strlen(other);
        char *newStr      = (char *)gstd::malloc(this_size + other_size + 1);
        std::memcpy(newStr, m_str, this_size);
        std::memcpy(newStr + this_size, other, other_size + 1);

        if (m_str)
            destructor(this);

        constructor(this, newStr);
        gstd::free((void *)newStr);

        return *this;
    }

    inline string &operator+=(const char other) {
        size_t this_size = size();
        char *newStr     = (char *)gstd::malloc(this_size + 2);
        if (this_size)
            std::memcpy(newStr, m_str, this_size);

        newStr[this_size]     = other;
        newStr[this_size + 1] = '\0';

        if (m_str)
            destructor(this);

        constructor(this, newStr);
        gstd::free((void *)newStr);

        return *this;
    }

    inline string &operator+=(const string &other) {
        *this += other.c_str();
        return *this;
    }

    inline string &operator=(const string &other) {    // FUN_0x6300F0(Arm) -> FUN_0x2FF260(Thumb)
        if (this != &other) {
            if (m_str)
                destructor(this);

            constructor_copy(this, other);
        }
        return *this;
    }

    inline string &operator=(const char *str) {
        if (m_str)
            destructor(this);

        return constructor(this, str);
    }

    inline string &operator=(string &&other) noexcept {
        if (this != &other) {
            if (m_str)
                destructor(this);

            m_str       = other.m_str;
            other.m_str = nullptr;
        }
        return *this;
    }

    inline string operator+(const string &other) {
        size_t this_size  = size();
        size_t other_size = std::strlen(other.c_str());
        char *newStr      = (char *)gstd::malloc(this_size + other_size + 1);
        std::memcpy(newStr, m_str, this_size);
        std::memcpy(newStr + this_size, other, other_size + 1);

        string res(newStr);
        gstd::free(newStr);

        return res;
    }

    using iterator       = char *;
    using const_iterator = const char *;

    inline iterator begin() {
        return m_str;
    }

    inline const_iterator begin() const {
        return m_str;
    }

    inline iterator end() {
        return m_str ? m_str + size() : m_str;
    }
    inline const_iterator end() const {
        return m_str ? m_str + size() : m_str;
    }
};
}    // namespace gstd
}    // namespace MC3DSPluginFramework

#endif