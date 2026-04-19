#include <types.h>

// ARMアセンブリ系のユーティリティクラス
// Thumb非対応
class Disassembly
{
public:
    // bxは非対応
    static constexpr bool isBranch(u32 instr)
    {
        u32 bit = (instr & 0x0F000000);
        return (bit == 0x0A000000 /* b */) || (bit == 0x0B000000 /* bl */);
    }

    static constexpr bool isBx(u32 instr)
    {
        u32 bit = (instr & 0x0FFFFFFF);
        return (bit == 0x012FFF1E /* bx */) || (bit == 0x012FFF3E /* blx */);
    }

    static constexpr u32 decodeARMBranch(u32 from)
    {
        s32 code = (*(u32 *)from & 0x00FFFFFF) << 2;
        if (code & 0x00800000)
            code |= 0xFF000000;

        return from + 8 + code;
    }

    static constexpr void setBranch(u32 from, u32 to)
    {
        s32 code     = (s32)(to - (from + 8));
        code         = (code >> 2) & 0x00FFFFFF;
        *(u32 *)from = 0xEA000000 | code;
    }

    static constexpr void setBranchLink(u32 from, u32 to)
    {
        s32 code     = (s32)(to - (from + 8));
        code         = (code >> 2) & 0x00FFFFFF;
        *(u32 *)from = 0xEB000000 | code;
    }

    static constexpr bool isLdrhPcRelative(u32 instr)
    {
        u32 bit = (instr & 0x0FFF00F0);
        return (bit == 0x01DF00B0 /* ldrh r, [pc]*/) || (bit == 0x019F00B0 /* ldrh r, [pc, r]*/);
    }

    static constexpr bool isStrhPcRelative(u32 instr)
    {
        u32 bit = (instr & 0x0FFF00F0);
        return (bit == 0x01CF00B0 /* strh r, [pc]*/) || (bit == 0x018F00B0 /* strh r, [pc, r]*/);
    }

    static constexpr bool isPcRelativeInstr(u32 instr)
    {
        constexpr bool a = isBranch(0x1A112233);

        if (isLdrhPcRelative(instr) || isStrhPcRelative(instr))
            return true;

        constexpr u16 list[] = {
            0x059F,    // ldr r, [pc]
            0x05DF,    // ldrb r, [pc]

            0x079F,    // ldr r, [pc, r] (switchで使用されている)
            0x07DF,    // ldrb r, [pc, r]

            0x058F,    // str r, [pc]
            0x05CF,    // strb r, [pc]

            0x078F,    // str r, [pc, r]
            0x07CF,    // strb r, [pc, r]

            0x0D9F,    // vldr s, [pc]
            0x0D8F,    // vstr s, [pc]

            0x028F,    // add r, pc, #　(文字列等の固定値参照とかで使われる)
            0x024F,    // sub r, pc, # (ほぼ使用されない)

        };

        for (auto i : list)
            if ((instr & 0x0FFF0000) == (i << 16))
                return true;

        return false;
    }
};