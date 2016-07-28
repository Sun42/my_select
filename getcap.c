/*
** getcap.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 18:23:03 2008 christophe sundas
** Last update Thu Dec  4 22:59:08 2008 christophe sundas
*/

#include <errno.h>
#include "my.h"
#include "my_select.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include <term.h>
#ifndef HAVE_NOT_TERMCAP_H
#include <termcap.h>
#else
char	*tgetstr();
#endif

char	*xtgetstr(char *cap, char **area)
{
  char	*capstr;

  if ((capstr = tgetstr(cap, area)) == NULL)
    {
      my_putstr_error("problem getting ");
      my_putstr_error(cap);
      my_putstr_error("\n");
      exit(-1);
    }
  return (capstr);
}

void			my_setkey()
{
  struct termios	t;
  
  if (ioctl(0, TIOCGETA, &t) == -1)
    my_put_nbr_error(errno);
  t.c_lflag &= ~(ICANON | ECHO);
  t.c_cc[VQUIT] = 'q';
  t.c_cc[VMIN] = 1;
  if (ioctl(0, TIOCSETA, &t) == -1)
    my_put_nbr_error(errno);
}

void	set_invisible_curs()
{
  char	t[4096];
  char	*area;
  char	*invisible_curs;

  area = t;
  invisible_curs = xtgetstr("vi", &area);
  if (tputs(invisible_curs, 1, my_outc) == ERR)
    exit(-1);
}

void	set_visible_curs()
{
  char	t[4096];
  char	*area;
  char	*visible_curs;

  area = t;
  visible_curs = xtgetstr("ve", &area);
  if (tputs(visible_curs, 1, my_outc) == ERR)
    exit(-1);
 }

void	set_upleft_curs()
{
  char	t[4096];
  char	*area;
  char	*upleft;

  area = t;
  upleft = xtgetstr("ho", &area);
  if (tputs(upleft, 1, my_outc) == ERR)
    exit(-1);
 }
