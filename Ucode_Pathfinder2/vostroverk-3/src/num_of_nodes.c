#include "../inc/pathfinder.h"

int num_vershin(t_list *is_unic)
{
                    int n = 0;
                    while (is_unic != NULL)
                    {
                                        n++;
                                        is_unic = is_unic->next;
                    }
                    return n;
}
