#include "GameSession.hpp"
#include "Level/Level.hpp"

namespace MC3DSPluginFramework
{
    Level *GameSession::getLevel()
    {
        return mLevel.get();
    }
}