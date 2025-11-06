#ifndef GAMENOTIFY_HPP
#define GAMENOTIFY_HPP

#include "gstd.hpp"

namespace MC3DSPluginFramework {
namespace GameNotify {

struct Item {
    u32 currentTime = 0;
    u32 maxTime     = 0xC8;
    gstd::string str1;
    const void *_nullptr = MC_NULLPTR;
    gstd::string str2;
    u32 unk = 0;
};

static const u32 *INSTANCE_PTR = (u32 *)0xA31AD8;

inline bool IsLoaded(void) {
    return *INSTANCE_PTR;
}

// Default 3
inline void ChangeMax(u8 max) {
    *(u32 *)0x11A778 = (0xE3500000 | max);
    *(u32 *)0x11A7CC = (0xE3500000 | max);
}

inline const gstd::vector<Item> *GetMessages(void) {
    if (u32 instance = *INSTANCE_PTR)
        return ((gstd::vector<Item> *)(instance + 0x9C));
    return nullptr;
}

// Do not use while the game thread is stopped.
// ゲームスレッドが停止してる間は使用しないでください。
inline bool Send(const gstd::string &str) {
    if (u32 instance = *INSTANCE_PTR) {
        Function<void>(0x11A680)(instance, str);
        return true;
    }
    return false;
}

};    // namespace GameNotify
}    // namespace MC3DSPluginFramework

#endif