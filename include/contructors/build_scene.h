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
    #include "structures.h"

static char *scene_name_set[] = {"name", NULL};

static char *sound_set[] = {
    "name",
    "path",
    "volume",
    "pitch",
    "looping",
    NULL
};

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

static char *button_set[] = {
    "name",
    "posx",
    "posy",
    "width",
    "height",
    "scale",
    "rotation",
    "texture",
    "ho_texture",
    "sound",
    "callback",
    NULL    
};

static char *entitie_set[] = {
    "name",
    "posx",
    "posy",
    "width",
    "height",
    "scale",
    "rotation",
    "hostile"
    "texture",
    "hit_texture",
    "death_texture",
    "hit_sound",
    "death_sound",
    "dialogue",
    NULL
};

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


int write_error(char const *str);

int my_strcmp(char *str1, char *str2);

char *get_keyword(char *str);

void my_printf(char *str, ...);
int find_scene_opt(char *id, char **content, int *line);
char *is_a_scene_opt(char **content, int *line);
#endif /*ERR_H_*/
