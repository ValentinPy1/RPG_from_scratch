/*
** EPITECH PROJECT, 2022
** structures
** File description:
** Header
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "particles.h"

typedef struct coord_s {
    double x;
    double y;
} coord_t;

typedef struct vector_s {
    double x;
    double y;
} vector_t;

typedef struct text_s {
    struct text_s *next;
    char *name;
    int posx;
    int posy;
} text_t;

typedef struct image_s {
    struct image_s *next;
    char *name;
    int posx;
    int posy;
    int width;
    int height;
} image_t;

typedef struct hitbox_s {
    sfVector2f position;
    double height;
    double width;
    double rotation;
    int is_hovered;
    sfVector2f **vertices;
    sfRectangleShape *rectangle;
    sfCircleShape **circle;
} hitbox_t;

typedef struct button_s {
    struct button_s *next;
    char *name;
    int posx;
    int posy;
    int width;
    int height;
} button_t;

typedef struct entity_s {
    struct entity_s *next;
    char *name;
    int posx;
    int posy;
    int width;
    int weight;
} entity_t;

typedef struct map_s {
    int **tiles;
    sfSprite *tiles_sprite;
    int size_x;
    int size_y;
} map_t;

typedef struct scene_s {
    char *name;
    button_t *buttons;
    entity_t *entities;
    image_t *images;
    text_t *texts;
    sfSound *music;
    sfSoundBuffer *music_buffer;
} scene_t;

typedef struct set_s {
    int window_x;
    int window_y;
} set_t;

typedef struct player_s {
    sfVector2f pos;
    sfSprite *player_sprite;
    sfIntRect *player_rect;
    sfView *view;
    sfClock *clock;
    sfTime time;
    float seconds;
} player_t;

typedef struct data_s {
    set_t *settings;
    int run_index;
    int debug_mode;
    player_t *red;
    scene_t **scene_list;
    char **scene_names;
    partic_ll_t *partic;
} data_t;

#endif /*STRUCT_H_*/
