#include "../inc/pathfinder.h"

int get_path(int *length, int *weights, char **islands, t_link **bridges, int count, char *first, char **path, int *blocklist, int *block, int *permo_block)
{
    int len = 0;
    int weight = -1;
    int moves = 1;
    char *island = first;
    int prev_bridge_i = -1;
    path[0] = first;
    int connect_bridge = -1;
    bool f1 = true;
    int j = 0;
    while (j < count + 1 && f1)
    {
        bool f = true;
        int i = 0;
        int first_weight = 0;
        while (islands[i] != NULL)
        {
            if (!mx_strcmp(islands[i], first))
                first_weight = weights[i];
            i++;
        }
        for (int i = 0; bridges[i] != NULL; i++)
        {
            bool n = false;
            for (int l = 0; l < *block; l++)
            {
                if (blocklist[l] == i)
                    n = true;
            }
            if (n)
                continue;
            if (!mx_strcmp(bridges[i]->first, first))
            {
                island = bridges[i]->second;
                int k = 0;
                weight = 0;
                while (islands[k] != NULL)
                {
                    if (!mx_strcmp(islands[k], bridges[i]->second))
                        weight = weights[k];
                    k++;
                }
                len = bridges[i]->weight;
            }
            else if (!mx_strcmp(bridges[i]->second, first))
            {
                island = bridges[i]->first;
                int k = 0;
                weight = 0;
                while (islands[k] != NULL)
                {
                    if (!mx_strcmp(islands[k], bridges[i]->first))
                        weight = weights[k];
                    k++;
                }
                len = bridges[i]->weight;
            }
            else
                continue;
            if (first_weight < len)
                continue;
            if (weight == 0)
            {
                blocklist[*block] = i;
                *block += 1;
                path[moves] = island;
                length[moves - 1] = len;
                moves++;
                f1 = false;
                f = false;
                connect_bridge = i;
                break;
            }
            if (first_weight - len == weight)
            {
                prev_bridge_i = i;
                length[moves - 1] = len;
                first = island;
                path[moves] = first;
                moves++;
                f = false;
                break;
            }
        }
        if (f == true)
        {
            if (!mx_strcmp(first, path[0]))
            {
                return -1;
            }
            j = 0;
            first = path[0];
            moves = 1;
            blocklist[*block] = prev_bridge_i;
            *block += 1;
            if (!mx_strcmp(bridges[prev_bridge_i]->first, path[0]) || !mx_strcmp(bridges[prev_bridge_i]->second, path[0]))
            {
                blocklist[*permo_block] = prev_bridge_i;
                *permo_block += 1;
                *block = *permo_block;
            }
        }
        if (!f1 && (!mx_strcmp(bridges[connect_bridge]->first, path[0]) || !mx_strcmp(bridges[connect_bridge]->second, path[0])))
        {
            blocklist[*permo_block] = connect_bridge;
            *permo_block += 1;
            *block = *permo_block;
        }
        j++;
    }
    path[moves] = NULL;
    return moves;
}
