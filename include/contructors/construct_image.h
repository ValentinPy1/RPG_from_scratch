/*
** EPITECH PROJECT, 2022
** construct_images
** File description:
** Header
*/

#ifndef ENT_H_
    #define ENT_H_
    #include "structures.h"
    #include <stddef.h>
    #include <stdlib.h>

typedef struct img_cons_s {
    char *name;
    int (*func)(image_t *image, char *value);
} img_cons_t;

int img_construct_posx(image_t *image, char *value);
int img_construct_posy(image_t *image, char *value);
int img_construct_width(image_t *image, char *value);
int img_construct_height(image_t *image, char *value);
int img_construct_scale(image_t *image, char *value);
int img_construct_rotation(image_t *image, char *value);
int img_construct_texture(image_t *image, char *value);

static const img_cons_t IMG_CONS[] = {
    {"posx", img_construct_posx},
    {"posy", img_construct_posy},
    {"width", img_construct_width},
    {"height", img_construct_height},
    {"rotation", img_construct_rotation},
    {"scale", img_construct_scale},
    {"texture", img_construct_texture},
    {NULL, NULL}
};

int write_error(char const *str);
int nb_char_in_str(char *str, char c);
char *get_keyword(char *str);
char *get_value(char *str);
int my_strcmp(char *str1, char *str2);
int my_getnbr(char *str);
float my_atof(char *str);
char *my_strcpy(char *dest, char const *src);

#endif /*ENT_H_*/
