
#include "./utility.h"


uint8_t char_to_int(char ch) {
    if (ch - '0' < 10 && ch - '0' > -1) {
        return ch - '0';
    }
    else {
        return -1;
    }
}


bool_t is_int(char ch) {
    uint8_t inted = char_to_int(ch);
    return inted > -1 && inted < 10;
}


bool_t is_whitespace(char ch) {
    return (ch == ' ' || ch == '\n' || ch == '\0');
}