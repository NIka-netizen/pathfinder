#include "../inc/libmx.h"

bool mx_isspace(char c) {
    if((c == 13) || ((c >= 9) && (c <= 11)) || (c == 32)) {
        bool rez = true;
        return rez;
    }
    else {
        bool rez = false;
        return rez;
    }
}

