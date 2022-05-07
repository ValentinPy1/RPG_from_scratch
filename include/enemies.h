/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enemies.h
*/

#ifndef __ENEMIES__
    #define __ENEMIES__

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include "structures.h"
    #define AGGRO_DIST 150
    #define ENEM_ATTACK_DELAY 1
    #define ENEM_ATTACK_DIST 30
    #define ENEM_COLLIDE_DIST 25
    #define ENEM_DMG 10

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

#endif
