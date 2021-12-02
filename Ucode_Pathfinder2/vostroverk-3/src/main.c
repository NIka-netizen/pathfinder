#include "../inc/pathfinder.h"

int main(int argc, char *argv[])
{
    ////////////////////////////// check 1
   if (argc != 2)
   {
      mx_printerr("usage: ./pathfinder [filename]\n");
      exit(0);
   };
   //////////////////////////////// check 2
   int ffile = open(argv[1], O_RDONLY);
   if (ffile < 0)
   {
      mx_printerr("error: file ");
      mx_printerr(argv[1]);
      mx_printerr(" does not exist\n");
      exit(0);
   }
   ////////////////////////////////// check 3
   char buff;
   int n = read(ffile, &buff, 1);
   if (n <= 0)
   {
      mx_printerr("error: file ");
      mx_printerr(argv[1]);
      mx_printerr(" is empty\n");
      exit(0);
   }
     t_list *sort_islands_unic = NULL;
                    t_list *all_bridges = NULL;
                    char *s = mx_file_to_str(argv[1]);
                    char *str = dub_string(s);
                    ////////////////////////////////////////// list_of_islands ->

                    int i = 0, col_line = 0;
                    while (str[i] != '\0')
                    {
                                        while (str[i] != '\n')
                                        {
                                                            i++;
                                        }
                                        col_line++;
                                        i++;
                    }

                    i = 0;
                    while (str[i] != '\n')
                    {
                                        i++;
                    }
                    i++;

                    t_list *first_b = NULL;
                    int num_line = 0;
                    char *temp = &str[i];
                    t_list *cur_b = first_b;
                    int size_b;

                    while (str[i + 1] != '\0')
                    {
                                        num_line++;
                                        size_b = 0;
                                        temp = &str[i];
                                        while (str[i] != '\n')
                                        {
                                                            size_b++;
                                                            i++;
                                        }

                                        mx_push_back(&cur_b, temp);
                                        if (num_line == 1)
                                        {
                                                            first_b = cur_b;
                                        }
                                        i++;
                                        if (cur_b->next != NULL)
                                                            cur_b = cur_b->next;
                    }

                    int size_1 = 0, size_2 = 0;
                    sort_islands_unic = NULL;
                    t_list *cur_island = sort_islands_unic;
                    cur_b = first_b;
                    for (i = 0; i < col_line - 1; i++)
                    {
                                        size_1 = 0;
                                        size_2 = 0;
                                        char *temp_b = cur_b->data;

                                        while (temp_b[size_1] != '-')
                                                            size_1++;
                                        char *smth_str1 = mx_strnew(size_1);
                                        mx_strncpy(smth_str1, temp_b, size_1);
                                        while (temp_b[size_1 + 1 + size_2] != ',')
                                                            size_2++;
                                        char *smth_str2 = mx_strnew(size_2);
                                        mx_strncpy(smth_str2, &temp_b[size_1 + 1], size_2);
                                        mx_push_back(&cur_island, smth_str1);
                                        if (i == 0)
                                                            sort_islands_unic = cur_island;
                                        if (cur_island->next != NULL)
                                                            cur_island = cur_island->next;
                                        mx_push_back(&cur_island, smth_str2);
                                        if (cur_island->next != NULL)
                                                            cur_island = cur_island->next;
                                        if (cur_b->next != NULL)
                                                            cur_b = cur_b->next;
                    }
                    t_list *pli = sort_islands_unic;
                    t_list *plj = sort_islands_unic;
                    t_list *buf;

                    while (pli->next != NULL)
                    {
                                        while (plj->next != NULL)
                                        {
                                                            if (mx_strcmp(plj->data, plj->next->data) > 0)
                                                            {
                                                                                buf = mx_create_node(plj->data);
                                                                                plj->data = plj->next->data;
                                                                                plj->next->data = buf->data;
                                                                                free(buf);
                                                            }
                                                            plj = plj->next;
                                        }
                                        plj = sort_islands_unic;
                                        pli = pli->next;
                    }
                    cur_island = sort_islands_unic;
                    i = 0;
                    while (cur_island->next != NULL)
                    {
                                        while (mx_strcmp(cur_island->data, cur_island->next->data) == 0 && cur_island->next->next != NULL)
                                        {
                                                            cur_island->next = cur_island->next->next;
                                        }
                                        if (cur_island->next->next == NULL)
                                        {
                                                            if (mx_strcmp(cur_island->data, cur_island->next->data) == 0)
                                                            {
                                                                                cur_island->next = NULL;
                                                            }
                                                            break;
                                        }
                                        cur_island = cur_island->next;
                    }
                    ////////////////////////////////////////////// list_of_links ->

                    i = 0;
                    while (str[i] != '\n')
                    {
                                        i++;
                    }
                    i++;
                    first_b = NULL;
                    num_line = 0;
                    temp = &str[i];
                    cur_b = first_b;
                    while (str[i + 1] != '\0')
                    {
                                        num_line++;
                                        size_b = 0;
                                        temp = &str[i];
                                        while (str[i] != '\n')
                                        {
                                                            size_b++;
                                                            i++;
                                        }
                                        mx_push_back(&cur_b, temp);
                                        if (num_line == 1)
                                        {
                                                            first_b = cur_b;
                                        }
                                        i++;
                                        if (cur_b->next != NULL)
                                                            cur_b = cur_b->next;
                    }
                    size_1 = 0, size_2 = 0;
                    all_bridges = NULL;
                    cur_island = all_bridges;
                    cur_b = first_b;
                    for (i = 0; i < col_line - 1; i++)
                    {
                                        size_1 = 0;
                                        char *temp_b1 = cur_b->data;

                                        while (temp_b1[size_1] != '\n')
                                                            size_1++;
                                        char *str1 = mx_strnew(size_1);
                                        mx_strncpy(str1, temp_b1, size_1);

                                        mx_push_back(&cur_island, str1);
                                        if (i == 0)
                                                            all_bridges = cur_island;
                                        if (cur_island->next != NULL)
                                                            cur_island = cur_island->next;
                                        if (cur_b->next != NULL)
                                                            cur_b = cur_b->next;
                    }
    /////////////////////////////////////////////
    path(argc, argv, sort_islands_unic, all_bridges);
}
