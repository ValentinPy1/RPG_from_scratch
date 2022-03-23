##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

SRC = 	src/main.c														\
		src/config_management/get_config_files.c						\
		src/config_management/get_content_file.c						\
		src/config_management/get_value.c								\
		src/config_management/get_keyword.c								\
		src/config_management/constructors/my_parser.c					\
		src/config_management/constructors/error_handling.c				\
		src/config_management/constructors/construct_scenes.c			\
		

NAME = my_rpg

OBJ = $(SRC:.c=.o)

LDFLAGS = -L lib/ -lmy -lcsfml-graphics -lcsfml-system \
			-lcsfml-window -lcsfml-audio

CPPFLAGS = -I./include -I./include/contructors

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

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

built:
	make -C lib/
	make -C lib/ clean

.PHONY: all clean fclean re built tests_run
