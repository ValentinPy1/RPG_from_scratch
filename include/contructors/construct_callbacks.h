/*
** EPITECH PROJECT, 2022
** construct_callbacks
** File description:
** Header
*/

#ifndef CALL_H_
    #define CALL_H_
    #include "structures.h"

typedef struct but_call_s {
    char *name;
    int (*func)(data_t *game_data, button_t *button, char **scenes_name);
} but_call_t;

int nothing(data_t *game_data, button_t *button, char **scenes_name);
int play(data_t *game_data, button_t *button, char **scenes_name);

static const but_call_t BUT_CALL[3] = {
    {"no", nothing},
    {"play", play},
    {NULL, NULL}
};

#endif /*CALL_H_*/
