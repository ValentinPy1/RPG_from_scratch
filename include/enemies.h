/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enemies.h
*/

#ifndef ENEMIES_H_
    #define ENEMIES_H_
    #include "structures.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

static const int AGGRO_DIST = 150;

enemies_t *setup_enemies_nodes(sfVector2f pos);
void add_enem(enemies_t *enemies, sfVector2f pos);
void draw_enemies(sfRenderWindow *win, enemies_t *enemies);
float normalize(float dist, float max_speed);
void destroy_next_enemies(enemies_t *node);
int enem_count(enemies_t *node);
sfVector2f get_direction(sfVector2f p1, sfVector2f p2);
float get_distance(sfVector2f p1, sfVector2f p2);
void setup_values_enem(enem_t *enem);
sfIntRect *set_enemy_rect(void);
void move_rect(sfIntRect *rect, int offset, int max_value);
sfTexture *random_enemy_texture(void);
int my_strcmp(char *str1, char *str2);
void update_groups(data_t *gd, partic_ll_t *groups);

#endif
