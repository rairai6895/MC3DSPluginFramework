#ifndef HOOKEX_HPP
#define HOOKEX_HPP

#include "HookExManager.hpp"
#include <3ds.h>
#include <csvc.h>
#include <types.h>
#include <vector>

struct Regs;
class HookExManager;
class HookEx {
    using Callback = void (*)(Regs &, u32 *, HookEx *);

  public:
    enum Mode {
        USE_LR_TO_RETURN              = 1 << 0,    // LRを保存する
        MITM_MODE                     = 1 << 1,    // LRを保存しない
        EXECUTE_ORIGINAL_INSTR_BEFORE = 1 << 2,    // 元の命令をコールバック前に実行
        EXECUTE_ORIGINAL_INSTR_AFTER  = 1 << 3,    // 元の命令をコールバック後に実行
        EXECUTE_OVERRIDE_INSTR_BEFORE = 1 << 4,    // 追加の命令をコールバック前に実行
        EXECUTE_OVERRIDE_INSTR_AFTER  = 1 << 5,    // 追加の命令をコールバック後に実行
    };

    struct Context {
        u32 mode;
        u32 targetAddress;
        Callback callback;
        u32 original_Instr;
        const std::vector<u32> *override_Instr_Before;
        const std::vector<u32> *override_Instr_After;
        void *args;
    };

    HookEx(u32 targetAddress, Callback callback, u32 mode, const std::vector<u32> &override_Before = {}, const std::vector<u32> &override_After = {});
    HookEx();
    ~HookEx();

    bool Init(u32 targetAddress, Callback callback, u32 mode, const std::vector<u32> &override_Before = {}, const std::vector<u32> &override_After = {});
    bool Init(u32 targetAddress, Callback callback, u32 mode, const std::initializer_list<u32> &override_Before = {}, const std::initializer_list<u32> &override_After = {});
    bool CheckSafe(void);

    void SetArgs(void *args);
    Context GetContext(void);

    bool IsEnabled(void);
    void Enable(void);
    void Disable(void);

  private:
    static u32 CheckAddress(u32 address);
    void ClearCache(void);
    void SetBranch(u32 from, u32 to);

    HookExManager *m_slot = nullptr;
    bool m_isEnabled      = false;
    bool m_initialized    = false;
    u32 m_mode            = Mode::USE_LR_TO_RETURN;
    u32 m_target_Address  = 0;
    Callback m_callback   = nullptr;
    u32 m_original_Instr  = 0;
    std::vector<u32> m_override_Instr_Before{};
    std::vector<u32> m_override_Instr_After{};
    void *m_args = nullptr;
};

#endif