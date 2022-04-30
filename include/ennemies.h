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

typedef struct ennem_s {
    sfVector2f speed;
    float damage;
    sfVector2f pos;
    float life;
    sfCircleShape *circle;
} ennem_t;

typedef struct ennemies_s {
    ennem_t ennem;
    struct ennemies_s *next;
} ennemies_t;

ennemies_t *setup_ennemies_nodes(sfVector2f pos);
void add_ennem(ennemies_t *ennemies, sfVector2f pos);
void draw_ennemies(sfRenderWindow *win, ennemies_t *ennemies);

#endif