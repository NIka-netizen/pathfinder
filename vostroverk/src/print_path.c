#include "../inc/pathfinder.h"

void print_path(int *weights, char **islands, t_link **bridges, int count, char *from, int bridge_count)
{
    char **path = malloc((count + 1) * sizeof (*path));
    int *dist = malloc(count * sizeof *dist);
    int *gone = malloc(bridge_count * sizeof (*gone));
    int tmp = 0;
    int blocked = 0;
    path[count] = NULL;
    int moves;
    while (1)
    {
        moves = get_path(dist, weights, islands, bridges, count, from, path, gone, &blocked, &tmp);
        if (moves == -1) break;

        for (int i = 0; i < 40; i++) mx_printchar('=');
        mx_printchar('\n');

        mx_printstr("Path: ");
        mx_printstr(path[0]);
        mx_printstr(" -> ");
        mx_printstr(path[moves - 1]);
        mx_printchar('\n');
        mx_printstr("Route: ");
        mx_print_strarr(path, " -> ");
        mx_printstr("Distance: ");
        int sum = 0;
        for (int i = 0; i < moves - 1; i++)
        {
            sum += dist[i];
            mx_printint(dist[i]);
            if (i + 1 != moves - 1) mx_printstr(" + ");
        }
        if (sum != dist[0])
        {
            mx_printstr(" = ");
            mx_printint(sum);
        }
        mx_printchar('\n');
        for (int i = 0; i < 40; i++) mx_printchar('=');
        mx_printchar('\n');
    }
    free(dist);
    free(path);
    free(gone);
}
