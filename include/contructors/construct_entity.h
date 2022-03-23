/*
** EPITECH PROJECT, 2022
** construct_entity
** File description:
** Header
*/

#ifndef ENT_H_
    #define ENT_H_
    #include "structures.h"
    #include <stddef.h>
    #include <stdlib.h>

typedef struct ent_cons_s {
    char *name;
    int (*func)(entity_t *entity, char *value);
} ent_cons_t;

int sp_construct_posx(entity_t *entity, char *value);

int sp_construct_posy(entity_t *entity, char *value);

int sp_construct_width(entity_t *entity, char *value);

int sp_construct_height(entity_t *entity, char *value);

int sp_construct_rotation(entity_t *entity, char *value);

int sp_construct_scale(entity_t *entity, char *value);

int sp_construct_texture(entity_t *entity, char *value);

int sp_construct_sound(entity_t *entity, char *value);

static const ent_cons_t ENT_CONS[] = {
    {"posx", sp_construct_posx},
    {"posy", sp_construct_posy},
    {"width", sp_construct_width},
    {"height", sp_construct_height},
    {"rotation", sp_construct_rotation},
    {"scale", sp_construct_scale},
    {"texture", sp_construct_texture},
    {"sound", sp_construct_sound},
    {NULL, NULL}
};

hitbox_t *init_hitbox(hitbox_data_t *hitbox_data, int height, int width);

int write_error(char const *str);

int nb_char_in_str(char *str, char c);

char *get_keyword(char *str);

char *get_value(char **content, int line);

int my_strcmp(char *str1, char *str2);

int my_getnbr(char *str);

#endif /*ENT_H_*/
