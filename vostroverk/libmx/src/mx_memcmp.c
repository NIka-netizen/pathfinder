#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *s11 = (char*)s1;
    char *s22 = (char*)s2;
    size_t i = 0;
    if (n == 0)
        return 0;
    else {
        while (i < n) {
            if (s11[i] != s22[i])
                return s11[i] - s22[i];
            i++;
        }
        return 0;
    }
}
