/*
** dclist2.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 17:39:22 2008 christophe sundas
** Last update Thu Dec  4 18:31:04 2008 christophe sundas
*/

#include <stdlib.h>
#include "my_select.h"

void	display_dclist(t_dclist list)
{
  list.cur = list.first;
  while (list.cur != list.last)
    {
      my_putstr2(list.cur->data);
      my_putchar2('\n');
      list.cur = list.cur->next;
    }
}

int	is_empty(t_dclist list)
{
  return (list.last == list.first);
}

int	my_dclist_size(t_dclist list)
{
  int	i;

  i = 0;
  list.cur = list.first;
  while (list.cur != list.last)
    {
      i++;
      list.cur = list.cur->next;
    }
  return (i);
}

int	find_pos(t_dclist list, t_dnode *node)
{
  int	i;

  i = 0;
  list.cur = list.first;
  while (list.cur != list.last)
    {
      if (list.cur == node)
        return (i);
      list.cur = list.cur->next;
      i++;
    }
  return (-1);
}

t_dnode	*find_at(int pos, t_dclist list)
{
  int	i;

  i = 0;
  if (pos >= my_dclist_size(list))
    return (NULL);
  list.cur = list.first;
  while (i < pos)
    {
      list.cur = list.cur->next;
      i++;
    }
  return (list.cur);
}
