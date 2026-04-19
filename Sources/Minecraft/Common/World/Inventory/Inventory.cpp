#include "Inventory.hpp"

namespace MC3DSPluginFramework
{
    void Inventory::setupDefault()
    {
        reinterpret_cast<void (*)(Inventory *)>(0x679C80)(this);
    }

}    // namespace MC3DSPluginFramework