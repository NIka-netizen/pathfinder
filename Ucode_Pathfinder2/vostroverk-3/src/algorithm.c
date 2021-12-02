#include "../inc/pathfinder.h"

void algorithm(t_link **bridges, char **islands, int num_islands, int num_bridges)
{
    swap(bridges, islands);
    int *weights = malloc((num_islands + 1) * sizeof(int));
    int i = 0;
    while (i < num_islands - 1)
    {
        for (int j = i + 1; j < num_islands; j++)
        {
            for (int k = 0; k < num_islands; k++)
                weights[k] = -1;
            set_weight(&weights, islands, islands[j], 0);
            find_path(weights, islands, bridges, num_islands);
            print_path(weights, islands, bridges, num_islands, islands[i], num_bridges);
        }
        i++;
    }
    for (int i = 0; (bridges)[i] != NULL; i++)
    {
        mx_strdel(&(bridges)[i]->first);
        mx_strdel(&(bridges)[i]->second);
        free((bridges)[i]);
    }
    bridges = NULL;
    mx_del_strarr(&islands);
}
