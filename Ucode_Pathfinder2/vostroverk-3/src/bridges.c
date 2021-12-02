#include "../inc/pathfinder.h"

char *dub_string(char *s)
{
                    int c = 1;
                    int i = 0;
                    while (i < mx_strlen(s))
                    {
                                        c++;
                                        i++;
                    }
                    char *d_str = (char *)malloc(c);
                    i = 0;
                    int j1 = 0;
                    int fl = 0;
                    while (s[i] != '\0')
                    {
                                        if (s[i] == '\n')
                                        {
                                                            fl++;
                                        }
                                        if (fl > 0)
                                        {
                                                            d_str[j1] = s[i];
                                                            j1++;
                                        }
                                        i++;
                    }
                    return d_str;
}
