#include "../inc/pathfinder.h"

int island_index(char **island, char *node)
{
    for (int i = 0; island[i] != NULL; i++)
    {
        if (!mx_strcmp(island[i], node)) return i;
    }
    return -1;
}

