/*
** clearscreen.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 17:33:27 2008 christophe sundas
** Last update Thu Dec  4 22:57:02 2008 christophe sundas
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
#include "my.h"
#include "my_select.h"

void	clearscreen()
{
  char	*term;
  char	bp[1024];
  char	*area;
  char	*clstr;
  char	t[4096];

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
  clstr = xtgetstr("cl", &area);
  if (tputs(clstr, 1, my_outc) == ERR)
    exit(-1);
}

void	my_clearscreen()
{
  char	*clstr;
  char	t[4096];
  char	*area;
  char	*term;
  char	bp[1024];

  if ((term = my_get_env("TERM")) == NULL)
    {
      my_putstr_error("can't determine terminal in myclear screen\n");
      exit(-1);
    }
  if (tgetent(bp, term) != 1)
    {
      my_putstr_error("problem with tgetent\n");
      exit(-1);
    }
  area = t;
  set_upleft_curs();
  clstr = xtgetstr("cd", &area);
  if (tputs(clstr, 1, my_outc) == ERR)
    exit(-1);
}

char	*my_get_env(char *label)
{
  extern char **environ;
  int	i;
  int	len;
  
  i = 0;
  while (environ[i])
    {
      len = get_label_len(environ[i]);
      if (my_strncmp(label, environ[i], len) == 0)
	return (environ[i] +  (my_strlen(label) + 1));
      i++;
    }
  return (NULL);
}

int	get_label_len(char *str)
{
  int	cpt;

  cpt = 0;
  while ((str[cpt] != '\0')  && (str[cpt] != '=')) 
    cpt++;
  return (cpt);
}

