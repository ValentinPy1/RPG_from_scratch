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

int construct_posx(button_t *button, char *value);

int construct_posy(button_t *button, char *value);

int construct_width(button_t *button, char *value);

int construct_height(button_t *button, char *value);

int construct_rotation(button_t *button, char *value);

int construct_scale(button_t *button, char *value);

int construct_texture(button_t *button, char *value);

int construct_ho_texture(button_t *button, char *value);

int construct_sound(button_t *button, char *value);

int construct_callback(button_t *button, char *value);

static const but_cons_t BUT_CONS[] = {
    {"posx", construct_posx},
    {"posy", construct_posy},
    {"width", construct_width},
    {"height", construct_height},
    {"rotation", construct_rotation},
    {"scale", construct_scale},
    {"texture", construct_texture},
    {"ho_texture", construct_ho_texture},
    {"sound", construct_sound},
    {"callback", construct_callback},
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
