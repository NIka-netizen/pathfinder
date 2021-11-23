#include "../inc/libmx.h"

int mx_strlen(const char *s) {
	int x = 0;
	int i = 0;
	while (s[i] != '\0'){
		 x++;
		 i++;	
	}
	return x;
}
