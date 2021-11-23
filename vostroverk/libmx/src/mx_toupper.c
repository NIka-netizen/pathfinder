#include "../inc/libmx.h"

int mx_toupper(int c) {
    if (c >= 97 && c <= 122) {
        char rez = c - 'a' + 'A';
        return rez;
    }
    else {
        return c;
    }
}

