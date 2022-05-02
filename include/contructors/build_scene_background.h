/*
** EPITECH PROJECT, 2022
** build_scene_background
** File description:
** Header
*/

#ifndef BUILD_SCENE_BACKGROUND_H_
    #define BUILD_SCENE_BACKGROUND_H_
    #include "stddef.h"

static char *background_set[] = {
    "type",
    "path",
    NULL
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
#endif /* !BUILD_SCENE_BACKGROUND_H_ */
