/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** movement.h
*/

#ifndef _MOVEMENT_
    #define _MOVEMENT_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include "structures.h"

void set_position(sfSprite *sprite, float x, float y);
int is_blocking_tile(map_t *map, sfVector2f pos);
void init_view(sfRenderWindow *window, data_t *game_data);

void move_rect(sfIntRect *rect, int offset, int max_value);
void player_walk(data_t *game_data, sfIntRect *rect,
int offset, int max_value);

#endif
