#include "../inc/libmx.h"

void mx_is_positive(int i) {
    if((i > 0) && (i != 0)) {
        char pos[] = "positive\n";
        mx_printstr(pos);
    }
    else if (i == 0) {
        char pos[] = "zero\n";
        mx_printstr(pos);
    }
    else {
        char pos[] = "negative\n";
        mx_printstr(pos);
    }
}
