#include "../inc/pathfinder.h"

void del_links(t_link ***bridges)
{
    for (int i = 0; (*bridges)[i] != NULL; i++)
    {
        mx_strdel(&(*bridges)[i]->first);
        mx_strdel(&(*bridges)[i]->second);
        free((*bridges)[i]);
    }
    *bridges = NULL;
}
