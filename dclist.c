/*
** dclist.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 17:34:53 2008 christophe sundas
** Last update Thu Dec  4 17:38:02 2008 christophe sundas
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_select.h"

t_dnode *mk_node()
{
  t_dnode	*new_node;

  if ((new_node = (t_dnode *) malloc(sizeof(t_dnode))) == NULL)
    exit(-1);
  return (new_node);
}

t_dclist	mk_dclist()
{
  t_dclist	list;

  if ((list.first = (t_dnode *) malloc(sizeof(t_dnode))) == NULL)
    exit(-1);
  if (list.first != NULL)
    list.first->next = list.first->prev = list.first;
  list.last = list.cur = list.first;
  return (list);
}

void	my_put_in_dclist(t_dclist *list, t_dnode *node)
{
  node->prev = list->first->prev;
  node->next = list->first;
  list->first->prev = node;
  if (is_empty(*list))
    {
      list->first->next = node;
    }
  list->first = node;
}

void	delete_dcnode(t_dclist *list, t_dnode *node)
{
  (node->prev)->next = node->next;
  (node->next)->prev = node->prev;
  if (node == list->first)
    list->first = node->next;
  free(node);
}

void	my_free_dclist(t_dclist *list)
{
  list->cur = list->first;
  while (list->cur != list->last)
    {
      free(list->cur->data);
      list->cur = list->cur->next;
      free(list->cur->prev);
    }
}
