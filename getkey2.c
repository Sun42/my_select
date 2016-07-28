/*
** getkey2.c for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 18:15:31 2008 christophe sundas
** Last update Thu Dec  4 21:21:41 2008 christophe sundas
*/

#include "my.h"
#include "my_select.h"

/*
** envoi la reponse au shell
*/
void	send_to_shell()
{
  int	flag;

  flag = 0;
  my_clearscreen();
  g_list.cur = g_list.first;
  while (g_list.cur != g_list.last)
    {
      if (g_list.cur->selected == 1)
        {
          if (flag == 1)
            my_putchar(' ');
          my_putstr(g_list.cur->data);
          flag = 1;
        }
      g_list.cur = g_list.cur->next;
    }
  my_exit2();
}
