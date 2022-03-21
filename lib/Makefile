##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile to compile the lib
##

SRC =	fonctions/my_putchar.c

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
