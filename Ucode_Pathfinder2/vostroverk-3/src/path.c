#include "../inc/pathfinder.h"

void path(int argc, char *argv[], t_list *sort_islands_unic, t_list *all_bridges)
{
    int num_ver = num_vershin(sort_islands_unic);
    int num_bridges = num_of_bridges(all_bridges);

    char **islands = malloc((num_ver + 1) * sizeof(char **));
    islands[num_ver] = NULL;

    errors(argc, argv);

    t_link **bridges = malloc((num_bridges + 1) * sizeof(t_link));
    bridges[num_bridges] = NULL;
    t_list *cur_bridge = all_bridges;

    int i = 0;
    int j = 0;
  while (cur_bridge != NULL)
                    {
                                        int k = 0;
                                        int first = 0;
                                        int second = 0;
                                        char *temp_bridge = cur_bridge->data;
                                        char *temp_island = mx_strnew(mx_strlen(temp_bridge));
                                        while (temp_bridge[first] != '-')
                                        {
                                                            temp_island[k] = temp_bridge[first];
                                                            k++;
                                                            first++;
                                        }
                                        char *temp1 = mx_strnew(first);
                                        mx_strcpy(temp1, temp_island);
                                        if (is_unic(temp1, islands))
                                        {
                                                            islands[j] = temp1;
                                                            j++;
                                        }
                                        mx_memset(temp_island, 0, mx_strlen(temp_island));
                                        temp_island = mx_strnew(mx_strlen(temp_bridge));
                                        k = 0;
                                        while (temp_bridge[first + 1 + second] != ',')
                                        {
                                                            second++;
                                        }
                                        char *temp2 = mx_strnew(second);
                                        mx_strncpy(temp2, &temp_bridge[first + 1], second);
                                        if (is_unic(temp2, islands))
                                        {
                                                            islands[j] = temp2;
                                                            j++;
                                        }
                                        bridges[i] = split_the_links(cur_bridge->data);
                                        i++;
                                        cur_bridge = cur_bridge->next;
                                        mx_memset(temp_island, 0, mx_strlen(temp_island));
                    }
                    algorithm(bridges, islands, num_ver, num_bridges);
}
