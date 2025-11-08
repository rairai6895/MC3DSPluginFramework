#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "Function.hpp"
#include "GameEnums.hpp"

namespace MC3DSPluginFramework {
namespace GameController {

inline const gKey &ConvertKey(u32 hidkey) {
    return Function<gKey &>(0x118B88)(0x0FFFFAE4, &hidkey);
}

inline void Press(gKey key) {
    Function<void>(0x1112FC)(0, key, true);
}

inline void Release(gKey key) {
    Function<void>(0x1112FC)(0, key, false);
}

}    // namespace GameController
}    // namespace MC3DSPluginFramework

#endif