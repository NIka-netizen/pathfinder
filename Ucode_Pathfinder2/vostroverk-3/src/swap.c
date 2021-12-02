#include "../inc/pathfinder.h"

t_link *swap (t_link **bridges, char **islands)
{
    t_link *c;
    int i = 0;
    while (bridges[i] != NULL)
    {
        int j = i + 1;
        while (bridges[j] != NULL)
        {
            if (get_index(islands, bridges[i]->first) +
                get_index(islands, bridges[i]->second) >
                get_index(islands, bridges[j]->first) +
                get_index(islands, bridges[j]->second))
            {
                c = bridges[i];
                bridges[i] = bridges[j];
                bridges[j] = c;
            }
            j++;
        }
        i++;
    }
    return *bridges;
}
