#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <types.h>

template <typename Result>
class Function {
  public:
    constexpr Function(u32 Address, bool thumb = false) :
        address(Address | thumb) {
    }

    template <typename... Args>
    inline Result operator()(Args... args) {
        return ((Result (*)(Args...))(address))(args...);
    }

    inline Function &operator=(u32 Address) {
        address = Address;
        return *this;
    }

    u32 address;

    template <typename... Args>
    class Const {
      public:
        constexpr Const(u32 Address, bool thumb = false) :
            address(Address | thumb) {
        }

        inline Result operator()(Args... args) {
            return ((Result (*)(Args...))(address))(args...);
        }

        inline Const &operator=(u32 Address) {
            address = Address;
            return *this;
        }

        u32 address;
    };
};

#endif