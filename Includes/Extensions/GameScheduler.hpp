#pragma once

#include "Helpers/Macro.hpp"

namespace MC3DSPluginFramework
{
    class GameScheduler
    {
    public:
        // ゲーム内main関数で一度だけ実行される関数
        // ユーザー定義可能
        static void WEAK onMainOnce();
    };
}    // namespace MC3DSPluginFramework