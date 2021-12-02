#include "../inc/pathfinder.h"

int num_of_bridges(t_list *bridges)
{
                    int count = 0;
                    while (bridges != NULL)
                    {
                                        count++;
                                        bridges = bridges->next;
                    }
                    return count;
}
