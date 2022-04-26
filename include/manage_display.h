/*
** EPITECH PROJECT, 2022
** manage_display
** File description:
** Header
*/

#ifndef MDIS_H_
    #define MDIS_H_
    #include <stddef.h>
    #include "structures.h"

void display_map(sfRenderWindow *window, map_t *map_data);
void set_position(sfSprite *sprite, float x, float y);
void handle_particles(sfRenderWindow *win, data_t *game_data, scene_t *scene);

#endif /*MDIS_H_*/
