#include "../inc/pathfinder.h"

bool visited(char **drawed, char *s, int draws)
{
    for (int i = 0; i < draws; i++)
    {
        if (!mx_strcmp(drawed[i], s)) return true;
    }
    return false;
}
