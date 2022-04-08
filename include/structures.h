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

typedef struct coord_s {
    double x;
    double y;
} coord_t;

typedef struct vector_s {
    double x;
    double y;
} vector_t;

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
    sfVector2f position;
    double rotation;
    sfVector2f scale;
    hitbox_t *hitbox;
    sfTexture *texture;
    sfTexture *ho_texture;
    sfSprite *sprite;
    sfSprite *ho_sprite;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    int is_selected;
    int (*callback)(struct button_s *button, char **scenes_name, int *index_run);
} button_t;

typedef struct entity_s {
    sfVector2f position;
    double rotation;
    sfVector2f scale;
    hitbox_t *hitbox;
    sfTexture *texture;
    sfSprite *sprite;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    char **dialogue;
} entity_t;

typedef struct scene_s {
    char *name;
    button_t **buttons;
    entity_t **entities;
    sfText **texts;
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfVector2i mouse_loc;
    int is_running;
} scene_t;

typedef struct data_s {
    int run_index;
    int debug_mode;
    scene_t **scene_list;
    char **scene_names;
} data_t;


#endif /*STRUCT_H_*/
