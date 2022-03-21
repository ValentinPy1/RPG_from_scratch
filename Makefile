##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

SRC = 	src/main.c

NAME = my_rpg

OBJ = $(SRC:.c=.o)

LDFLAGS = -L lib/ -lmy -lcsfml-graphics -lcsfml-system \
			-lcsfml-window -lcsfml-audio

CPPFLAGS = -I./include

CFLAGS = -Wall -Wextra

all: built $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)
	make clean

clean:
	rm -f $(OBJ)
	rm -f vgcore*
	rm -f *.gcda
	rm -f *.gcno
	rm -f src/*.gcda
	rm -f src/*.gcno
	make -C lib/ clean
	make -C tests/ clean

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean
	make -C tests/ fclean

re: fclean all

built:
	make -C lib/
	make -C lib/ clean

tests_run: built
	make -C tests/ tests_run
	make -C tests/ clean

.PHONY: all clean fclean re built tests_run
