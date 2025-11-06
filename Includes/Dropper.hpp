#ifndef DROPPER_HPP
#define DROPPER_HPP

#include "EntityClass.hpp"
#include "GameStructs.hpp"

namespace MC3DSPluginFramework {
namespace Dropper {

// Do not use while the game thread is stopped.
inline void Send(Entity *entity, const SlotData &item, bool swing, bool diffusion) {
    Function<void>(swing ? 0x198174 : 0x5F2F38)(entity, &item, diffusion);
}

}    // namespace Dropper
}    // namespace MC3DSPluginFramework

#endif