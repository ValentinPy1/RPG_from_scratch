##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

CON_PATH = src/config_management/constructors/

SRC = 	src/main.c													\
		src/free/free_data.c 										\
		src/free/free_obj.c 										\
		src/collision_algorithm/point_in_rect.c						\
		src/window_management/open_window.c							\
		src/window_management/manage_display.c 						\
		src/window_management/manage_events.c						\
		src/window_management/manage_buttons.c						\
		src/collision_management/map_collision.c					\
		src/window_management/get_run_index.c 						\
		src/config_management/get_value.c							\
		src/config_management/get_keyword.c							\
		src/config_management/get_names_scene.c 					\
		src/config_management/get_config_files.c					\
		src/config_management/get_content_file.c					\
		src/config_management/callbacks/button_callback1.c			\
		src/config_management/callbacks/button_callback2.c			\
		src/config_management/callbacks/button_callback3.c			\
		$(CON_PATH)build_scene.c									\
		$(CON_PATH)construct_tools.c								\
		$(CON_PATH)scene_option.c									\
		$(CON_PATH)build_background/build_scene_background.c		\
		$(CON_PATH)build_background/back_opt.c						\
		$(CON_PATH)build_name/build_scene_name.c 					\
		$(CON_PATH)build_name/name_opt.c							\
		$(CON_PATH)build_button/build_scene_buttons.c				\
		$(CON_PATH)build_button/button_opt.c						\
		$(CON_PATH)build_button/button_opt2.c						\
		$(CON_PATH)build_button/button_opt3.c						\
		$(CON_PATH)build_entity/build_scene_entities.c				\
		$(CON_PATH)build_entity/entity_opt.c						\
		$(CON_PATH)build_entity/entity_opt2.c						\
		$(CON_PATH)build_sound/build_scene_sounds.c					\
		$(CON_PATH)build_sound/sound_opt.c							\
		$(CON_PATH)build_text/build_scene_texts.c					\
		$(CON_PATH)build_text/text_opt.c							\
		$(CON_PATH)build_text/text_opt2.c							\
		$(CON_PATH)build_text/text_opt3.c							\
		$(CON_PATH)build_image/built_scene_images.c					\
		$(CON_PATH)build_image/image_opt.c							\
		$(CON_PATH)build_image/image_opt2.c							\
		src/random/random_generator.c								\
		src/particles/setup.c										\
		src/particles/update.c										\
		src/particles/draw.c										\
		src/particles/destroy.c										\
		src/particles/manage_particules.c							\
		src/particles/type.c										\
		src/constructor/player_constructor.c 						\
		src/movement_management/movement.c 							\
		src/movement_management/view.c								\
		src/movement_management/animations.c						\
		src/enemies/setup.c											\
		src/enemies/setup_tools.c									\
		src/enemies/draw.c											\
		src/enemies/update.c										\
		src/enemies/destroy.c										\
		src/enemies/ai.c											\
		src/enemies/tools.c											\

NAME = my_rpg

OBJ = $(SRC:.c=.o)

LDFLAGS = -L lib/ -lmy -lcsfml-graphics -lcsfml-system \
			-lcsfml-window -lcsfml-audio -lm

CPPFLAGS = -I./include -I./include/contructors

CFLAGS = -Wall -Wextra -g3

all: built $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

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
