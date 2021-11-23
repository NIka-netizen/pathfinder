#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    char *k = s1;
    
    while (*s1 != mx_strlen(s1)) {
        s1++;
    }

    while (*s2 != mx_strlen(s2)) {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return k;
}

