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

static const sfVector2f OFFSET[4] =
{{-16, 0}, {-32, -32}, {0, -32}, {-16, -35}};

void display_map(sfRenderWindow *window, map_t *map_data);
void set_position(sfSprite *sprite, float x, float y);
void handle_particles(sfRenderWindow *win, data_t *game_data, scene_t *scene);
void update_enemies(data_t *gd, enemies_t *enemies);
void update_groups(data_t *gd, partic_ll_t *groups);
void update_stats(data_t *game_data);
char *my_getstr(int nb);
scene_t *get_scene(scene_t **scene_list, char *name);
text_t *get_text(text_t *texts, char *name);

#endif /*MDIS_H_*/