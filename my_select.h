
/*
** my_select.h for my_select in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Dec  4 21:21:03 2008 christophe sundas
** Last update Thu Dec  4 22:12:10 2008 christophe sundas
*/

#ifndef __H_MY_SELECT__
# define __H_MY_SELECT__

#define BUFSIZE 10
#define MSG_USAGE "usage my_select [args...]"
#define RETSIGTYPE void


typedef struct		s_dnode
{
  char			*data;
  int			selected;
  int			underline;
  struct s_dnode	*next;
  struct s_dnode	*prev;

}			t_dnode;

typedef struct	s_dclist
{
  t_dnode	*first;
  t_dnode	*last;
  t_dnode	*cur;
}		t_dclist;


extern t_dclist	g_list;

/*
** my_select norme ok
*/
void		my_select();
void		my_exit();
void		my_exit2();
int		get_label_len(char *str);
/*
** getcap.c norme ok
*/
char		*xtgetstr(char *cap, char **area);
void		my_setkey();
void		set_invisible_curs();
void		set_visible_curs();
void		set_upleft_curs();

/*
** getkey nomre ok
*/
void		my_getkey();
void		init_buffer(char buffer[]);
int		redirect(char buffer[BUFSIZE]);
void		select_line(int *pos);
void		delete_ligne(int *pos);

/*
** getkey2 suite norme ok
*/
void		send_to_shell();

/*
** liste doublement chainee 1 norme ok
*/
t_dclist	mk_dclist();
void		my_put_in_dclist(t_dclist *list, t_dnode *node);
t_dnode		*mk_node();
void		my_free_dclist(t_dclist *list);
void		delete_dcnode(t_dclist *list, t_dnode *node);

/*
**liste doublementy chainee 2 nrome ok
*/
int		find_pos(t_dclist list, t_dnode *node);
t_dnode		*find_at(int pos, t_dclist list);
void		display_dclist(t_dclist list);
int		is_empty(t_dclist list);
int		my_dclist_size(t_dclist list);

/*
** output.h norme ok
*/
void		output_list();
void		output_node(t_dnode *node);
void		my_putstr2(char *str);
void		my_putchar2(char c);
int		my_outc(int c);

/*
** Video mode :norme ok
*/
void		rev_underline(char *str);
void		video_inv(char *str);
void		underline(char *str);
void		set_color(int bgcolor, int fgcolor);

/*
** clearscreen.h norme ok
*/
void		clearscreen();
void		my_clearscreen();
char		*my_get_env(char *label);

/*
** redim.h nrome ok
*/
RETSIGTYPE	sigwinch();
int		check_limit_col(int *itab, int nbcol, int limit);
int		*mktabcol(int nbcol);
int		get_len_col(int nbcol);
int		get_nbcol(int list_size, int size_term);

/*
** redim2.h norme ok
*/
void		display_col(int lenword, int max);
void		display_node(int *i, int nbcol, int *itab);

/*
** Mov curs norme ok
*/
void		my_up_curs(int *pos);
void		my_down_curs(int *pos);
void		my_refresh_curs(int *pos);

#endif
