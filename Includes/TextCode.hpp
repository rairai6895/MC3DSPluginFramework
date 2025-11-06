#ifndef TEXTCODE_HPP
#define TEXTCODE_HPP

#include <string>
#include <types.h>

namespace MC3DSPluginFramework {

class TextCode {
  public:
    constexpr TextCode(u16 code) :
        _code(code) {}

    constexpr u16 GetCode() const { return _code; }

    static const TextCode Black;
    static const TextCode Blue;
    static const TextCode Green;
    static const TextCode Turquoise;
    static const TextCode Red;
    static const TextCode Purple;
    static const TextCode Orange;
    static const TextCode Gray;
    static const TextCode DarkGray;
    static const TextCode VioletBlue;
    static const TextCode LimeGreen;
    static const TextCode Cyan;
    static const TextCode OrangeRed;
    static const TextCode Magenta;
    static const TextCode Yellow;
    static const TextCode White;

    static const TextCode Bold;
    static const TextCode Italic;

    static const TextCode Reset;

    static constexpr size_t SIZE = sizeof(u16);

  private:
    u16 _code;
};

inline gstd::string operator+(const TextCode &a, const TextCode &b) {
    char res_c[TextCode::SIZE * 2 + 1];
    res_c[0] = (char)(a.GetCode() >> 8);
    res_c[1] = (char)(a.GetCode() & 0xFF);
    res_c[2] = (char)(b.GetCode() >> 8);
    res_c[3] = (char)(b.GetCode() & 0xFF);
    res_c[4] = '\0';
    return gstd::string(res_c);
}

inline gstd::string operator+(const gstd::string str, const TextCode code) {
    size_t baseSize = str.size();
    char *res_c     = (char *)gstd::malloc(baseSize + TextCode::SIZE + 1);
    std::memcpy(res_c, str.c_str(), baseSize);
    res_c[baseSize]                  = (char)((code.GetCode() >> 8) & 0xFF);
    res_c[baseSize + 1]              = (char)(code.GetCode() & 0xFF);
    res_c[baseSize + TextCode::SIZE] = '\0';
    gstd::string res(res_c);
    gstd::free(res_c);
    return res;
}

inline gstd::string operator+(const TextCode &code, const gstd::string str) {
    size_t baseSize = str.size();
    char *res_c     = (char *)gstd::malloc(baseSize + TextCode::SIZE + 1);
    res_c[0]        = (char)((code.GetCode() >> 8) & 0xFF);
    res_c[1]        = (char)(code.GetCode() & 0xFF);
    std::memcpy(&res_c[2], str.c_str(), baseSize);
    res_c[2 + baseSize] = '\0';
    gstd::string res(res_c);
    gstd::free(res_c);
    return res;
}

constexpr TextCode TextCode::Black(0x1E30);
constexpr TextCode TextCode::Blue(0x1E31);
constexpr TextCode TextCode::Green(0x1E32);
constexpr TextCode TextCode::Turquoise(0x1E33);
constexpr TextCode TextCode::Red(0x1E34);
constexpr TextCode TextCode::Purple(0x1E35);
constexpr TextCode TextCode::Orange(0x1E36);
constexpr TextCode TextCode::Gray(0x1E37);
constexpr TextCode TextCode::DarkGray(0x1E38);
constexpr TextCode TextCode::VioletBlue(0x1E39);
constexpr TextCode TextCode::LimeGreen(0x1E61);
constexpr TextCode TextCode::Cyan(0x1E62);
constexpr TextCode TextCode::OrangeRed(0x1E63);
constexpr TextCode TextCode::Magenta(0x1E64);
constexpr TextCode TextCode::Yellow(0x1E65);
constexpr TextCode TextCode::White(0x1E66);

constexpr TextCode TextCode::Bold(0x1E6C);
constexpr TextCode TextCode::Italic(0x1E6F);

constexpr TextCode TextCode::Reset(0x1E72);

}    // namespace MC3DSPluginFramework

#endif