#pragma once

#include <types.h>

namespace MC3DSPluginFramework
{
    // 仮名
    class TouchPad
    {
    public:
        // FUN_0x19C01C
        static void setTouch(bool set)
        {
            mTouch = set;
        }

        // FUN_0x19C04C
        static void setX(short set)
        {
            mX = set;
        }

        static void setY(short set)
        {
            mY = set;
        }

        static bool isTouch()
        {
            return mTouch;
        }

        static short getX()
        {
            return mX;
        }

        static short getY()
        {
            return mY;
        }

    private:
        static inline bool &mTouch = *(bool *)0xA317B6;
        static inline u16  &mX     = *(u16 *)0xA317B8;
        static inline u16  &mY     = *(u16 *)0xA317BA;
    };
}    // namespace MC3DSPluginFramework