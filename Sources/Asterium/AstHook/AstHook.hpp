#pragma once

#include "Regs.hpp"
#include <3ds.h>
#include <csvc.h>
#include <vector>

namespace Asterium
{
    namespace HookMode
    {
        enum {
            // ROUTINEの追加モード
            // 完全に関数を乗っ取る
            // コールバック終了後、フック前のLRに復帰する
            MITM = 1 << 0,

            // bl funcのような関数呼び出しの前後にコールバックを挟む
            // beforeCallbackAddress または afterCallbackAddressのどちらかだけが0(nullptr)でも可
            // Before、Original、Afterの順でコールバックを呼んだあと、targetAddress+4の位置にLRを書き換えて戻る
            WRAP_SUB = 1 << 1,

            // コールバックでレジスタやスタックを触ることができる
            // モードを追加することができる
            // 戻り先は追加のモードやコールバック内でのLR書き換えによって決まる
            ROUTINE = 1 << 2,

            // ROUTINEの追加モード
            // LRを書き換えず、targetAddress+4の位置にPCを書き換えて戻る
            // フック前の元の命令は自動実行されない
            // MITMと併用不可能
            TRAMPOLINE = 1 << 3,

            // ROUTINEの追加モード
            // PC-relative命令には適用不可
            // EXECUTE_ORIGINAL_INSTR_AFTER と併用可能
            EXECUTE_ORIGINAL_INSTR_BEFORE = 1 << 4,

            // ROUTINEの追加モード
            // PC-relative命令には適用不可
            // EXECUTE_ORIGINAL_INSTR_BEFORE と併用可能
            EXECUTE_ORIGINAL_INSTR_AFTER = 1 << 5,
        };
    }    // namespace HookMode

    class AstHookManager;

    class AstHook
    {
    public:
        friend AstHookManager;

        using Routine = void (*)(Regs &regs, u32 *stackPointer, AstHook *hook);

        AstHook();
        ~AstHook();

        AstHook(const AstHook &)            = delete;
        AstHook &operator=(const AstHook &) = delete;

        bool initMitm(u32 targetAddress, u32 callbackAddress);
        bool initSubWrap(u32 targetAddress, u32 beforeCallbackAddress, u32 afterCallbackAddress);
        bool initRoutine(u32 targetAddress, Routine callbackAddress, u32 addmode = 0);

        bool isEnabled() const;
        void enable();
        void disable();
        void clearCache() const;

    private:
        static constexpr u32 checkAddress(u32 address)
        {
            return address >= 0x100000 ? address : 0;
        }

    private:
        u32 mTargetAddress;
        u32 mCallbackAddress;
        u32 mBeforeCallbackAddress;
        u32 mAfterCallbackAddress;
        u32 mReturnAddress;
        u32 mOriginalInstr;
        u32 mMode;
        AstHookManager *mSlot;
        bool mEnabled;
    };
}    // namespace Asterium
