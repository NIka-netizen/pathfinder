#include "../inc/libmx.h"

bool is_delim(char c, char *delim)
{
  while(*delim != '\0')
  {
    if(c == *delim)
      return 1;
    delim++;
  }
  return 0;
}

char *mx_strtok(char *s, char *delim)
{
  static char *p;
  if(!s)
  {
    s = p;
  }
  if(!s)
  {
    return NULL;
  }
  while(1)
  {
    if(is_delim(*s, delim))
    {
      s++;
      continue;
    }
    if(*s == '\0')
    {
      return NULL; 
    }
    break;
  }

  char *ret = s;
  while(1)
  {
    if(*s == '\0')
    {
      p = s; 
      return ret;
    }
    if(is_delim(*s, delim))
    {
      *s = '\0';
      p = s + 1;
      return ret;
    }
    s++;
  }
}

