#include "../inc/libmx.h"

char *mx_str_size_cpy(char *dst, const char *src, int start, int end) {
	int i = 0;
	int j = start;

	while  (j < end) {
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return dst;
}

char *mx_str_size_dup(const char *s1, size_t start, size_t end) {
	char *copy = NULL;

	copy = mx_strnew(end - start);
	if (copy  == NULL)
		return NULL;
	else
		mx_str_size_cpy(copy, s1, start, end);
	return copy;
}

char *mx_strjoin_free(char *s1, const char *s2) {
	char *join = NULL;
	int i;

	if (s1 == NULL && s2 == NULL) 
		return NULL;
	else if (s1 == NULL) 
		join = mx_strdup(s2);
	else if (s2 == NULL)
		join = mx_strdup(s1);
	else {
		join = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
		for (i = 0; i < mx_strlen(s1); i++)
			join[i] = s1[i];
		for (int j = 0; j < mx_strlen(s2); j++, i++)
			join[i] = s2[j];
		join[i] = '\0';
	}
	mx_strdel(&s1);
	return join;
}

char *mx_str_size_dup_free(char *s1, size_t start, size_t end) {
	char *copy = NULL;

	copy = mx_strnew(end - start);
	if (copy  == NULL)
		return NULL;
	else
		mx_str_size_cpy(copy, s1, start, end);
	mx_strdel(&s1);
	return copy;
}

char *ptr_delim_checking(char **ptr, char delim) {
	char *lineptr = NULL;
	int j;

	j = mx_get_char_index(*ptr, delim);
	if (j == -1) {
		lineptr = mx_strdup(*ptr);
		mx_strdel(ptr);
	}
	else {
		lineptr = mx_strndup(*ptr,  j);
		if (ptr[j + 1])
			*ptr = mx_str_size_dup_free(*ptr, j + 1, (mx_strlen(*ptr)));
	}
	return lineptr;
}

char *buf_to_lineptr(char *lineptr, char **buf, int index) {
	char *temp = NULL;

	temp = mx_strndup(*buf, index);
	lineptr = mx_strjoin_free(lineptr, temp);
	mx_strdel(&temp);
   
	return lineptr;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
	size_t i;
	int j;
	static char	*ptr;
	char *buf = NULL;

	if (read(fd, NULL, 0) < 0 || fd == -1)
		return -2;
	else if (*lineptr)
		mx_strdel(lineptr);	
	if (ptr != NULL) {
		*lineptr = ptr_delim_checking(&ptr, delim);
		if (ptr != NULL)
			return mx_strlen(*lineptr);
	}
	buf = mx_strnew(buf_size);
	while ((i = read(fd, buf, buf_size)) > 0) {
		j = mx_get_char_index(buf, delim);
		if (i < buf_size && j == -1) {
			*lineptr = buf_to_lineptr(*lineptr, &buf, i);
			return -1;
		}
		else if (j == -1) 
			*lineptr = mx_strjoin_free(*lineptr, buf);
		else if (j > -1) {
			*lineptr = buf_to_lineptr(*lineptr, &buf, j);
			if (buf[j + 1])
				ptr = mx_str_size_dup(buf, j + 1, i);
			break;
		}
	}
	mx_strdel(&buf);
	return ((i == 0 && j == -1) ? -1 : mx_strlen(*lineptr));
}
