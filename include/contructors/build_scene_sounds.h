/*
** EPITECH PROJECT, 2022
** build_scene_sounds
** File description:
** Header
*/

#ifndef BUILD_SCENE_SOUNDS_H_
    #define BUILD_SCENE_SOUNDS_H_
    #include "stddef.h"
    #include "structures.h"

static char *sound_set[] = {
    "name",
    "path",
    "volume",
    "pitch",
    "looping",
    NULL
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
#endif /* !BUILD_SCENE_SOUNDS_H_ */
