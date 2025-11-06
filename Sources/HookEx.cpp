#include "HookEx.hpp"

HookEx::HookEx(u32 targetAddress, Callback callback, u32 mode, const std::vector<u32> &override_Before, const std::vector<u32> &override_After) :
    m_target_Address(CheckAddress(targetAddress)), m_callback(callback), m_mode(mode), m_override_Instr_Before(override_Before), m_override_Instr_After(override_After) {

    m_initialized = (m_target_Address && m_callback);
}

HookEx::HookEx() {}

HookEx::~HookEx() {
    if (m_isEnabled)
        Disable();
}

bool HookEx::Init(u32 targetAddress, Callback callback, u32 mode, const std::vector<u32> &override_Before, const std::vector<u32> &override_After) {
    m_target_Address        = CheckAddress(targetAddress);
    m_callback              = callback;
    m_mode                  = mode;
    m_override_Instr_Before = override_Before;
    m_override_Instr_After  = override_After;
    return (m_initialized = (m_target_Address && m_callback));
}

bool HookEx::Init(u32 targetAddress, Callback callback, u32 mode, const std::initializer_list<u32> &override_Before, const std::initializer_list<u32> &override_After) {
    m_target_Address        = CheckAddress(targetAddress);
    m_callback              = callback;
    m_mode                  = mode;
    m_override_Instr_Before = override_Before;
    m_override_Instr_After  = override_After;
    return (m_initialized = (m_target_Address && m_callback));
}

bool HookEx::CheckSafe(void) {
    return m_initialized;
}

void HookEx::SetArgs(void *args) {
    m_args = args;
}

HookEx::Context HookEx::GetContext(void) {
    Context ctx;
    ctx.mode                  = m_mode;
    ctx.targetAddress         = m_target_Address;
    ctx.callback              = m_callback;
    ctx.original_Instr        = m_original_Instr;
    ctx.override_Instr_Before = &m_override_Instr_Before;
    ctx.override_Instr_After  = &m_override_Instr_After;
    ctx.args                  = m_args;
    return ctx;
}

bool HookEx::IsEnabled(void) {
    return m_isEnabled;
}

void HookEx::Enable(void) {
    if (!m_isEnabled && m_initialized) {
        m_original_Instr = *(u32 *)m_target_Address;    // AllocSlot内で使うから先に保存
        if (m_slot = HookExManager::AllocSlot(this)) {
            SetBranch(m_target_Address, (u32)m_slot);
            m_isEnabled = true;
            ClearCache();
        }
    }
}

void HookEx::Disable(void) {
    if (m_isEnabled) {
        *(u32 *)m_target_Address = m_original_Instr;
        m_slot->FreeSlot();
        m_slot      = nullptr;
        m_isEnabled = false;
        ClearCache();
    }
}

u32 HookEx::CheckAddress(u32 address) {
    return address >= 0x00100000 ? address : 0;
}

void HookEx::ClearCache(void) {
    svcInvalidateEntireInstructionCache();
    svcFlushProcessDataCache(CUR_PROCESS_HANDLE, m_target_Address, 4);
}

void HookEx::SetBranch(u32 from, u32 to) {
    u32 code  = (((to - (from + 8)) >> 2) & 0x00FFFFFF);
    u32 instr = 0;

    if (m_mode & Mode::MITM_MODE)
        instr = 0xEA000000;
    else if (m_mode & Mode::USE_LR_TO_RETURN)
        instr = 0xEB000000;

    if (instr)
        *(u32 *)from = instr | code;
}
