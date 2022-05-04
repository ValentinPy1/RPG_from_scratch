/*
** EPITECH PROJECT, 2022
** build_scene_texts
** File description:
** Header
*/

#ifndef BUILD_SCENE_TEXTS_H_
    #define BUILD_SCENE_TEXTS_H_
    #include "stddef.h"
    #include "structures.h"

static char *text_set[] =  {
    "name",
    "posx",
    "posy",
    "text",
    "font",
    "size",
    "rotation",
    "style",
    "color",
    "outline_color",
    "outline_tickness",
    "letter_spacing",
    "line_spacing",
    NULL
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
#endif /* !BUILD_SCENE_TEXTS_H_ */
