/*
** redim2.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 18:38:06 2008 christophe sundas
** Last update Thu Dec  4 18:38:53 2008 christophe sundas
*/

#include "my.h"
#include "my_select.h"

void	display_col(int lenword, int max)
{
  my_putchar2(' ');
  while (lenword < max)
    {
      my_putchar2(' ');
      lenword++;
    }
}

void	display_node(int *i, int nbcol, int *itab)
{
  output_node(g_list.cur);
  if (*i == nbcol)
    {
      if (g_list.cur->next != g_list.last)
        my_putchar2('\n');
      *i = 0;
    }
  else
    {
      if (g_list.cur->next != g_list.last)
        display_col(my_strlen(g_list.cur->data), itab[(*i) - 1]);
    }
}
