#pragma once

#include "Minecraft/gstd/gstd.hpp"

namespace MC3DSPluginFramework
{
    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src-deps\\Renderer\\VertexFormat.cpp"
    class VertexFormat
    {
    public:
        static inline VertexFormat &EMPTY = *(VertexFormat *)0xA358E1;

        // FUN_0x124DF0
        VertexFormat(VertexFormat &other)
        {
            this->todo = other.todo;
        }

    private:
        gstd::type_unknown<8> todo;
    };
}    // namespace MC3DSPluginFramework