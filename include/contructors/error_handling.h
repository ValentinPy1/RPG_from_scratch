/*
** EPITECH PROJECT, 2022
** error_handling
** File description:
** Header
*/

#ifndef ERR_H_
    #define ERR_H_
    #include <stddef.h>
    #include <stdlib.h>

static char *settings[3] = {
    "name",
    "game_object",
    NULL
};

static char *game_object_settings[4] = {
    "buttons",
    "background",
    "entities",
    NULL
};

static char *object_settings[15] = {
    "posx",
    "posy",
    "width",
    "height",
    "scale",
    "rotation",
    "shape",
    "texture",
    "ho_texture",
    "animation",
    "speed",
    "sound",
    "callback",
    NULL
};

int write_error(char const *str);

int my_strcmp(char *str1, char *str2);

char *get_keyword(char *str);
#endif /*ERR_H_*/
