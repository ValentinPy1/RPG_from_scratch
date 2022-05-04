##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

CON_PATH = src/config_management/constructors/

SRC = 	src/main.c																	\
		src/init_game.c																\
		src/free_data.c																\
		src/config_management/get_config_files.c									\
		src/config_management/get_content_file.c									\
		src/config_management/constructors/new_construct/build_scene.c				\
		src/config_management/constructors/new_construct/scene_option.c				\
		src/config_management/constructors/new_construct/build_scene_name.c 		\
		src/config_management/constructors/new_construct/build_scene_background.c 	\
		src/config_management/constructors/new_construct/build_scene_buttons.c		\
		src/config_management/constructors/new_construct/build_scene_entities.c		\
		src/config_management/constructors/new_construct/build_scene_sounds.c		\
		src/config_management/constructors/new_construct/build_scene_texts.c		\
		src/config_management/constructors/new_construct/built_scene_images.c		\
		src/config_management/constructors/new_construct/construct_tools.c			\

NAME = my_rpg

OBJ = $(SRC:.c=.o)

LDFLAGS = -L lib/ -lmy -lcsfml-graphics -lcsfml-system \
			-lcsfml-window -lcsfml-audio -lm

CPPFLAGS = -I./include -I./include/contructors

CFLAGS = -Wall -Wextra -g3

all: built $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -C lib/ clean

fclean: clean
	rm -f $(NAME)
	make -C lib/ fclean

re: fclean all

built:
	make -C lib/

.PHONY: all clean fclean re built tests_run
