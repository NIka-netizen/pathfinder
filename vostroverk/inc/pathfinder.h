#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx.h"
#include <limits.h>

typedef struct s_island {
    char *name; //здесь просто одна строка имени
    t_list *bridges; //мосты, которые связаны с этой вершиной
    int flag;
}t_island;

typedef struct s_links
{
    int weight;
    char *first;
    char *second;
} t_link;


void errors(int argc, char *argv[]);
void path(char *argv[]);
t_link *split_the_link(const char *s);
void althorithm(t_link **bridges, char **islands, int n, int count);
void del_links(t_link ***bridges);
void find_path(int *weights, char **island, t_link **bridges, int count);
void print_path(int *weights, char **islands, t_link **bridges, int count, char *from, int bridge_count);
void set_weight(int **weights, char **island, char *s, int waight);
bool is_gone(int c, int *blacklist, int size);
int get_path(int *len, int *weights, char **islands, t_link **bridges, int count, char *from, char **path, int *gone, int *block, int *tmp);
int get_weight(char **islands, int *weights, char *s);
bool visited(char **drawed, char *s, int draws);
int island_index(char **island, char *node);
#endif
