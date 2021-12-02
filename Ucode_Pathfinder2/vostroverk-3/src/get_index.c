#include "../inc/pathfinder.h"

int get_index(char **all_of_islands, char *one_of_island)
{
    int index = 0;
    while(all_of_islands[index] != NULL)
    {
        if (!mx_strcmp(all_of_islands[index], one_of_island)) return index;
        index++;
    }
    return -1;
}
