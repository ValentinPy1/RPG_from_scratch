/*
** EPITECH PROJECT, 2022
** button_callback.c
** File description:
** Source code of every callback
*/

#include "callbacks.h"

int nothing(button_t *button, char **scenes_name, int *index_run)
{
    return (0);
}

int play(button_t *button, char **scenes_name, int *index_run)
{
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "main_scene") == 1)
            *index_run = index;
    }
    return (0);
}

int quit(button_t *button, char **scenes_name, int *index_run)
{
    *index_run = -1;
    return 0;
}
