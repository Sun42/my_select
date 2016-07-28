#include "my.h"
#include <ncurses.h>
#include <term.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <signal.h>
#ifndef HAVE_NOT_TERMCAP_H
#include <termcap.h>
#else
char	*tgetstr();
#endif
#include "my_select.h"

RETSIGTYPE	sigwinch()
{
  output_list();
}

int	check_limit_col(int *itab, int nbcol, int limit)
{
  int	i;
  int	total_col_len;

  i = 0;
  total_col_len = nbcol -1;
  while (i < nbcol)
    {
      total_col_len += itab[i];
      i++;
    }
  if (total_col_len > limit)
    {
      clearscreen();
      my_putstr_error("Veuillez redimensionner le terminal");
      return (0);
    }
  return (1);
}

int	get_nbcol(int list_size, int size_term)
{
  int	res;

  if (size_term >= list_size)
    res = 1;
  else
    {
      res = (list_size / size_term) + 1;
    }
  return (res);
}


int	*mktabcol(int nbcol)
{
  int	*itab;
  int	i;

  if ((itab = malloc(sizeof(*itab) * nbcol)) == NULL)
    exit(-1);
  i = 0;
  while (i < nbcol)
    {
      itab[i] = get_len_col(i + 1);
      i++;
    }
  return (itab);
}

int	get_len_col(int nbcol)
{
  int	i;
  int	max;
  int	len;

  max = 0;
  i = 0;
  g_list.cur = g_list.first;
  while (g_list.cur != g_list.last)
    {
      i++;
      if (i == nbcol)
        {
          len = my_strlen(g_list.cur->data);
          max = max > len ? max : len;
          i = 0;
        }
      g_list.cur = g_list.cur->next;
    }
  return (max);
}
