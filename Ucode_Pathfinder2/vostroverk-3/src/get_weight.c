#include "../inc/pathfinder.h"

int get_weight(char **islands, int *weights, char *s)
{
    int i = 0;
    while (islands[i] != NULL)
    {
        if (!mx_strcmp(islands[i], s)) return weights[i];
        i++;
    }
    return 0;
}
