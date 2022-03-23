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

static const but_call_t BUT_CALL[] = {
    {NULL, NULL}
};

#endif /*CALL_H_*/
