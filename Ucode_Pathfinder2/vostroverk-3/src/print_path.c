#include "../inc/pathfinder.h"

void print_path(int *weights, char **islands, t_link **bridges, int count_of_islands, char *from, int bridge_count)
{
    int *dist = malloc(count_of_islands * sizeof *dist);
    char **path = malloc((count_of_islands + 1) * sizeof *path);
    path[count_of_islands] = NULL;
    int *blocklist = malloc(bridge_count * sizeof *blocklist);
    int perm_blocked = 0;
    int steps = 0;
    int blocked = 0;
    while (1)
    {
        steps = get_path(dist, weights, islands, bridges, count_of_islands, from, path, blocklist, &blocked, &perm_blocked);
        if (steps == -1) break;

        for (int i = 0; i < 40; i++) write(1, "=", 1);
        mx_printchar('\n');

        write(1, "Path: ", 6);
        write(1, path[0], mx_strlen(path[0]));
        write(1, " -> ", 4);
        write(1, path[steps - 1], mx_strlen(path[steps - 1]));
        mx_printchar('\n');
        write(1, "Route: ", 7);
        mx_print_strarr(path, " -> ");
        write(1, "Distance: ", 10);
        int sum = 0;
        for (int i = 0; i < steps - 1; i++)
        {
            sum += dist[i];
            mx_printint(dist[i]);
            if (i + 1 != steps - 1) write(1, " + ", 3);
        }
        if (sum != dist[0])
        {
            write(1, " = ", 3);
            mx_printint(sum);
        }
        mx_printchar('\n');
        for (int i = 0; i < 40; i++) write(1, "=", 1);
        mx_printchar('\n');
    }
    free(dist);
    free(path);
    free(blocklist);
}
