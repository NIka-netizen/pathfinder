#include "../inc/pathfinder.h"

char *dub_string(char *s)
{
   int c = 1;
   int i = 0;
   while (i < mx_strlen(s))
   {
      c++;
      i++;
   }
   char *d_str = (char *)malloc(c);
   i = 0;
   int j1 = 0;
   int fl = 0;
   while (s[i] != '\0')
   {
      if (s[i] == '\n')
      {
         fl++;
      }
      if (fl > 0)
      {
         d_str[j1] = s[i];
         j1++;
      }
      i++;
   }
   return d_str;
}

int num_vershin(char *s)
{
   int c = 1, i = 0, n;
   while (i < mx_strlen(s))
   {
      c++;
      i++;
   }
   i = 0;
   char *ch = (char *)malloc(c);
   while (s[i] != '\n')
   {
      ch[i] = s[i];
      i++;
   }
   n = mx_atoi(ch);
   return n;
}

void mx_print_list(void *head)
{
   t_list *cur = head;
   while (cur != NULL)
   {
      write(1, cur->data, mx_strlen(cur->data));
      write(1, "\n", 1);
      cur = cur->next;
   }
}

bool unic_island(char *island, char **islands){
    int i = 0;
    while(islands[i]){
        if(mx_strcmp(island, islands[i]) == 0){
            return false;
        }
        i++;
    }
    return true;
}

void path(char *argv[])
{
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
   t_list *island_1 = NULL;
   t_list *cur_island = island_1;
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
         island_1 = cur_island;
      if (cur_island->next != NULL)
         cur_island = cur_island->next;
      mx_push_back(&cur_island, smth_str2);
      if (cur_island->next != NULL)
         cur_island = cur_island->next;
      if (cur_b->next != NULL)
         cur_b = cur_b->next;
   }

   t_list *pli = island_1;
   t_list *plj = island_1;
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
      plj = island_1;
      pli = pli->next;
   }
   cur_island = island_1;
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
   t_list *all_bridges = NULL;
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
   //////////////////////// fill the matrix of islands ->

   int n = num_vershin(s);
   char **islands = malloc((n + 1) * sizeof(char **));
    islands[n] = NULL;
   ////////////////////// fill the structure of islands (weight, first_is, second_is) ->
   int count = 0;
   i = 0;
   while (str[i] != '\0')
   {
      if (str[i] == '\n')
         count++;
      i++;
   }
   t_link **links = malloc(count * sizeof(t_link));
   links[count] = NULL;
   i = 0;
   int j = 0;
   t_list *cur_bridge = all_bridges;
   while (cur_bridge != NULL)
   {
      int first_size = 0;
      int second_size = 0;
      char *temp_bridge = cur_bridge->data;
      while (temp_bridge[first_size] != '-')
      {
         first_size++;
      }
      char *t1 = mx_strnew(first_size);
      mx_strncpy(t1, temp_bridge, first_size);
      if (unic_island(t1, islands))
      {
         islands[j] = t1;
         j++;
      }
      while (temp_bridge[first_size + 1 + second_size] != ',')
      {
         second_size++;
      }
      char *t2 = mx_strnew(second_size);
      mx_strncpy(t2, &temp_bridge[first_size + 1], second_size);
      if (unic_island(t2, islands))
      {
         islands[j] = t2;
         j++;
      }
      links[i] = split_the_link(cur_bridge->data);
      cur_bridge = cur_bridge->next;
      i++;
   }
   althorithm(links, islands, n, count);
}
