##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

CON_PATH = src/config_management/constructors/

SRC = 	src/main.c																					\
		src/init_game.c																				\
		src/free_data.c																				\
		src/config_management/get_names_scene.c														\
		src/config_management/get_config_files.c													\
		src/config_management/get_content_file.c													\
		src/config_management/constructors/construct_map/map_parser.c								\
		src/config_management/constructors/new_construct/build_background/build_scene_background.c	\
		src/config_management/constructors/new_construct/build_background/back_opt.c				\
		src/config_management/constructors/new_construct/build_name/build_scene_name.c 				\
		src/config_management/constructors/new_construct/build_name/name_opt.c						\
		src/config_management/constructors/new_construct/build_button/build_scene_buttons.c			\
		src/config_management/constructors/new_construct/build_button/button_opt.c					\
		src/config_management/constructors/new_construct/build_button/button_opt2.c					\
		src/config_management/constructors/new_construct/build_button/button_opt3.c					\
		src/config_management/constructors/new_construct/build_entity/build_scene_entities.c		\
		src/config_management/constructors/new_construct/build_entity/entity_opt.c					\
		src/config_management/constructors/new_construct/build_entity/entity_opt2.c					\
		src/config_management/constructors/new_construct/build_sound/build_scene_sounds.c			\
		src/config_management/constructors/new_construct/build_sound/sound_opt.c					\
		src/config_management/constructors/new_construct/build_text/build_scene_texts.c				\
		src/config_management/constructors/new_construct/build_text/text_opt.c						\
		src/config_management/constructors/new_construct/build_text/text_opt2.c						\
		src/config_management/constructors/new_construct/build_text/text_opt3.c						\
		src/config_management/constructors/new_construct/build_image/built_scene_images.c			\
		src/config_management/constructors/new_construct/build_image/image_opt.c					\
		src/config_management/constructors/new_construct/build_image/image_opt2.c					\
		src/config_management/constructors/new_construct/build_scene.c								\
		src/config_management/constructors/new_construct/scene_option.c								\
		src/config_management/constructors/new_construct/construct_tools.c							\
		src/config_management/callbacks/button_callback1.c											\

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
