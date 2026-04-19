#pragma once

namespace MC3DSPluginFramework
{
    template <typename T>
    class Vec2
    {
    public:
        T x, y;

    public:
        void init(T x, T y)
        {
            this->x = x;
            this->y = y;
        }

        Vec2() = default;

        Vec2(T x, T y)
        {
            init(x, y);
        }
    };
}    // namespace MC3DSPluginFramework