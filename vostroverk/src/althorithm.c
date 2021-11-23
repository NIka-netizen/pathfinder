#include "../inc/pathfinder.h"

void althorithm(t_link **bridges, char **islands, int n, int count)
{
    t_link *buf;

    for (int i = 0; bridges[i] != NULL; i++)
    {
        for (int j = i + 1; bridges[j] != NULL; j++)
        {
            if (island_index(islands, bridges[i]->first) +
                island_index(islands, bridges[i]->second) >
                island_index(islands, bridges[j]->first) +
                island_index(islands, bridges[j]->second))
            {
                buf = bridges[i];
                bridges[i] = bridges[j];
                bridges[j] = buf;
            }
        }
    }

    int *weights = malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int z = 0; z < n; z++) weights[z] = -1;
            set_weight(&weights, islands, islands[j], 0);
            find_path(weights, islands, bridges, n);
            print_path(weights, islands, bridges, n, islands[i], count);
        }
    }

    del_links(&bridges);
    mx_del_strarr(&islands);
}
