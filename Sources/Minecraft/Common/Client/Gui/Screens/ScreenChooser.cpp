#include "Minecraft/Common/Client/Gui/Screens/ScreenChooser.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x23AC6C
    void ScreenChooser::_pushScreen(Util::BoxedPtr::Shared<BaseScreen> screen, bool unknown)
    {
        mMinecraftGame->pushScreen(screen, unknown);
    }
}