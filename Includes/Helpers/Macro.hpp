#pragma once

#define WEAK __attribute__(weak)
#define WEAK_ALIAS(x) __attribute__((weak, alias(#x)))

#define MACRO_MAKE_PAIR(name, T1, field1, T2, field2)            \
    struct name {                                                \
        T1 field1;                                               \
        T2 field2;                                               \
                                                                 \
        name() = default;                                        \
                                                                 \
        template <class U1, class U2>                            \
        name(U1 &&f1, U2 &&f2) : field1(std::forward<U1>(f1)),   \
                                 field2(std::forward<U2>(f2)) {} \
                                                                 \
        name(const name &)            = default;                 \
        name(name &&)                 = default;                 \
        name &operator=(const name &) = default;                 \
        name &operator=(name &&)      = default;                 \
    };
