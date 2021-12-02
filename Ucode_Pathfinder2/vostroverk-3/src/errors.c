#include "../inc/pathfinder.h"
void errors(int argc, char *argv[])
{
   ////////////////////////////// check 1
   if (argc != 2)
   {
      /*mx_printerr("usage: ./pathfinder [filename]\n");
      exit(0);*/
   };
   //////////////////////////////// check 2
   int ffile = open(argv[1], O_RDONLY);
   if (ffile < 0)
   {
     /* mx_printerr("error: file ");
      mx_printerr(argv[1]);
      mx_printerr(" does not exist\n");
      exit(0);*/
   }
   ////////////////////////////////// check 3
   char buf;
   int n = read(ffile, &buf, 1);
   if (n <= 0)
   {
     /* mx_printerr("error: file ");
      mx_printerr(argv[1]);
      mx_printerr(" is empty\n");
      exit(0);*/
   }
   //////////////////////////////// check 4
   if (mx_isdigit(buf))
   {
      while (read(ffile, &buf, 1))
      {
         if (!mx_isdigit(buf) && buf != '\n')
         {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
         }
         if (buf == '\n')
            break;
      }
   }
   else
   {
      mx_printerr("error: line 1 is not valid\n");
      exit(0);
   }
   ////////////////////////////// check 5
   char *s = mx_file_to_str(argv[1]);
   int count_prob = 0, count_zap = 0;
   int i = 0, j = 0;
   while (i < mx_strlen(s))
   {
      j++;
      count_prob = 0;
      count_zap = 0;
      while (s[i] != '\n' && s[i] != '\0')
      {
         if (j == 1)
         {
            i++;
            continue;
         }
         if (s[i] == '-' || s[i] == ',')
         {
            if (s[i] == '-')
            {
               count_prob++;
            }
            if (s[i] == ',')
            {
               count_zap++;
            }
            if (s[i] == '-' && (!mx_isalpha(s[i - 1]) || !mx_isalpha(s[i + 1])))
            {
               mx_printerr("error: line ");
               mx_printerr(mx_itoa(j));
               mx_printerr(" is not valid\n");
               exit(0);
            }
            if (s[i] == ',' && (!mx_isalpha(s[i - 1]) || !mx_isdigit(s[i + 1])))
            {
               mx_printerr("error: line ");
               mx_printerr(mx_itoa(j));
               mx_printerr(" is not valid\n");
               exit(0);
            }
         }
         i++;
      }
      if ((count_prob != 1 || count_zap != 1) && j != 1)
      {
         ;
         mx_printerr("error: line ");
         mx_printerr(mx_itoa(j));
         mx_printerr(" is not valid\n");
         exit(0);
      }
      ///////////////////////////////////////// ckeck 6
      if (s[i + 1] == s[mx_strlen(s)] && s[i] != '\n')
      {
         mx_printerr("error: line ");
         mx_printerr(mx_itoa(j));
         mx_printerr(" is not valid\n");
         exit(0);
      }
      //////////////////////////////////////////
      i++;
   }
   ///////////////////////////////////////// check 7 number of islands
   int c = 1;
   i = 0;
   while (i < mx_strlen(s))
   {
      c++;
      i++;
   }
   char *str_dub = (char *)malloc(c);
   i = 0;
   int j1 = 0;
   int j2 = 0;
   int fl = 0;

   char *ch = (char *)malloc(c);
   while (s[i] != '\n')
   {
      ch[i] = s[i];
      i++;
   }

   i = 0;
   while (s[i] != '\0')
   {
      if (s[i] == '\n')
      {
         fl = 1;
      }
      if (fl == 1)
      {
         if (mx_isalpha(s[i]) || s[i] == '-' || s[i] == '\n')
         {
            str_dub[j1] = s[i];
            j1++;
         }
      }
      i++;
   }
   char seps[] = "-\n";
   char *token;
   char *tks[20];
   int it;
   int count;
   it = 0;
   count = 0;
   token = mx_strtok(str_dub, seps);
   while (token != NULL)
   {
      i = 0;
      while (i < it)
      {
         if (mx_strcmp(tks[i], token) == 0)
            break;
         i++;
      }
      if (i == it)
      {
         if (it == 20)
         {
            break;
         }
         tks[it] = (char *)malloc(mx_strlen(token) + 1);
         mx_strcpy(tks[it], token);
         it++;
         count++;
      }
      else
         count--;
      token = mx_strtok(NULL, seps);
   }
   int ch1 = mx_atoi(ch);
   if (ch1 != it)
   {
      mx_printerr("error: invalid number of islands\n");
      exit(0);
   }
   /////////////////////////////////// check 8
   c = 1;
   i = 0;
   while (i < mx_strlen(s))
   {
      c++;
      i++;
   }
   char *bridges1 = (char *)malloc(c);
   char *bridges2 = (char *)malloc(c);
   i = 0;
   j = 0;
   j1 = 0;
   j2 = 0;
   fl = 0;
   while (s[i] != '\0')
   {
      mx_memset(bridges1, 0, mx_strlen(bridges1));
      mx_memset(bridges2, 0, mx_strlen(bridges2));
      if (s[i] == '\n')
      {
         fl = 1;
      }
      if (fl == 1)
      {
         while (s[i] != '\n' && !mx_isdigit(s[i]))
         {
            j++;
            while (s[i] != '-')
            {
               bridges1[j1] = s[i];
               i++;
               j1++;
            }
            i++;
            while (s[i] != ',')
            {
               bridges2[j2] = s[i];
               i++;
               j2++;
            }
            if ((mx_strcmp(bridges1, bridges2)) == 0)
            {
               mx_printerr("error: line ");
               mx_printerr(mx_itoa(j + 1));
               mx_printerr(" is not valid\n");
               exit(0);
            }
            i++;
         }
         j1 = 0;
         j2 = 0;
      }
      i++;
   }
   /////////////////////////////////////////// check 9
   i = 0;
   j = 0;
   j1 = 0;
   j2 = 0;
   fl = 0;
   while (s[i] != '\0')
   {
      if (s[i] == '\n')
      {
         fl = 1;
      }
      if (fl == 1)
      {
         while (s[i] != '\n' && !mx_isdigit(s[i]))
         {
            j++;
            while (s[i] != ',')
            {
               bridges1[j1] = s[i];
               i++;
               j1++;
            }
            i++;
            if (mx_strcmp(bridges1, bridges2) == 0)
            {
               mx_printerr("error: duplicate bridges\n");
               exit(0);
            }
            mx_strncpy(bridges2, bridges1, mx_strlen(bridges1));
         }
         j1 = 0;
         j2 = 0;
      }
      i++;
   }

   char *tmp1 = (char *)malloc(c);
   char *tmp2 = (char *)malloc(c);
   char *rever_brige = (char *)malloc(c);
   i = 0;
   j1 = 0;
   j2 = 0;
   fl = 0;
   while (s[i] != '\0')
   {
      mx_memset(tmp1, 0, mx_strlen(tmp1));
      mx_memset(tmp2, 0, mx_strlen(tmp2));
      if (s[i] == '\n')
      {
         fl = 1;
      }
      if (fl == 1)
      {
         while (s[i] != '\n' && !mx_isdigit(s[i]))
         {
            while (s[i] != '-')
            {
               tmp1[j1] = s[i];
               i++;
               j1++;
            }
            i++;
            while (s[i] != ',')
            {
               tmp2[j2] = s[i];
               i++;
               j2++;
            }
            i++;
         }
         j1 = 0;
         j2 = 0;
         rever_brige = mx_strjoin(rever_brige, tmp2);
         rever_brige = mx_strjoin(rever_brige, "-");
         rever_brige = mx_strjoin(rever_brige, tmp1);
         int q = 0;
         int it = 0;
         int fl2 = 0;
         while (s[q] != '\0')
         {
            mx_memset(bridges1, 0, mx_strlen(bridges1));
            if (s[q] == '\n')
            {
               fl2 = 1;
            }
            if (fl2 == 1)
            {
               while (s[q] != '\n' && !mx_isdigit(s[q]))
               {
                  while (s[q] != ',')
                  {
                     bridges1[it] = s[q];
                     q++;
                     it++;
                  }
                  q++;
                  if (mx_strcmp(bridges1, rever_brige) == 0)
                  {
                     mx_printerr("error: duplicate bridges\n");
                     exit(0);
                  }
                  mx_strncpy(rever_brige, bridges1, mx_strlen(bridges1));
               }
               it = 0;
            }
            q++;
         }
         rever_brige = NULL;
      }
      i++;
   }
   /////////////////////////////////////////// check 10
   i = 0;
   int sum = 0;
   char *pop = (char *)malloc(c);
   int from_pop;
   fl = 0;
   while (s[i] != '\0')
   {
      if (s[i] == '\n')
      {
         fl = 1;
      }
      if (fl == 1)
      {
         j = 0;
         from_pop = 0;
         mx_memset(pop, 0, mx_strlen(pop));
         while (s[i] != '\n')
         {
            if (mx_isdigit(s[i]))
            {
               pop[j] = s[i];
               j++;
            }
            i++;
         }
         from_pop = mx_atoi(pop);
         sum += from_pop;
      }
      i++;
   }
   if (sum > 2147483647 || sum < 0) {
      mx_printerr("error: sum of bridges lengths is too big\n");
      exit(0);
   }
   close(ffile);
   mx_memset(pop, 0, mx_strlen(pop));
   free(s);
   free(tmp1);
   free(tmp2);
   free(rever_brige);
   free(bridges1);
   free(bridges2);
   free(str_dub);
}
