##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile code source
##

CON_PATH = src/config_management/constructors/

SRC = 	src/main.c													\
		src/free_data.c 											\
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
		$(CON_PATH)my_parser.c										\
		$(CON_PATH)error_handling.c									\
		$(CON_PATH)construct_scenes.c								\
		$(CON_PATH)construct_map/map_parser.c						\
		$(CON_PATH)construct_map/tools_parser.c						\
		$(CON_PATH)construct_hitbox/init_hitbox.c					\
		$(CON_PATH)construct_hitbox/load_vertices.c					\
		$(CON_PATH)construct_texts/parse_text.c						\
		$(CON_PATH)construct_texts/construct_text1.c				\
		$(CON_PATH)construct_texts/construct_text2.c				\
		$(CON_PATH)construct_texts/construct_text3.c				\
		$(CON_PATH)construct_sounds/parse_sound.c					\
		$(CON_PATH)construct_sounds/construct_sound.c				\
		$(CON_PATH)construct_images/parse_images.c					\
		$(CON_PATH)construct_images/construct_image1.c				\
		$(CON_PATH)construct_images/construct_image2.c				\
		$(CON_PATH)construct_buttons/parse_buttons.c 				\
		$(CON_PATH)construct_buttons/construct_button1.c 			\
		$(CON_PATH)construct_buttons/construct_button2.c 			\
		$(CON_PATH)construct_buttons/construct_button3.c 			\
		$(CON_PATH)construct_entities/parse_entities.c				\
		$(CON_PATH)construct_entities/construct_entities1.c			\
		$(CON_PATH)construct_entities/construct_entities2.c			\
		$(CON_PATH)construct_background/parse_background.c			\
		$(CON_PATH)construct_background/construct_background.c		\
		src/random/random_generator.c								\
		src/particles/setup.c										\
		src/particles/update.c										\
		src/particles/draw.c										\
		src/particles/destroy.c										\
		src/particles/manage_partic_ll.c							\
		src/particles/type.c										\
		src/constructor/player_constructor.c 						\
		src/movement_management/movement.c 							\
		src/movement_management/view.c								\
		src/movement_management/animations.c						\

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
