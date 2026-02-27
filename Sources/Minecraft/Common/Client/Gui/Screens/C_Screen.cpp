#include "Minecraft/Common/Client/Gui/Screens/C_Screen.hpp"

namespace MC3DSPluginFramework
{
    C_Screen::~C_Screen()
    {
        reinterpret_cast<void (*)(C_Screen *)>(0x6213B8)(this);
    }
}