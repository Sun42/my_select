##
## Makefile for my_sleect in /u/all/sundas_c/cu/rendu/unix/projet/my_select2
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Thu Dec  4 18:16:33 2008 christophe sundas
## Last update Thu Dec  4 21:54:35 2008 christophe sundas
##

CC = gcc 
NAME = my_select
SRC = 	my_select.c \
	output.c \
	clearscreen.c \
	getcap.c \
	getkey.c \
	getkey2.c \
	mov_curs.c \
	dclist.c \
	dclist2.c \
	video_mode.c \
	redim.c \
	redim2.c
OBJ = $(SRC:.c=.o)
TMP = $(OBJ:.o=.c~)
CFLAGS += -I. -ansi -pedantic -W -Wall
LIB = -L. -lmy_`uname -m`-`uname -s` -lncurses -ltermcap
RM = rm -f

$(NAME) : $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) $(LIB)

all : $(NAME)

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TMP)
	$(RM) $(NAME)

re: fclean all
