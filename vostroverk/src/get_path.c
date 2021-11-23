#include "../inc/pathfinder.h"

int get_path(int *len, int *weights, char **islands, t_link **bridges, int count, char *from, char **path, int *gone, int *block, int *tmp)
{
    int length;
    int weight = -1;
    int prev_bridge = -1;
    int link_bridge = -1;
    int start_node_weight;
    int steps = 1;
    char *node1 = from;
    path[0] = from;
    bool f1 = true;
    for (int j = 0; j < count + 1 && f1; j++)
    {
        bool f2 = true;
        start_node_weight = get_weight(islands, weights, from);
        for (int i = 0; bridges[i] != NULL; i++)
        {
            if (is_gone(i, gone, *block)) continue;
            if (!mx_strcmp(bridges[i]->first, from))
            {
                node1 = bridges[i]->second;
                weight = get_weight(islands, weights, bridges[i]->second);
                length = bridges[i]->weight;
            }
            else if (!mx_strcmp(bridges[i]->second, from))
            {
                node1 = bridges[i]->first;
                weight = get_weight(islands, weights, bridges[i]->first);
                length = bridges[i]->weight;
            }
            else continue;
            if (start_node_weight < length) continue;
            if (weight == 0)
            {
                gone[*block] = i;
                *block += 1;
                path[steps] = node1;
                len[steps - 1] = length;
                steps++;
                f1 = false;
                f2 = false;
                link_bridge = i;
                break;
            }
            if (start_node_weight - length == weight)
            {
                prev_bridge = i;
                len[steps - 1] = length;
                from = node1;
                path[steps] = from;
                steps++;
                f2 = false;
                break;
            }
        }
        if (f2 == true)
        {
            if (!mx_strcmp(from, path[0]))
            {
                return -1;
            }
            j = 0;
            from = path[0];
            steps = 1;
            gone[*block] = prev_bridge;
            *block += 1;
            if (!mx_strcmp(bridges[prev_bridge]->first, path[0])
                || !mx_strcmp(bridges[prev_bridge]->second, path[0]))
            {
                gone[*tmp] = prev_bridge;
                *tmp += 1;
                *tmp = *tmp;
            }
        }
        if (!f1 && (!mx_strcmp(bridges[link_bridge]->first, path[0])
            || !mx_strcmp(bridges[link_bridge]->second, path[0])))
        {
            gone[*tmp] = link_bridge;
            *tmp += 1;
            *block = *tmp;
        }
    }
    path[steps] = NULL;
    return steps;
}
