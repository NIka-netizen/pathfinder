#include "../inc/pathfinder.h"

void find_path(int *weights, char **islands, t_link **bridges, int num_islands)
{
    char **visited = malloc(num_islands * sizeof *visited);
    char *cur;
    int moves = 0;
    int weight = 0;
    int i = 0, j = 0;
    bool n = true;
    while (i < num_islands)
    {
        int min = 0;
        while (n == true)
        {
            n = false;
            for (int i = 0; i < moves; i++)
            {
                if (!mx_strcmp(visited[i], islands[min]))
                    n = true;
            }
            min++;
        }
        if (moves == num_islands)
            break;
        for (j = 0; j < num_islands; j++)
        {
            if (is_visited(visited, islands[j], moves))
                continue;
            if (weights[j] >= 0 && (weights[min] < 0 || weights[min] > weights[j]))
            {
                min = j;
            }
        }
        cur = islands[min];
        for (j = 0; bridges[j] != NULL; j++)
        {
            if (!mx_strcmp(bridges[j]->first, cur))
            {
                if (is_visited(visited, bridges[j]->second, moves))
                    continue;
                int k = 0;
                weight = 0;
                while (islands[k] != NULL)
                {
                    if (!mx_strcmp(islands[k], cur))
                        weight = weights[k];
                    k++;
                }
                set_weight(&weights, islands, bridges[j]->second, weight + bridges[j]->weight);
            }
            else if (!mx_strcmp(bridges[j]->second, cur))
            {
                if (is_visited(visited, bridges[j]->first, moves))
                    continue;
                int k = 0;
                weight = 0;
                while (islands[k] != NULL)
                {
                    if (!mx_strcmp(islands[k], cur))
                        weight = weights[k];
                    k++;
                }
                set_weight(&weights, islands, bridges[j]->first, weight + bridges[j]->weight);
            }
        }
        visited[moves] = cur;
        moves++;
        i++;
    }
    free(visited);
}
