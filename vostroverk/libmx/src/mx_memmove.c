#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	char *buf = (char *)malloc(sizeof(char)*len);
	mx_memcpy(buf, ((char *)src), len);
	mx_memcpy(((char *)dst), buf, len);
	free(buf);
	return dst;
}
