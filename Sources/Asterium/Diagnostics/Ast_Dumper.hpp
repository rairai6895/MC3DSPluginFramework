#pragma once

#include "Ast_Logger.hpp"
#include "Ast_Time.hpp"
#include "Asterium/AstHook/Regs.hpp"

namespace Asterium::Dumper
{

    // グローバルスコープでLoggerは使えないので関数化
    inline Logger &getLogger()
    {
        static Logger instance("Debug/Dump.txt");
        return instance;
    }

    inline void clear()
    {
        getLogger().clear();
    }

    inline void dumpCPURegs(Regs &regs, const char *hook = "")
    {
        std::string line;

        line += timeStamp('[', ']');
        line += " ";
        line += hook;
        line += '\n';

        // r0 ~ r12
        for (int i = 0; i < 13; ++i) {
            line += 'r';
            line += std::to_string(i);
            line += ": ";
            line += CTRPF::Utils::ToHex(regs.r(i));
            line += '\n';
        }

        // lr
        line += "lr:";
        line += CTRPF::Utils::ToHex(regs.lr);
        line += "\n\n";
        getLogger().write(line);
    }

    inline void dumpFPURegs(Regs &regs, const char *hook = "")
    {
        std::string line;

        line += timeStamp('[', ']');
        line += " ";
        line += hook;
        line += '\n';

        // s0 ~ s31
        for (int i = 0; i < 32; ++i) {
            line += 's';
            line += std::to_string(i);
            line += ": ";
            line += std::to_string(regs.s(i));
            line += '\n';
        }

        line += "\n";
        getLogger().write(line);
    }

    inline void dumpRegs(Regs &regs, const char *hook = "")
    {
        std::string line;

        line += timeStamp('[', ']');
        line += " ";
        line += hook;
        line += '\n';

        // r0 ~ r12
        for (int i = 0; i < 13; ++i) {
            line += 'r';
            line += std::to_string(i);
            line += ": ";
            line += CTRPF::Utils::ToHex(regs.r(i));
            line += '\n';
        }

        // lr
        line += "lr: ";
        line += CTRPF::Utils::ToHex(regs.lr);
        line += '\n';

        // s0 ~ s31
        for (int i = 0; i < 32; ++i) {
            line += 's';
            line += std::to_string(i);
            line += ": ";
            line += std::to_string(regs.s(i));
            line += '\n';
        }

        line += "\n";
        getLogger().write(line);
    }

    inline void dumpStackPointer(u32 *sp, int size, const char *hook = "")
    {
        std::string line;

        line += timeStamp('[', ']');
        line += " ";
        line += hook;
        line += '\n';

        for (int i = 0; i <= size; ++i) {
            line += "sp";
            line += std::to_string(i);
            line += ": ";
            line += CTRPF::Utils::ToHex(sp[i]);
            line += '\n';
        }

        line += "\n";
        getLogger().write(line);
    }

}    // namespace Asterium::Dumper
