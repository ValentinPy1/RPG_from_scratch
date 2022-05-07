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

static const int WIN_WIDTH = 1920;
static const int WIN_HEIGHT = 1080;
static const int WIN_DIAG = 2203;
static const int MSEC = 1000000;

typedef struct data_s data_t;

typedef struct particle_param_s {
    sfVector2f pos;
    sfVector2f spawn_radius;
    sfVector2f init_vel;
    sfVector2f rdm_vel;
    sfColor color;
    int max_duration;
    float size;
    sfVector2f gravity;
    sfVector2f resistance;
    int count;
} particle_param_t;

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    float duration;
    sfVector2f grav;
    sfVector2f res;
    sfCircleShape *circle;
} particle_t;

typedef struct partic_arr_s {
    particle_t *particles;
    int count;
    int duration;
} partic_arr_t;

typedef struct partic_ll_s {
    partic_arr_t *partic_arr;
    struct partic_ll_s *next;
} partic_ll_t;

typedef struct enem_s {
    float speed;
    float direction;
    float damage;
    sfVector2f pos;
    float life;
    sfSprite *sprite;
    sfIntRect *rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    float kb_speed;
    float kb_dir;
    sfVector2f destination;
} enem_t;

typedef struct enemies_s {
    enem_t *enem;
    struct enemies_s *next;
} enemies_t;

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

typedef struct text_s {
    struct text_s *next;
    sfText *text;
    char *name;
    sfVector2f position;
    char *str;
    sfFont *font;
    int size;
    sfTextStyle style;
    float rotation;
    sfColor color;
    sfColor outline_color;
    float outline_thickness;
    float line_spacing;
    float letter_spacing;
} text_t;

typedef struct image_s {
    struct image_s *next;
    char *name;
    sfVector2f position;
    int width;
    int height;
    sfVector2f scale;
    float rotation;
    sfSprite *sprite;
    sfTexture *texture;
} image_t;

typedef struct button_s {
    struct button_s *next;
    char *name;
    sfVector2f position;
    int width;
    int height;
    sfVector2f scale;
    float rotation;
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *ho_sprite;
    sfTexture *ho_texture;
    sfSound *clic_sound;
    sfSoundBuffer *sound_buffer;
    hitbox_t *hitbox;
    int is_hovered;
    int (*callback)(data_t *game_data, char **scenes_name, int *index_run);
} button_t;

typedef struct entity_s {
    struct entity_s *next;
    char *name;
    sfVector2f position;
    int width;
    int height;
    sfVector2f scale;
    float rotation;
    sfSprite *sprite;
    sfTexture *texture;
    sfSound *action_sound;
    sfSoundBuffer *sound_buffer;
    char *dialogue;
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
    map_t *map;
    sfSprite *background_sprite;
    sfTexture *background_texture;
    partic_ll_t *partic;
} scene_t;

typedef struct set_s {
    int window_x;
    int window_y;
} set_t;

typedef struct stats_s {
    int att;
    int def;
    int spd;
} stats_t;

typedef struct player_s {
    stats_t *stats;
    sfVector2f pos;
    sfSprite *player_sprite;
    sfIntRect *player_rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfSprite *attack_sprite;
    sfIntRect *attack_rect;
    sfClock *attack_clock;
    sfTime attack_time;
    float attack_seconds;
    int attack_state;
    int facing;
    sfView *view;
    float kb_dir;
    float kb_speed;
    float percentage;
    sfSound *kill;
    sfSoundBuffer *kill_buffer;
} player_t;

typedef struct key_s {
    int up;
    int right;
    int down;
    int left;
} keys_t;

struct data_s {
    set_t *settings;
    int run_index;
    int debug_mode;
    player_t *red;
    scene_t **scene_list;
    char **scene_names;
    keys_t *keys;
    unsigned int framerate;
    sfRenderWindow *window;
    enemies_t *enemies;
    unsigned long long int frame_count;
};

#endif /*STRUCT_H_*/
