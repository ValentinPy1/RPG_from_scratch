/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enemies.h
*/

#ifndef __enemIES__
    #define __enemIES__

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

    #define AGGRO_DIST 150

typedef struct enem_s {
    float speed;
    float direction;
    float damage;
    sfVector2f pos;
    float life;
    sfCircleShape *circle;
    float kb_speed;
    float kb_dir;
    sfVector2f destination;
} enem_t;

typedef struct enemies_s {
    enem_t enem;
    struct enemies_s *next;
} enemies_t;

enemies_t *setup_enemies_nodes(sfVector2f pos);
void add_enem(enemies_t *enemies, sfVector2f pos);
void draw_enemies(sfRenderWindow *win, enemies_t *enemies);
float normalize(float dist, float max_speed);
void destroy_next_enemies(enemies_t *node);
int enem_count(enemies_t *node);
sfVector2f get_direction(sfVector2f p1, sfVector2f p2);
float get_distance(sfVector2f p1, sfVector2f p2);

#endif