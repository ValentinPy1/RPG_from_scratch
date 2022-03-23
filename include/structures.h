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

typedef struct hitbox_data_s {
    int height;
    int width;
    double rotation;
    sfVector2f position;
    sfVector2f center;
    sfVector2f scale;
} hitbox_data_t;

typedef struct hitbox_s {
    int height;
    int width;
    double rotation;
    sfVector2f position;
    sfVector2f center;
    int is_hovered;
    sfVector2i **vertices;
    sfRectangleShape *rectangle;
} hitbox_t;

typedef struct scene_s;

typedef struct button_s {
    int height;
    int width;
    int posx;
    int posy;
    sfVector2f position;
    sfVector2f center;
    sfVector2f scale;
    double rotation;
    hitbox_t *hitbox;
    sfTexture *texture;
    sfTexture *ho_texture;
    sfTexture *sel_texture;
    sfSprite *sprite;
    sfSprite *ho_sprite;
    sfSprite *sel_sprite;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    int is_selected;
    void (*callback)(struct button_s *button,
                        struct scene_s **scene_list, int index);
} button_t;

typedef struct entity_s {
    int height;
    int width;
    int posx;
    int posy;
    sfVector2i center;
    sfVector2f scale;
    double rotation;
    sfVector2i **vertices;
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

#endif /*STRUCT_H_*/
