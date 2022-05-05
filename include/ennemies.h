/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ennemies.h
*/

#ifndef __ENNEMIES__
    #define __ENNEMIES__

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

    #define AGGRO_DIST 150

typedef struct ennem_s {
    float speed;
    float direction;
    float damage;
    sfVector2f pos;
    float life;
    sfCircleShape *circle;
    float kb_speed;
    float kb_dir;
    sfVector2f destination;
} ennem_t;

typedef struct ennemies_s {
    ennem_t ennem;
    struct ennemies_s *next;
} ennemies_t;

ennemies_t *setup_ennemies_nodes(sfVector2f pos);
void add_ennem(ennemies_t *ennemies, sfVector2f pos);
void draw_ennemies(sfRenderWindow *win, ennemies_t *ennemies);
float normalize(float dist, float max_speed);
void destroy_next_ennemies(ennemies_t *node);
int ennem_count(ennemies_t *node);
sfVector2f get_direction(sfVector2f p1, sfVector2f p2);
float get_distance(sfVector2f p1, sfVector2f p2);

#endif