#include "../inc/libmx.h"

int mx_max(int a, int b, int c) {
    if(a > b) {
        if(a > c)
            return a;
        else
            return c;
    }
    if(b > c) 
        return b;
    else 
        return c;
}

