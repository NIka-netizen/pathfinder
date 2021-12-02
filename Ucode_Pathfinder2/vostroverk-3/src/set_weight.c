#include "../inc/pathfinder.h"

void set_weight(int **weights, char **islands, char *s, int waight)
{
    int l = 0;
    while (islands[l] != NULL)
    {
        if (!mx_strcmp(islands[l], s))
        {
            if ((*weights)[l] < waight && (*weights)[l] > 0) return;
            (*weights)[l] = waight;
            return;
        }
        l++;
    }
}
