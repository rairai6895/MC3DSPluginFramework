#pragma once

#include <ctime>
#include <string>

namespace Asterium
{
    inline std::string timeStamp(char beforeCloseBracket, char afterCloseBracket)
    {
        time_t now    = std::time(NULL);
        tm *localTime = std::localtime(&now);
        char timeString[100];

        std::string format;
        format += beforeCloseBracket;
        format += "%Y-%m-%d %H:%M:%S";
        format += afterCloseBracket;

        std::strftime(timeString, sizeof(timeString), format.c_str(), localTime);

        return std::string(timeString);
    }
}    // namespace Asterium