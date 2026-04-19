#pragma once

namespace MC3DSPluginFramework::RumtimeFunctions
{
    // FUN_0x1003BC
    void *__construct_array(void *m, void (*constructor)(void *), int size, int count)
    {
        if (constructor)
            for (int i = 0; i < count; ++i)
                constructor(reinterpret_cast<void *>(reinterpret_cast<int>(m) + i * size));

        return m;
    }
}    // namespace MC3DSPluginFramework::RumtimeFunctions