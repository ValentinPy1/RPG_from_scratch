/*
** EPITECH PROJECT, 2022
** build_scene_images
** File description:
** Header
*/

#ifndef BUILD_SCENE_IMAGES_H_
    #define BUILD_SCENE_IMAGES_H_
    #include "stddef.h"
    #include "structures.h"

typedef struct img_opt_s {
    char *name;
    int (*func)(entity_t *entity, char *value);
} img_opt_t;

int build_img_name(entity_t *entity, char *value);
int build_img_posx(entity_t *entity, char *value);
int build_img_posy(entity_t *entity, char *value);
int build_img_width(entity_t *entity, char *value);
int build_img_height(entity_t *entity, char *value);
int build_img_scale(entity_t *entity, char *value);
int build_img_rotation(entity_t *entity, char *value);
int build_img_texture(entity_t *entity, char *value);

static img_opt_t IMG_OPT_TAB[] = {
    {"name", build_img_name},
    {"posx", build_img_posx},
    {"posy", build_img_posy},
    {"width", build_img_width},
    {"height", build_img_height},
    {"scale", build_img_scale},
    {"rotation", build_img_rotation},
    {"texture", build_img_texture},
    {NULL, NULL}
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
#endif /* !BUILD_SCENE_IMAGES_H_ */
