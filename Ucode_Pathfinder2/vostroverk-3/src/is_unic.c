#include "../inc/pathfinder.h"

bool is_unic(char *island, char **islands)
{
    int i = 0;
    while (islands[i])
    {
        if (mx_strcmp(island, islands[i]) == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
