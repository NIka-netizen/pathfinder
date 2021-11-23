#include "../inc/pathfinder.h"

void find_path(int *weights, char **island, t_link **bridges, int count)
{
    char **drawed = malloc(count * sizeof *drawed);
    char *curr;
    int draws = 0;
    int min = 0;
    int weight = 0;
    for (int i = 0; i < count; i++)
    {
        min = 0;
        while (visited(drawed, island[min], draws)) min++;
        if (draws == count) break;
        for (int j = 0; j < count; j++)
        {
            if (visited(drawed, island[j], draws)) continue;
            if (weights[j] >= 0 && (weights[min] < 0 || weights[min] > weights[j]))
            {
                min = j;
            }
        }
        curr = island[min];
        for (int j = 0; bridges[j] != NULL; j++)
        {
            if (!mx_strcmp(bridges[j]->first, curr))
            {
                if (visited(drawed, bridges[j]->second, draws)) continue;
                weight = get_weight(island, weights, curr);
                set_weight(&weights, island, bridges[j]->second, weight + bridges[j]->weight);
            }
            else if (!mx_strcmp(bridges[j]->second, curr))
            {
                if (visited(drawed, bridges[j]->first, draws)) continue;
                weight = get_weight(island, weights, curr);
                set_weight(&weights, island, bridges[j]->first, weight + bridges[j]->weight);
            }
        }
        drawed[draws] = curr;
        draws++;
    }
    free(drawed);
}
