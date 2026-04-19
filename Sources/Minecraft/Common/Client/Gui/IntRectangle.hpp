#pragma once

namespace MC3DSPluginFramework
{
    class IntRectangle
    {
    public:
        int mX, mY, mWidth, mHeight;

    public:
        void init(int x, int y, int w, int h)
        {
            mX      = x;
            mY      = y;
            mWidth  = w;
            mHeight = h;
        }

        IntRectangle()
        {
            init(0, 0, 1, 1);
        }

        IntRectangle(int x, int y, int w, int h)
        {
            init(x, y, w, h);
        }
    };
}    // namespace MC3DSPluginFramework