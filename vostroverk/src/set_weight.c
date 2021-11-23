#include "../inc/pathfinder.h"

void set_weight(int **weights, char **island, char *s, int waight)
{
    for (int i = 0; island[i] != NULL; i++)
    {
        if (!mx_strcmp(island[i], s))
        {
            if ((*weights)[i] < waight && (*weights)[i] > 0) return;
            (*weights)[i] = waight;
            return;
        }
    }
}
