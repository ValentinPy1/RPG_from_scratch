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

typedef struct hitbox_s {
    sfVector2f position;
    sfVector2f center;
    int height;
    int width;
    double rotation;
    int is_hovered;
    sfVector2i **vertices;
    sfRectangleShape *rectangle;
} hitbox_t;

typedef struct button_s {
    sfVector2f position;
    sfVector2f center;
    double rotation;
    sfVector2f scale;
    hitbox_t *hitbox;
    sfTexture *texture;
    sfTexture *ho_texture;
    sfSprite *sprite;
    sfSprite *ho_sprite;
    sfSprite *sel_sprite;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    int is_selected;
    int (*callback)(struct button_s *button, char **scenes_name, int *index_run);
} button_t;

typedef struct entity_s {
    int posx;
    int posy;
    sfVector2i center;
    double rotation;
    sfVector2f scale;
    hitbox_t *hitbox;
    sfTexture *texture;
    sfSprite *sprite;
    sfSound *sound;
} entity_t;

typedef struct scene_s {
    char *name;
    button_t **buttons;
    entity_t **entities;
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfVector2i mouse_loc;
    int is_running;
} scene_t;

typedef struct data_s {
    int run_index;
    scene_t **scene_list;
    char **scene_names;
} data_t;


#endif /*STRUCT_H_*/
