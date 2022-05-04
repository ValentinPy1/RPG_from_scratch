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

static char *image_set[] = {
    "name",
    "posx",
    "posy",
    "width",
    "height",
    "scale",
    "rotation",
    "texture",
    NULL
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
#endif /* !BUILD_SCENE_IMAGES_H_ */
