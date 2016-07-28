/*
** output.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 18:27:58 2008 christophe sundas
** Last update Thu Dec  4 21:40:04 2008 christophe sundas
*/

#include "my.h"
#include "my_select.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <signal.h>
#ifndef HAVE_NOT_TERMCAP_H
#include <termcap.h>
#else
char	*tgetstr();
#endif
#include <ncurses.h>
#include <term.h>
#ifdef HAVE_TERMIOS_H
# include <termios.h>
#endif
#include <sys/termios.h>

t_dclist		g_list;

void			output_list()
{
  struct winsize	w;
  int			*itab;
  int			nbcol;
  int			i;
  
  my_clearscreen();
  if (ioctl(0, TIOCGWINSZ, &w) < 0)
    my_exit();
  nbcol = get_nbcol(my_dclist_size(g_list), w.ws_row);
  i = 0;
  itab = mktabcol(nbcol);
  if (check_limit_col(itab, nbcol, w.ws_col) == 1)
    {
      g_list.cur = g_list.first;
      while (g_list.cur != g_list.last)
	{
	  i++;
	  display_node(&i, nbcol, itab);
	  g_list.cur = g_list.cur->next;
	}
    }
  free(itab);
}

void	output_node(t_dnode *node)
{
  if ((node->selected == 1) && (node->underline == 0))
    {
      video_inv(node->data);
    }
  if ((node->selected == 1) && (node->underline == 1))
    {
      rev_underline(node->data);
    }
  if ((node->selected == 0) && (node->underline == 1))
    {
      underline(node->data);
    }
  if ((node->selected == 0) && (node->underline == 0))
    my_putstr2(node->data);
}

void	my_putstr2(char *str)
{
  while (*str)
    {
      my_putchar2(*str);
      str++;
    }
}

void	my_putchar2(char c)
{
  write(0, &c, 1);
}

int	my_outc(int c)
{
  my_putchar2(c);
  return (0);
}
