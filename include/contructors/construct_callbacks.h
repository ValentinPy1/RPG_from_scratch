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
    int (*func)(struct button_s *button, char **scenes_name, int *index_run);
} but_call_t;

int nothing(struct button_t *button, char **scenes_name, int *index_run);
int play(struct button_s *button, char **scenes_name, int *index_run);

static const but_call_t BUT_CALL[3] = {
    {"no", nothing},
    {"play", play},
    {NULL, NULL}
};

#endif /*CALL_H_*/
