/*
** getkey.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 17:59:55 2008 christophe sundas
** Last update Thu Dec  4 20:59:20 2008 christophe sundas
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "my.h"
#include "my_select.h"
#include <ncurses.h>
#include <term.h>

t_dclist	g_list;

/*
** int ioctl(int d, unsigned long request, ...);
*/
void	my_getkey()
{
  int	nblu;
  char	buffer[BUFSIZE];
  int	pos;
  int	choix;
  
  pos = 0;
  while ((nblu = read(0, buffer, BUFSIZE)) != 0)
    {
      if (nblu == -1)
	exit(-1);
      if (is_empty(g_list))
	my_exit();
      choix = redirect(buffer);
      if (choix == 1)
	my_up_curs(&pos);
      if (choix == 2)
	my_down_curs(&pos);
      if (choix == 3)
	select_line(&pos);
      if (choix == 4)
	delete_ligne(&pos);
      if (choix == 5)
	send_to_shell();
      init_buffer(buffer);
    }
}

void	init_buffer(char buffer[])
{
  buffer[0] = 0;
  buffer[1] = 0;
  buffer[2] = 0;
}

/*
** supprime la ligne courante et opsitionne le curseur hmm ou?
*/
void	delete_ligne(int *pos)
{
  t_dnode	*cur_node;

  cur_node = find_at(*pos, g_list);
  delete_dcnode(&g_list, cur_node);
  if (my_dclist_size(g_list) == (*pos))
    *pos = 0;
  my_refresh_curs(pos);
}

/*
** selectionne un ligne en mode inverse puis move curs down
*/
void	select_line(int *pos)
{
  t_dnode	*cur_node;

  cur_node = find_at(*pos, g_list);
  cur_node->selected = (!cur_node->selected);
  my_down_curs(pos);
}

/*
** Keyup 27, 91, 65
** Keydown 27,91,66
** espace, selectionne ' '
** backspace 8
** delete 27, 91, 51
** enter \n
** escape 27,0
*/
int	redirect(char buffer[BUFSIZE])
{
  if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
    return (1);
  if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
    return (2);
  if (buffer[0] == ' ')
    return (3);
  if (buffer[0] == 8)
    return (4);
  if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 51)
    return (4);
  if (buffer[0] == '\n')
    return (5);
  if ((buffer[0] == 27) && (buffer[1] == 0))
    my_exit();
  return (0);
}
