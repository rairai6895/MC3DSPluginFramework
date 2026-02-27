#include "Minecraft/Common/Client/Input/PlayerController.hpp"
#include "Minecraft/Common/Client/Game/ClientInstance.hpp"
#include "Minecraft/src-deps/Input/InputHandler.hpp"

namespace MC3DSPluginFramework
{
    // FUN_0x41ED38
    void PlayerController::changeState(int i)
    {
        switch (i) {
            default:
                mState = "gamePlayNormal";
                break;
            case 1:
                mState = "gamePlayBoating";
                break;
            case 2:
                mState = "gamePlayFlying";
                break;
            case 3:
                mState = "screenBed";
                return;
            case 4:
                mState = "gamePlayMinecart";
                break;
            case 5:
                mState = "gamePlayRiding";
        }

        if (mClientInstance->FUN_0012aae4())
            mInputHandler->updateInputMapping(mState);
    }
}    // namespace MC3DSPluginFramework