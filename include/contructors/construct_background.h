/*
** EPITECH PROJECT, 2022
** construct_entity
** File description:
** Header
*/

#ifndef BACK_H_
    #define BACK_H_
    #include "structures.h"
    #include <stdlib.h>

typedef struct back_cons_s {
    char *name;
    int (*func)(scene_t *scene, char *path);
} back_cons_t;

int back_construct_map(scene_t *scene, char *path);

int back_construct_proc(scene_t *scene, char *path);

int back_construct_img(scene_t *scene, char *path);

static const back_cons_t BACK_CONS[] = {
    {"map", back_construct_map},
    {"path", back_construct_img},
    {"procedural", back_construct_proc},
    {NULL, NULL}
};

int my_strlen(char const *str);

int nb_char_in_str(char *str, char c);

char *get_keyword(char *str);

char *get_value(char **content, int line);

int my_strcmp(char *str1, char *str2);

#endif /*BACK_H_*/
