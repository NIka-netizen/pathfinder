#include "../inc/pathfinder.h"

t_link *split_the_links(const char *s)
{
    t_link *link = malloc(sizeof(*link));
    char **dist = malloc(sizeof(char **) * (mx_strlen(s)));
    while (*s == ',')
        s++;
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ',' && (s[i + 1] == ',' || s[i + 1] == '\0'))
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
        if (s[i] != ',')
        {
            cur_w_len = mx_get_char_index(&s[i], ',');
            if (cur_w_len == -1)
                cur_w_len = mx_strlen(&s[i]);
            s_arr[j] = mx_strndup(&s[i], cur_w_len);
            j++;
            i += cur_w_len;
            if (s[i] == '\0')
                break;
        }
    }
    dist = s_arr;
    link->weight = mx_atoi(dist[1]);
    char **island = malloc(sizeof(char **) * (mx_strlen(s)));

    ////////////////////////////////////////
    char const *s2 = dist[0];
    while (*s2 == '-')
        s2++;
    count = 0;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        if (s2[i] != '-' && (s2[i + 1] == '-' || s2[i + 1] == '\0'))
        {
            count++;
        }
    }
    char **s_ar = malloc((count + 1) * sizeof(char **));
    s_ar[count] = NULL;
    cur_w_len = 0;
    j = 0;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        if (s2[i] != '-')
        {
            cur_w_len = mx_get_char_index(&s2[i], '-');
            if (cur_w_len == -1)
                cur_w_len = mx_strlen(&s2[i]);
            s_ar[j] = mx_strndup(&s2[i], cur_w_len);
            j++;
            i += cur_w_len;
            if (s2[i] == '\0')
                break;
        }
    }

    ////////////////////////////////////////////
    island = s_ar;
    link->first = mx_strdup(island[0]);
    link->second = mx_strdup(island[1]);
    mx_del_strarr(&island);
    mx_del_strarr(&dist);
    return link;
}
