/*
** my_select.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 18:21:24 2008 christophe sundas
** Last update Thu Dec  4 22:26:48 2008 christophe sundas
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "my_select.h"

t_dclist	g_list;

void	my_select()
{
 
  g_list.first->underline = 1;
  output_list();
  my_setkey();
  set_invisible_curs();
  my_getkey();
}

int		main(int ac, char **av)
{
  int		i;
  t_dnode	*node;
 
  signal(SIGWINCH, sigwinch);
  i = ac - 1;
  my_clearscreen();
  set_color(0, 2);
  g_list = mk_dclist();
  while (i > 0)
    {
      node = mk_node();
      node->data = my_strdup(av[i]);
      node->selected = 0;
      node->underline = 0;
      my_put_in_dclist(&g_list, node);
      i--;
    }
  my_select();
  my_free_dclist(&g_list);
  return (0);
}

void	my_exit()
{
  my_clearscreen();
  my_free_dclist(&g_list);
  set_visible_curs();
  set_color(0, 7);
  exit(0);
}

void	my_exit2()
{
  my_free_dclist(&g_list);
  set_visible_curs();
  set_color(0, 7);
  exit(0);
}
