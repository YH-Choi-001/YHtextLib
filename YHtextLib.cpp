#ifndef YHTEXTLIB_CPP
#define YHTEXTLIB_CPP __DATE__ ", " __TIME__

#include "YHtextLib.h"
// #include <string>

namespace YH {
    namespace Lib {
        namespace Func {
            namespace texts {
                const char vers [] = YHTEXTLIB_CPP;
                const char capital_letters [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                const char small_letters [] = "abcdefghijklmnopqrstuvwxyz";
                const char number_chars [] = "0123456789";
                const char symbol_chars [] = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
                namespace buffer {
                    char buffer1024 [1024];
                    wchar_t w_buffer1024 [1024];
                }
                template <class T>
                void *qual_cast_away (T *ptr) {
                    return (void *)ptr;
                }
                types::largest_float power (const types::largest_float base, const types::largest_int exponential) {
                    types::largest_float result = 1;
                    if (exponential > 0) {
                        for (types::largest_int i = 0; i < exponential; i++) {
                            result *= base;
                        }
                    } else {
                        for (types::largest_int i = 0; i > exponential; i--) {
                            result /= base;
                        }
                    }
                    return result;
                }
                // template functions that are not supposed to have external linkage
                template <class T>
                T                  atod     (const char *src);
                template <class T>
                T                  strtod   (const char *src, char **rejected_str, const uint8_t base = 10);
                template <class T>
                T                  atoud    (const char *src);
                template <class T>
                T                  strtoud  (const char *src, char **rejected_str, const uint8_t base = 10);
                template <class T>
                T                  atoxf (const char *src);
                template <class T>
                T                  strtoxf (const char *src, char **rejected_str, const uint8_t base = 10);
            }
        }
    }
}

YH::Lib::types::largest_uint YH::Lib::Func::texts::strlen (const char * const str) {
    types::largest_uint i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}
int8_t YH::Lib::Func::texts::strcpy (char *dest, const char *src) {
    // for (types::largest_uint i = 0; (dest[i] = src[i]) != '\0'; i++); costs 2 more assembly commands
    while ((*dest = *src) != '\0') {++dest, ++src;}
    return 0;
}
YH::Lib::types::largest_uint YH::Lib::Func::texts::strncpy (char *dest, const char *src, types::largest_uint maxlen) {
    for (types::largest_uint i = 0; i < maxlen; i++) {
        if ((dest[i] = src[i]) == '\0') return i;
    }
    return maxlen;
}
int8_t YH::Lib::Func::texts::strcmp (const char *lhs, const char *rhs) {
    while (1) {
        if (*lhs < *rhs) return -1;
        else if (*lhs > *rhs) return 1;
        else if (*lhs == '\0') return 0;
        ++lhs, ++rhs;
    }
    return 0; // failure
}
int8_t YH::Lib::Func::texts::strncmp (const char *lhs, const char *rhs, types::largest_uint maxlen) {
    for (types::largest_uint i = 0; i < maxlen; i++) {
        if (lhs[i] < rhs[i]) return -1;
        else if (lhs[i] > rhs[i]) return 1;
        else if (lhs[i] == '\0') return 0;
    }
    return 0;
}
YH::Lib::types::largest_uint YH::Lib::Func::texts::strclr (char *str, types::largest_uint strsize) {
    for (types::largest_uint i = 0; i < strsize; i++) {
        if ((str[i] = '\0') != '\0') return i;
    }
    return 0;
}
// numbers and characters conversion
char YH::Lib::Func::texts::val_to_char (const uint8_t val, const uint8_t base) {
    if (val > 9 && val < base) return YH::Lib::Func::texts::capital_letters[val - 10];
    if (val < base) return YH::Lib::Func::texts::number_chars[val];
    return '\0';
}
int8_t YH::Lib::Func::texts::char_to_val (const char val, const uint8_t base) {
    int8_t to_return = -1;
    switch (val) {
        case '0':
            to_return = 0;
            break;
        case '1':
            to_return = 1;
            break;
        case '2':
            to_return = 2;
            break;
        case '3':
            to_return = 3;
            break;
        case '4':
            to_return = 4;
            break;
        case '5':
            to_return = 5;
            break;
        case '6':
            to_return = 6;
            break;
        case '7':
            to_return = 7;
            break;
        case '8':
            to_return = 8;
            break;
        case '9':
            to_return = 9;
            break;
        case 'A':
        case 'a':
            to_return = 10;
            break;
        case 'B':
        case 'b':
            to_return = 11;
            break;
        case 'C':
        case 'c':
            to_return = 12;
            break;
        case 'D':
        case 'd':
            to_return = 13;
            break;
        case 'E':
        case 'e':
            to_return = 14;
            break;
        case 'F':
        case 'f':
            to_return = 15;
            break;
        case 'G':
        case 'g':
            to_return = 16;
            break;
        case 'H':
        case 'h':
            to_return = 17;
            break;
        case 'I':
        case 'i':
            to_return = 18;
            break;
        case 'J':
        case 'j':
            to_return = 19;
            break;
        case 'K':
        case 'k':
            to_return = 20;
            break;
        case 'L':
        case 'l':
            to_return = 21;
            break;
        case 'M':
        case 'm':
            to_return = 22;
            break;
        case 'N':
        case 'n':
            to_return = 23;
            break;
        case 'O':
        case 'o':
            to_return = 24;
            break;
        case 'P':
        case 'p':
            to_return = 25;
            break;
        case 'Q':
        case 'q':
            to_return = 26;
            break;
        case 'R':
        case 'r':
            to_return = 27;
            break;
        case 'S':
        case 's':
            to_return = 28;
            break;
        case 'T':
        case 't':
            to_return = 29;
            break;
        case 'U':
        case 'u':
            to_return = 30;
            break;
        case 'V':
        case 'v':
            to_return = 31;
            break;
        case 'W':
        case 'w':
            to_return = 32;
            break;
        case 'X':
        case 'x':
            to_return = 33;
            break;
        case 'Y':
        case 'y':
            to_return = 34;
            break;
        case 'Z':
        case 'z':
            to_return = 35;
            break;
        default:
            to_return = -1;
            break;
    }
    return (to_return >= base) ? -to_return - 1 : to_return;
}
// capital and small letters conversion
char YH::Lib::Func::texts::capital_to_small (const char input) {
    if (is_charset_ascii) return (input > 0x40 && input < 0x5B) ? input + 0x20 : input;
    for (uint8_t i = 0U; i < 26U; i++) {
        if (input == YH::Lib::Func::texts::capital_letters[i]) return YH::Lib::Func::texts::small_letters[i];
    }
    return input;
}
char YH::Lib::Func::texts::small_to_capital (const char input) {
    if (is_charset_ascii) return (input > 0x60 && input < 0x7B) ? input - 0x20 : input;
    for (uint8_t i = 0U; i < 26U; i++) {
        if (input == YH::Lib::Func::texts::small_letters[i]) return YH::Lib::Func::texts::capital_letters[i];
    }
    return input;
}
// if the character is of the specific type
bool YH::Lib::Func::texts::is_num (const char input, const uint8_t base) {
    if (is_charset_ascii) return (input > 0x2f && input < 0x3a) || (input > 0x40 && input < (base + 0x37)) || (input > 0x60 && input < (base + 0x57));
    for (uint8_t i = 0; i < base; i++) {
        if (input == YH::Lib::Func::texts::number_chars[i]) return true;
    }
    for (uint8_t i = 0; i + 10U < base; i++) {
        if (input == YH::Lib::Func::texts::capital_letters[i] || input == YH::Lib::Func::texts::small_letters[i]) return true;
    }
    return false;
}
bool YH::Lib::Func::texts::is_capital (char input) {
    if (is_charset_ascii) return input > 0x40 && input < 0x5B;
    for (uint8_t i = 0U; i < 26U; i++) {
        if (input == YH::Lib::Func::texts::capital_letters[i]) return true;
    }
    return false;
}
bool YH::Lib::Func::texts::is_small (char input) {
    if (is_charset_ascii) return input > 0x60 && input < 0x7B;
    for (uint8_t i = 0U; i < 26U; i++) {
        if (input == YH::Lib::Func::texts::small_letters[i]) return true;
    }
    return false;
}
bool YH::Lib::Func::texts::is_letter (char input) {
    if (is_charset_ascii) return input == 0x20 || (input > 0x40 && input < 0x5B) || (input > 0x60 && input < 0x7B);
    for (uint8_t i = 0U; i < 26U; i++) {
        if (input == YH::Lib::Func::texts::capital_letters[i]) return true;
    }
    for (uint8_t i = 0U; i < 26U; i++) {
        if (input == YH::Lib::Func::texts::small_letters[i]) return true;
    }
    return input == ' ';
}
bool YH::Lib::Func::texts::is_symbol (char input) {
    for (uint8_t i = 0U; i < 26U; i++) {
        if (input == YH::Lib::Func::texts::symbol_chars[i]) return true;
    }
    return false;
}
// if the string contains some type of characters
bool YH::Lib::Func::texts::cont_num (const char *str) {
    for (; (*str) != '\0'; str++) {
        if (YH::Lib::Func::texts::is_num(*str)) return true;
    }
    return false;
}
bool YH::Lib::Func::texts::cont_capital (const char *str) {
    for (; (*str) != '\0'; str++) {
        if (YH::Lib::Func::texts::is_capital(*str)) return true;
    }
    return false;
}
bool YH::Lib::Func::texts::cont_small (const char *str) {
    for (; (*str) != '\0'; str++) {
        if (YH::Lib::Func::texts::is_small(*str)) return true;
    }
    return false;
}
bool YH::Lib::Func::texts::cont_letter (const char *str) {
    for (; (*str) != '\0'; str++) {
        if (YH::Lib::Func::texts::is_letter(*str)) return true;
    }
    return false;
}
bool YH::Lib::Func::texts::cont_symbol (const char *str) {
    for (; (*str) != '\0'; str++) {
        if (YH::Lib::Func::texts::is_symbol(*str)) return true;
    }
    return false;
}
//  do all characters belong to the specific type
bool YH::Lib::Func::texts::is_all_num (const char *str, const uint8_t base) {
    for (; (*str) != '\0'; str++) {
        if (!YH::Lib::Func::texts::is_num(*str, base)) return false;
    }
    return true;
}
bool YH::Lib::Func::texts::is_float (const char *str) {
    bool dec_pt_occur = false; // set flag if the '.' is found in string
    for (types::largest_uint i = 0U; str[i] != '\0'; i++) {
        if (!YH::Lib::Func::texts::is_num(str[i])) {
            if (str[i] == '-') {
                if (i != 0) return false;
            } else if (str[i] == '.') {
                if (dec_pt_occur) return false;
                else dec_pt_occur = true;
            } else return false; // detected chars like 'a', 'g', 'j', '@', '%'
        }
    }
    return true;
}
bool YH::Lib::Func::texts::is_all_capital (const char *str) {
    while (1) {
        if ((*str) == '\0') return true;
        else if (!YH::Lib::Func::texts::is_capital(*str)) return false;
        str++;
    }
    return false;
}
bool YH::Lib::Func::texts::is_all_small (const char *str) {
    while (1) {
        if ((*str) == '\0') return true;
        else if (!YH::Lib::Func::texts::is_small(*str)) return false;
        str++;
    }
    return false;
}
bool YH::Lib::Func::texts::is_all_letter (const char *str) {
    while (1) {
        if ((*str) == '\0') return true;
        else if (!YH::Lib::Func::texts::is_letter(*str)) return false;
        str++;
    }
    return false;
}
bool YH::Lib::Func::texts::is_all_symbol (const char *str) {
    while (1) {
        if ((*str) == '\0') return true;
        else if (!YH::Lib::Func::texts::is_symbol(*str)) return false;
        str++;
    }
    return false;
}
// converts alphabetical characters into numbers
// atod family
template <class T>
T YH::Lib::Func::texts::atod (const char *src) {
    T toReturn = 0;
    bool isNegative = false;
    for (types::largest_uint i = 0U; src[i] != '\0'; i++) {
        if (!is_num(src[i], 10)) {
            if (src[i] == '-' && (!i)) {
                isNegative = true;
                continue;
            } else break;
        }
        toReturn *= 10;
        toReturn += char_to_val(src[i], 10);
    }
    return isNegative ? -toReturn : toReturn;
}
         short     YH::Lib::Func::texts::atos  (const char *src) { return atod<short>(src); }
         int       YH::Lib::Func::texts::atoi  (const char *src) { return atod<int>(src); }
         long      YH::Lib::Func::texts::atol  (const char *src) { return atod<long>(src); }
         long long YH::Lib::Func::texts::atoll (const char *src) { return atod<long long>(src); }
// strtod family
template <class T>
T YH::Lib::Func::texts::strtod (const char *src, char **rejected_str, const uint8_t base) {
    T toReturn;
    toReturn = 0;
    bool isNegative = false;
    const bool reject_str_avail = (rejected_str != NULL);
    if (reject_str_avail) *rejected_str = static_cast<char *>(qual_cast_away(src));
    for (types::largest_uint i = 0U; src[i] != '\0'; i++, reject_str_avail ? (*rejected_str)++ : 0) {
        if (!is_num(src[i], base)) {
            if (src[i] == '-' && (!i)) {
                isNegative = true;
                continue;
            } else break;
        }
        toReturn *= base;
        toReturn += char_to_val(src[i], base);
    }
    return isNegative ? 0 - toReturn : toReturn;
}
         short     YH::Lib::Func::texts::strtos  (const char *src, char **rejected_str, const uint8_t base) {
             return strtod<short>(src, rejected_str, base); }
         int       YH::Lib::Func::texts::strtoi  (const char *src, char **rejected_str, const uint8_t base) {
             return strtod<int>(src, rejected_str, base); }
         long      YH::Lib::Func::texts::strtol  (const char *src, char **rejected_str, const uint8_t base) {
             return strtod<long>(src, rejected_str, base); }
         long long YH::Lib::Func::texts::strtoll (const char *src, char **rejected_str, const uint8_t base) {
             return strtod<long long>(src, rejected_str, base); }
// converts alphabetical characters into unsigned numbers
// atoud family
template <class T>
T YH::Lib::Func::texts::atoud (const char *src) {
    T toReturn = 0;
    bool isNegative = false;
    for (types::largest_uint i = 0U; src[i] != '\0'; i++) {
        if (!is_num(src[i], 10)) {
            if (src[i] == '-' && (!i)) {
                isNegative = true;
                continue;
            } else break;
        }
        toReturn *= 10U;
        toReturn += char_to_val(src[i], 10);
    }
    return isNegative ? 0 - toReturn : toReturn;
}
unsigned short     YH::Lib::Func::texts::atous  (const char *src) { return atoud<unsigned short>(src); }
unsigned int       YH::Lib::Func::texts::atoui  (const char *src) { return atoud<unsigned int>(src); }
unsigned long      YH::Lib::Func::texts::atoul  (const char *src) { return atoud<unsigned long>(src); }
unsigned long long YH::Lib::Func::texts::atoull (const char *src) { return atoud<unsigned long long>(src); }
// strtoud family
template <class T>
T YH::Lib::Func::texts::strtoud (const char *src, char **rejected_str, const uint8_t base) {
    T toReturn;
    toReturn = 0;
    bool isNegative = false;
    const bool reject_str_avail = rejected_str != NULL;
    if (reject_str_avail) *rejected_str = static_cast<char *>(qual_cast_away(src));
    for (types::largest_uint i = 0U; src[i] != '\0'; i++, reject_str_avail ? (*rejected_str)++ : 0) {
        if (!is_num(src[i], base)) {
            if (src[i] == '-' && (!i)) {
                isNegative = true;
                continue;
            } else break;
        }
        toReturn *= base;
        toReturn += char_to_val(src[i], base);
    }
    return isNegative ? 0 - toReturn : toReturn;
}
unsigned short     YH::Lib::Func::texts::strtous  (const char *src, char **rejected_str, const uint8_t base) {
             return strtoud<unsigned short>(src, rejected_str, base); }
unsigned int       YH::Lib::Func::texts::strtoui  (const char *src, char **rejected_str, const uint8_t base) {
             return strtoud<unsigned int>(src, rejected_str, base); }
unsigned long      YH::Lib::Func::texts::strtoul  (const char *src, char **rejected_str, const uint8_t base) {
             return strtoud<unsigned long>(src, rejected_str, base); }
unsigned long long YH::Lib::Func::texts::strtoull (const char *src, char **rejected_str, const uint8_t base) {
             return strtoud<unsigned long long>(src, rejected_str, base); }
// converts alphabetical characters into floating-point numbers
// atoxf family
template <class T>
T YH::Lib::Func::texts::atoxf (const char *src) {
    T toReturn;
    toReturn = 0;
    bool isNegative = false;
    // unsigned int fp_idx = 0U; // floating point index
    bool isDecimal = false;
    types::largest_float dec_base = 1.0;
    for (types::largest_uint i = 0U; src[i] != '\0'; i++) {
        if (!is_num(src[i], 10)) {
            if (src[i] == '-' && (!i)) {
                isNegative = true;
                continue;
            } else if (src[i] == '.') {
                isDecimal = true;
                continue;
            } else break;
        }
        if (isDecimal) {
            dec_base /= 10.0;
            toReturn += char_to_val(src[i], 10) * dec_base;
        } else {
            toReturn *= 10.0;
            toReturn += char_to_val(src[i], 10);
        }
    }
    return (isNegative) ? toReturn * -1 : toReturn;
}
float              YH::Lib::Func::texts::atof  (const char *src) { return atoxf<float>(src); }
double             YH::Lib::Func::texts::atolf (const char *src) { return atoxf<double>(src); }
long double        YH::Lib::Func::texts::atold (const char *src) { return atoxf<long double>(src); }
// strtoxf family
template <class T>
T YH::Lib::Func::texts::strtoxf (const char *src, char **rejected_str, const uint8_t base) {
    T toReturn;
    toReturn = 0;
    bool isNegative = false;
    // unsigned int fp_idx = 0U; // floating point index
    bool isDecimal = false;
    types::largest_float dec_base = 1.0;
    const bool reject_str_avail = rejected_str != NULL;
    if (reject_str_avail) *rejected_str = static_cast<char *>(qual_cast_away(src));
    for (types::largest_uint i = 0U; src[i] != '\0'; i++, reject_str_avail ? (*rejected_str)++ : 0) {
        if (!is_num(src[i], base)) {
            if (src[i] == '-') {
                if (!i) {
                    isNegative = true;
                    continue;
                }
                else break;
            } else if (src[i] == '.' && !isDecimal) {
                isDecimal = true;
                continue;
            } else break;
        }
        if (isDecimal) {
            dec_base /= base;
            toReturn += char_to_val(src[i], base) * dec_base;
        } else {
            toReturn *= base;
            toReturn += char_to_val(src[i], base);
        }
    }
    return (isNegative) ? -toReturn : toReturn;
}
float              YH::Lib::Func::texts::strtof  (const char *src, char **rejected_str, const uint8_t base) {
             return strtoxf<float>(src, rejected_str, base); }
double             YH::Lib::Func::texts::strtolf  (const char *src, char **rejected_str, const uint8_t base) {
             return strtoxf<double>(src, rejected_str, base); }
long double        YH::Lib::Func::texts::strtold  (const char *src, char **rejected_str, const uint8_t base) {
             return strtoxf<long double>(src, rejected_str, base); }
//
template <class T>
T YH::Lib::Func::texts::strtoType (const char *src, char **rejected_str, const uint8_t base) {
    T toReturn;
    toReturn = 0;
    bool isNegative = false;
    // unsigned int fp_idx = 0U; // floating point index
    bool isDecimal = false;
    const bool reject_str_avail = rejected_str != NULL;
    if (reject_str_avail) *rejected_str = static_cast<char *>(qual_cast_away(src));
    types::largest_float dec_base = 1.0;
    for (types::largest_uint i = 0U; src[i] != '\0'; i++, reject_str_avail ? (*rejected_str)++ : 0) {
        if (!is_num(src[i], base)) {
            if (src[i] == '-') {
                if (!i) {
                    isNegative = true;
                    continue;
                }
                else break;
            } else if (src[i] == '.' && !isDecimal) {
                isDecimal = true;
                continue;
            } else break;
        }
        if (isDecimal) {
            dec_base = dec_base / base;
            toReturn = toReturn + char_to_val(src[i], base) * dec_base;
        } else {
            toReturn = toReturn * base;
            toReturn = toReturn + char_to_val(src[i], base);
        }
    }
    return (isNegative) ? -toReturn : toReturn;
}

const char *YH::Lib::Func::texts::fptos (types::largest_float val, types::largest_uint max_length) {
    if (max_length > 1024) max_length = 1024;
    // std::string toReturn = "";
    char toReturn [max_length];
    for (types::largest_uint i = 0; i < max_length; i++) {
        toReturn[i] = '\0';
    }
    bool isNegative = false;
    if ((isNegative = (val < 0))) val = (0 - val);
    types::largest_int real_base = static_cast<types::largest_int>(val);
    do {
        // toReturn.insert(0, text.num_to_char(real_base % 10)); // this sentence is not avail bc insert requires a str as arg
        for (types::largest_uint j = max_length - 1; j > 0; j--) {
            toReturn[j] = toReturn[j-1];
        }
        toReturn[0] = val_to_char(real_base % 10, 10);
        // switch (real_base % 10) {
        //     case 0:
        //         toReturn[0] = '0';
        //         break;
        //     case 1:
        //         toReturn.insert(0, "1");
        //         break;
        //     case 2:
        //         toReturn.insert(0, "2");
        //         break;
        //     case 3:
        //         toReturn.insert(0, "3");
        //         break;
        //     case 4:
        //         toReturn.insert(0, "4");
        //         break;
        //     case 5:
        //         toReturn.insert(0, "5");
        //         break;
        //     case 6:
        //         toReturn.insert(0, "6");
        //         break;
        //     case 7:
        //         toReturn.insert(0, "7");
        //         break;
        //     case 8:
        //         toReturn.insert(0, "8");
        //         break;
        //     case 9:
        //         toReturn.insert(0, "9");
        //         break;
        // }
        real_base /= 10;
    } while (real_base);
    //
    if (val - real_base) {
        // val has decimal points
        toReturn[strlen(toReturn)] = '.';
        long double tobepcs = val - static_cast<long double>(real_base);
        for (unsigned long long k = strlen(toReturn); tobepcs - static_cast<long double>(static_cast<long long>(tobepcs)) && k < max_length - 1; k++) {
            tobepcs *= 10;
            toReturn[k] = val_to_char(static_cast<long long>(tobepcs) % 10);
            // toReturn.push_back(val_to_char(static_cast<long long>(tobepcs) % 10));
            // switch (static_cast<long long>(tobepcs) % 10) {
            //     case 0:
            //         toReturn.push_back('0');
            //         break;
            //     case 1:
            //         toReturn.push_back('1');
            //         break;
            //     case 2:
            //         toReturn.push_back('2');
            //         break;
            //     case 3:
            //         toReturn.push_back('3');
            //         break;
            //     case 4:
            //         toReturn.push_back('4');
            //         break;
            //     case 5:
            //         toReturn.push_back('5');
            //         break;
            //     case 6:
            //         toReturn.push_back('6');
            //         break;
            //     case 7:
            //         toReturn.push_back('7');
            //         break;
            //     case 8:
            //         toReturn.push_back('8');
            //         break;
            //     case 9:
            //         toReturn.push_back('9');
            //         break;
            // }
        }
        for (types::largest_uint p = strlen(toReturn) - 1; toReturn[p] == '0'; toReturn[p--] = '\0') {} // remove extra 0s at the back of decimal part
    }
    // if (isNegative) toReturn.insert(0, "-");
    if (isNegative) {
        for (types::largest_uint j = max_length - 1; j > 0; j--) {
            toReturn[j] = toReturn[j-1];
        }
        toReturn[0] = '-';
    }
    YH::Lib::Func::texts::strncpy(YH::Lib::Func::texts::buffer::buffer1024, toReturn, sizeof(YH::Lib::Func::texts::buffer::buffer1024) / sizeof(char));
    return YH::Lib::Func::texts::buffer::buffer1024;
}

// functions below are originally developed in YHmathsLib, but moved to this library due to its purposes

YH::Lib::types::largest_float YH::Lib::Func::texts::base_n_to_base_10 (const char *str, const uint16_t base_from, char* *remaining_unrecognized_str) {
    types::largest_int int_val = 0;
    types::largest_uint i = 0;
    int8_t pcsing_val = 0;
    for (; str[i] != '.' && str[i] != '\0'; i++) {
        pcsing_val = char_to_val(str[i]);
        if (pcsing_val < 0 || static_cast<uint16_t>(pcsing_val) >= base_from) {
            if (remaining_unrecognized_str != NULL) *remaining_unrecognized_str = const_cast<char *>(str + i);
            return int_val;
        }
        int_val *= base_from;
        int_val += char_to_val(str[i]);
    }
    if (str[i++] == '.') {
        types::largest_float float_val = int_val;
        types::largest_float base_powering = 1;
        for (; str[i] != '\0'; i++) {
            pcsing_val = char_to_val(str[i]);
            if (pcsing_val < 0 || static_cast<uint16_t>(pcsing_val) >= base_from) {
                if (remaining_unrecognized_str != NULL) *remaining_unrecognized_str = const_cast<char *>(str + i);
                return float_val;
            }
            base_powering /= base_from;
            float_val += pcsing_val * base_powering;
        }
        return float_val;
    } else {
        return int_val;
    }
}

const char *YH::Lib::Func::texts::base_10_to_base_n (const types::largest_float val, const uint16_t base_to, types::largest_uint str_max_len, const bool round_off_last_digit) {
    if (base_to < 2 || str_max_len < 2) return 0; // base == 0 || base == 1 || str_max_len == 0 || str_max_len == 1
    if (!str_max_len) {
        buffer::buffer1024[0] = '\0';
        return buffer::buffer1024;
    }
    if (str_max_len > 1024) str_max_len = 1024;
    if (val == static_cast<types::largest_float>(NAN)) {
        strncpy(buffer::buffer1024, "nan", 4);
        return buffer::buffer1024;
    } else if (val == static_cast<types::largest_float>(INFINITY)) {
        strncpy(buffer::buffer1024, "inf", 4);
        return buffer::buffer1024;
    }
    char holding_str [str_max_len]; // acts as the string buffer to be copied then returned
    //
    // -1 represents val < 1, -10 indicates the location of decimal-point
    types::largest_int holding_str_cal_val [str_max_len]; // the buffer that holds the digits corresponding to the string buffer above
    bool is_val_neg = val < 0;
    bool int_part_equals_0 = false; // to indicate if val >= 1
    // set the whole buffer to \\0
    for (types::largest_uint i = 0; i < str_max_len; i++) {
        holding_str[i] = '\0';
        holding_str_cal_val[i] = -255;
    }
    // ... process the data
    // convert the integer part first
    types::largest_uint i = 0;
    types::largest_int pcs_int_val = static_cast<types::largest_int>(val);
    types::largest_uint int_val_require_len = 0;
    while (pcs_int_val) {
        pcs_int_val /= base_to;
        int_val_require_len++;
    }
    if (int_val_require_len == 0) {
        int_val_require_len++;
        int_part_equals_0 = true;
    }
    const types::largest_uint int_holding_str_sum_len_minus_1 = int_val_require_len + is_val_neg;
    // char int_holding_str [int_holding_str_sum_len]; // int part
    // holding_str [int_holding_str_sum_len_minus_1] = '\0';
    // holding_str_cal_val [int_holding_str_sum_len_minus_1] = -255;
    if (is_val_neg) {
        holding_str_cal_val[i] = -1;
        // holding_str[i] = '-';
        i++;
        holding_str_cal_val[i] = -255;
        // holding_str[i] = '\0';
    }
    if (int_part_equals_0) {
        holding_str_cal_val[i] = 0;
        // holding_str[i] = '0';
        i++;
        holding_str_cal_val[i] = -255;
        // holding_str[i] = '\0';
    }
    pcs_int_val = is_val_neg ? -static_cast<types::largest_int>(val) : static_cast<types::largest_int>(val);
    for (types::largest_int j = int_holding_str_sum_len_minus_1 - 1; pcs_int_val; pcs_int_val /= base_to, j--) {
        holding_str_cal_val[j] = pcs_int_val % base_to;
        // holding_str[j] = valToCapLetter(holding_str_cal_val[j]);
    }
    // strncpy(holding_str, int_holding_str, int_holding_str_sum_len);
    // convert the part after decimal point
    //
    types::largest_uint k = int_holding_str_sum_len_minus_1;
    holding_str_cal_val[k] = -2;
    // holding_str[k] = '.'; // add the decimal point into the string
    k++;
    types::largest_float pcs_float_val = is_val_neg ? (static_cast<types::largest_int>(val) - val) : (val - static_cast<types::largest_int>(val));
    const types::largest_uint k_upper_limit = str_max_len - 1;
    while (k < k_upper_limit) {
        pcs_float_val *= base_to;
        // holding_str_cal_val[k] = rnddn(pcs_float_val) % base_to;
        holding_str_cal_val[k] = static_cast<types::largest_int>(pcs_float_val) % base_to;
        // holding_str[k] = valToCapLetter(holding_str_cal_val[k]);
        k++;
        // pcs_float_val -= rnddn(pcs_float_val);
        pcs_float_val -= static_cast<types::largest_int>(pcs_float_val);
    }
    // holding_str[k] = '\0';
    if (round_off_last_digit) {
        pcs_float_val *= base_to; // extract the digit after the max_str_len
        // if ((rnddn(pcs_float_val) % base_to) >= (base_to / 2U)) {
        if ((static_cast<types::largest_int>(pcs_float_val) % base_to) >= (base_to / 2U)) {
            // correct to max_str_len sig. fig.
            // last char += 1
            if (holding_str_cal_val[--k] > -1 || holding_str_cal_val[k] == -2) { // when the value == -2, [k] is pointing to the '.' sign in the string
                if (holding_str_cal_val[k] == -2) --k;
                holding_str_cal_val[k] += 1;
                // holding_str[k] = valToCapLetter(holding_str_cal_val[k]);
                while (holding_str_cal_val[k] == base_to) {
                    holding_str_cal_val[k] = 0;
                    // holding_str[k] = valToCapLetter(holding_str_cal_val[k]);
                    if (!k) {
                        // k == 0
                        // right shift 1 char
                        for (types::largest_uint p = str_max_len - 1; p > 0; p--) {
                            holding_str_cal_val[p] = holding_str_cal_val[p - 1];
                        }
                        k = 1;
                    }
                    if (holding_str_cal_val[--k] > -1 || holding_str_cal_val[k] == -2) {
                        if (holding_str_cal_val[k] == -2) --k;
                        holding_str_cal_val[k] += 1;
                        // holding_str[k] = valToCapLetter(holding_str_cal_val[k]);
                    } else if (holding_str_cal_val[k] == -1) {
                        // [k] is pointing to the '-' sign in the string
                        break;
                    }
                }
            } else if (holding_str_cal_val[k] == -1) {
                // [k] is pointing to the '-' sign in the string
            }
        }
    }
    if (holding_str_cal_val[str_max_len - 2] == '.') holding_str[str_max_len - 2] = '\0';
    holding_str_cal_val[str_max_len - 1] = -255;
    for (types::largest_uint i = 0; i < str_max_len; i++) {
        holding_str[i] = val_to_char(holding_str_cal_val[i], base_to);
    }
    strncpy(buffer::buffer1024, holding_str, str_max_len);
    buffer::buffer1024 [str_max_len - 1] = '\0';
    return buffer::buffer1024;
}

const char *YH::Lib::Func::texts::change_base_of_str (const char *inputed_str, const uint16_t base_from, const uint16_t base_to, const types::largest_uint str_max_len) {
    return base_10_to_base_n(base_n_to_base_10(inputed_str, base_from, 0), base_to, str_max_len);
}

/*
YHtextLib::Text () : capital("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
                     small("abcdefghijklmnopqrstuvwxyz"),
                     num("0123456789"),
                     version(YHTEXTLIB_CPP),
                     amount_of_eng_letters(0) {
    
    YHtextLib::amount_of_eng_letters = sizeof(YHtextLib::capital) / sizeof(YHtextLib::capital[0]) - 1;
}
char YHtextLib::small_to_capital (char input) {
    for (int i = 0; i < YHtextLib::amount_of_eng_letters; i++) {
        if (input == YHtextLib::small[i] || input == YHtextLib::capital[i]) return YHtextLib::capital[i];
    }
    return input;
}
char YHtextLib::capital_to_small (char input) {
    for (int i = 0; i < YHtextLib::amount_of_eng_letters; i++) {
        if (input == YHtextLib::small[i] || input == YHtextLib::capital[i]) return YHtextLib::small[i];
    }
    return input;
}
char YHtextLib::char_to_num (char input) {
    for (int i = 0; i < 10; i++) {
        if (input == YHtextLib::num[i]) return i;
    }
    return -1;
}
char YHtextLib::num_to_char (short input) {
    if (input >= 0 && input < 10) return YHtextLib::num[input];
    return '\0';
}
bool YHtextLib::is_num (char input) {
    for (int i = 0; i < 10; i++) {
        if (input == YHtextLib::num[i]) return true;
    }
    return false;
}
bool YHtextLib::is_capital (char input) {
    for (int i = 0; i < amount_of_eng_letters; i++) {
        if (input == YHtextLib::capital[i]) return true;
    }
    return false;
}
bool YHtextLib::is_small (char input) {
    for (int i = 0; i < amount_of_eng_letters; i++) {
        if (input == YHtextLib::small[i]) return true;
    }
    return false;
}
const char *YHtextLib::vers () const {
    return YHtextLib::version;
}
*/

#endif // #ifndef YHTEXTLIB_CPP