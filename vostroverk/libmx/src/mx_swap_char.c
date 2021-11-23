#include "../inc/libmx.h"

void mx_swap_char(char *s1, char *s2) {
    char o = *s1;
    char i = *s2;
    *s1 = i;
    *s2 = o;
}


