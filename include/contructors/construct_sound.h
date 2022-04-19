/*
** EPITECH PROJECT, 2022
** construct_sound
** File description:
** Header
*/

#ifndef SOUND_H_
    #define SOUND_H_
    #include "structures.h"
    #include <stdlib.h>

typedef struct sound_cons_s {
    char *name;
    int (*func)(scene_t *scene, char *path);
} sound_cons_t;

int sound_construct_path(scene_t *scene, char *path);
int sound_construct_volume(scene_t *scene, char *path);
int sound_construct_pitch(scene_t *scene, char *path);
int sound_construct_loop(scene_t *scene, char *path);

static const sound_cons_t SOUND_CONS[] = {
    {"path", sound_construct_path},
    {"volume", sound_construct_volume},
    {"pitch", sound_construct_pitch},
    {"looping", sound_construct_loop},
    {NULL, NULL}
};

int my_strlen(char const *str);
int nb_char_in_str(char *str, char c);
char *get_keyword(char *str);
char *get_value(char *str);
int my_strcmp(char *str1, char *str2);
float my_atof(char *str);
#endif /*SOUND_H_*/
