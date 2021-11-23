#include "../inc/pathfinder.h"

bool is_gone(int c, int *blacklist, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (blacklist[i] == c) return true;
    }
    return false;
}
