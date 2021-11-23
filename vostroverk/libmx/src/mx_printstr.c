#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    if ((*s < 32) && (*s >= 127)
            && (*s == (char)0)) {}
    else {
            write(1, s, mx_strlen(s));
         }
}

