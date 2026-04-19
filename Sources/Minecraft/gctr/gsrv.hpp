#pragma once

#include <3ds/svc.h>
#include <string.h>

namespace MC3DSPluginFramework
{
    namespace gsrv
    {
        inline Handle &getSessionHandle()
        {
            return *(Handle *)0xA36694;
        }

        // FUN_0x123F6C
        inline Result getServiceHandleDirect(Handle *out, const char *name, size_t len, u32 unknown)
        {
            Result res = 0xD8A067F8;

            if ((0 < *(int *)(0xA3668C + 4)) && (res = 0xD9006405, len < 9))
            {
                u32 tls = (u32)getThreadLocalStorage();

                *(u32 *)(tls + 0x80) = 0x00050100;
                strncpy((char *)(tls + 0x84), name, len);
                *(u32 *)(tls + 0x8c) = len;
                *(u32 *)(tls + 0x90) = unknown;

                if (-1 < svcSendSyncRequest(getSessionHandle()))
                {
                    res  = *(Result *)(tls + 0x84);
                    *out = *(Handle *)(tls + 0x8c);
                }
            }

            return res;
        }
    };    // namespace gsrv
}    // namespace MC3DSPluginFramework