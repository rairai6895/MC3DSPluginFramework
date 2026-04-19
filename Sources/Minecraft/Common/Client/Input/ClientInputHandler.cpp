#include "ClientInputHandler.hpp"
#include "../Game/ClientInstance.hpp"
#include "Minecraft/src-deps/Input/InputHandler.hpp"

namespace MC3DSPluginFramework
{
    ClientInputHandler::ClientInputHandler(ClientInstance *client)
    {
        reinterpret_cast<ClientInputHandler *(*)(ClientInputHandler *, ClientInstance *)>(0x426E9C)(this, client);
    }

    // FUN_0x41ED38
    void ClientInputHandler::updateInputMode(int i)
    {
        switch (i)
        {
            default:
                mInputMode = "gamePlayNormal";
                break;
            case 1:
                mInputMode = "gamePlayBoating";
                break;
            case 2:
                mInputMode = "gamePlayFlying";
                break;
            case 3:
                mInputMode = "screenBed";
                return;
            case 4:
                mInputMode = "gamePlayMinecart";
                break;
            case 5:
                mInputMode = "gamePlayRiding";
                break;
        }

        if (mClientInstance->FUN_0012aae4())
            mInputHandler->updateInputMapping(mInputMode);
    }

    void ClientInputHandler::setJumping(bool set)
    {
        mMoveInputHandler->setJumping(set);
    }

    bool ClientInputHandler::isJumping()
    {
        return mMoveInputHandler->isJumping();
    }

    void ClientInputHandler::setSneaking(bool set)
    {
        mMoveInputHandler->setSneaking(set);
    }

    bool ClientInputHandler::isSneaking()
    {
        return mMoveInputHandler->isSneaking();
    }
}    // namespace MC3DSPluginFramework