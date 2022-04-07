/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Header
*/

#ifndef BUTT_H_
    #define BUTT_H_
    #include "structures.h"
    #include <stddef.h>
    #include <stdlib.h>

typedef struct but_cons_s {
    char *name;
    int (*func)(button_t *button, char *value);
} but_cons_t;

int but_construct_posx(button_t *button, char *value);
int but_construct_posy(button_t *button, char *value);
int but_construct_width(button_t *button, char *value);
int but_construct_height(button_t *button, char *value);
int but_construct_rotation(button_t *button, char *value);
int but_construct_scale(button_t *button, char *value);
int but_construct_texture(button_t *button, char *value);
int but_construct_ho_texture(button_t *button, char *value);
int but_construct_sound(button_t *button, char *value);
int but_construct_callback(button_t *button, char *value);

static const but_cons_t BUT_CONS[] = {
    {"posx", but_construct_posx},
    {"posy", but_construct_posy},
    {"width", but_construct_width},
    {"height", but_construct_height},
    {"rotation", but_construct_rotation},
    {"scale", but_construct_scale},
    {"texture", but_construct_texture},
    {"ho_texture", but_construct_ho_texture},
    {"sound", but_construct_sound},
    {"callback", but_construct_callback},
    {NULL, NULL}
};

int write_error(char const *str);
int nb_char_in_str(char *str, char c);
char *get_keyword(char *str);
char *get_value(char *str);
int my_strcmp(char *str1, char *str2);
int my_getnbr(char *str);
int init_hitbox(hitbox_t *hitbox);

#endif /*BUTT_H_*/
