/*
** mov_curs.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 18:44:27 2008 christophe sundas
** Last update Thu Dec  4 18:45:27 2008 christophe sundas
*/

#include "my_select.h"

t_dclist	g_list;

void		my_up_curs(int *pos)
{
  t_dnode	*cur_node;

  if (my_dclist_size(g_list) == 0)
    my_exit();
  cur_node = find_at(*pos, g_list);
  cur_node->underline = 0;
  cur_node = cur_node->prev;
  if (cur_node == g_list.last)
    cur_node = find_at(my_dclist_size(g_list) - 1, g_list);
  *pos = find_pos(g_list, cur_node);
  cur_node->underline = 1;
  output_list();
}

void		my_down_curs(int *pos)
{
  t_dnode	*cur_node;

  if (my_dclist_size(g_list) == 0)
    my_exit();
  cur_node = find_at(*pos, g_list);
  cur_node->underline = 0;
  cur_node = cur_node->next;
  if (cur_node == g_list.last)
    cur_node = g_list.first;
  *pos = find_pos(g_list, cur_node);
  cur_node->underline = 1;
  output_list();
}

void		my_refresh_curs(int *pos)
{
  t_dnode	*cur_node;

  if (my_dclist_size(g_list) == 0)
    my_exit();
  cur_node = find_at(*pos, g_list);
  cur_node->underline = 1;
  output_list();
}
