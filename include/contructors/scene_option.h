/*
** EPITECH PROJECT, 2022
** scene_option
** File description:
** Header
*/

#ifndef SOURCE_OPTION_H_
    #define SOURCE_OPTION_H_
    #include "stddef.h"
    #include <stdlib.h>

typedef struct game_func_s {
    char *name;
    int (*func)(char **content, int *line);
} game_func_t;

int build_scene_name(char **content, int *line);
int build_scene_background(char **content, int *line);
int build_scene_buttons(char **content, int *line);
int build_scene_entities(char **content, int *line);
int build_scene_texts(char **content, int *line);
int build_scene_images(char **content, int *line);
int build_scene_sounds(char **content, int *line);

static const game_func_t TAB_SOPT[] = {
    {"scene_name", build_scene_name},
    {"background", build_scene_background},
    {"buttons", build_scene_buttons},
    {"entities", build_scene_entities},
    {"texts", build_scene_texts},
    {"images", build_scene_images},
    {"sound", build_scene_sounds},
    {NULL, NULL}
};

int my_strcmp(char *str1, char *str2);
#endif /* !SOURCE_OPTION_H_ */
