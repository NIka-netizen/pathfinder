#include "../inc/pathfinder.h"

char **m_strsplit(const char *s, char c)
{
    if (s == NULL) return NULL;
    while (*s == c) s++;
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c 
            && (s[i + 1] == c 
            || s[i + 1] == '\0'))
        {
            count++;
        }
    }
    char **s_arr = malloc((count + 1) * sizeof(char **));
    s_arr[count] = NULL;
    int cur_w_len = 0;
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            cur_w_len = mx_get_char_index(&s[i], c);
            if (cur_w_len == -1) cur_w_len = mx_strlen(&s[i]);
            s_arr[j] = mx_strndup(&s[i], cur_w_len);
            j++;
            i += cur_w_len;
            if (s[i] == '\0') break;
        }
    }
    return s_arr;
}

t_link *split_the_link(const char *s)
{
    t_link *bridge = malloc(sizeof(*bridge));
    char **s1 = m_strsplit(s, ',');
    bridge->weight = mx_atoi(s1[1]);
    char **s2 = m_strsplit(s1[0], '-');
    bridge->first = mx_strdup(s2[0]);
    bridge->second = mx_strdup(s2[1]);
    mx_del_strarr(&s2);
    mx_del_strarr(&s1);
    return bridge;
}

