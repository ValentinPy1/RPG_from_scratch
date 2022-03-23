##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile to compile the lib
##

SRC =	fonctions/count_char.c		\
		fonctions/get_content.c 	\
		fonctions/my_split.c	 	\
		fonctions/my_strlen.c 	 	\
		fonctions/my_strncpy.c	 	\
		fonctions/next_char.c		\
		fonctions/my_strconc.c		\
		fonctions/write_error.c		\
		fonctions/add_char.c		\
		fonctions/my_realloc.c		\
		fonctions/my_strcmp.c		\
		fonctions/my_getnbr.c
		

NAME =	libmy.a

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
