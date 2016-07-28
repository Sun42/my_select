/*
** video_mode.c for my_select	 in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 17:26:58 2008 christophe sundas
** Last update Thu Dec  4 23:07:30 2008 christophe sundas
*/

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

void	video_inv(char *str)
{
  char	*sostr;
  char	*sestr;
  char	t[4096];
  char	*area;

  area = t;
  sostr = xtgetstr("so", &area);
  if (tputs(sostr, 1, my_outc) == ERR)
    exit(-1);
  my_putstr2(str);
  sestr = xtgetstr("se", &area);
  if (tputs(sestr, 1, my_outc) == ERR)
    exit(-1);
}

void	underline(char *str)
{
  char	*usstr;
  char	*uestr;
  char	t[4096];
  char	*area;

  area = t;
  usstr = xtgetstr("us", &area);
  if (tputs(usstr, 1, my_outc) == ERR)
    exit(-1);
  my_putstr2(str);
  uestr = xtgetstr("ue", &area);
  if (tputs(uestr, 1, my_outc) == ERR)
    exit(-1);
}

void	rev_underline(char *str)
{
  char	*sostr;
  char	*sestr;
  char	*usstr;
  char	*uestr;
  char	t[4096];
  char	*area;
  
  area = t;
  sostr = xtgetstr("so", &area);
  if (tputs(sostr, 1, my_outc) ==  ERR)
    exit(-1);
  usstr = xtgetstr("us", &area);
  if (tputs(usstr, 1, my_outc) ==  ERR)
    exit(-1);
  my_putstr2(str);
  uestr = xtgetstr("ue", &area);
  if (tputs(uestr, 1, my_outc) == ERR)
    exit(-1);
  sestr = xtgetstr("se", &area);
  if (tputs(sestr, 1, my_outc) == ERR)
    exit(-1);
}

void	set_color(int bgcolor, int fgcolor)
{
  char	*afstr;
  char	*abstr;
  char	t[4096];
  char	*area;
  char	*term;
  char	bp[1024];
  
  if ((term = my_get_env("TERM")) == NULL)
    {
      my_putstr_error("can't determine terminal\n");
      exit(-1);
    }
  if (tgetent(bp, term) != 1)
    {
      my_putstr_error("problem with tgetent\n");
      exit(-1);
    }
  area = t;
  afstr = xtgetstr("AF", &area);
  abstr = xtgetstr("AB", &area);
  if (tputs(tparm(afstr, fgcolor), 1, my_outc) == ERR)
    exit(-1);
  if (bgcolor != 0)
    if (tputs(tparm(abstr, bgcolor), 1, my_outc) ==  ERR)
      exit(-1);
}
