#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "../libmx/inc/libmx.h"

typedef struct s_link
{
    int weight;
    char *first;
    char *second;
} t_link;

void path(int argc, char *argv[], t_list *sort_islands_unic, t_list *all_bridges);
void errors(int argc, char *argv[]);
int num_vershin(t_list *is_unic);
int num_of_bridges(t_list *bridges);
char *dub_string(char *s);
void mx_print_list(t_list *head);
t_link *swap (t_link **bridges, char **islands);
int get_index(char **all_of_islands, char *one_of_island);
t_link *split_the_links(const char *s);
bool is_unic(char *island, char **islands);
void algorithm(t_link **bridges, char **islands, int num_islands, int num_bridges);
void set_weight(int **weights, char **islands, char *s, int waight);
void find_path(int *weights, char **islands, t_link **bridges, int num_islands);
int get_weight(char **islands, int *weights, char *s);
void print_path(int *weights, char **nodes, t_link **bridges, int count, char *from, int bridge_count);
int get_path(int *length, int *weights, char **islands, t_link **bridges, int count, char *from, char **path, int *blacklist, int *block, int *permo_block);
bool is_visited(char **visited, char *s, int visits);
bool unic_island(char *island, char **islands);

#endif
