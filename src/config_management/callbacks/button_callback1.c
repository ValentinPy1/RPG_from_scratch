/*
** EPITECH PROJECT, 2022
** button_callback.c
** File description:
** Source code of every callback
*/

#include "callbacks.h"

int nothing(data_t *game_data, char **scenes_name, int *index_run)
{
    return (0);
}

int play(data_t *game_data, char **scenes_name, int *index_run)
{
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "main_scene") == 1)
            *index_run = index;
    }
    return (0);
}

int quit(data_t *game_data, char **scenes_name, int *index_run)
{
    *index_run = -1;
    return 0;
}

int options(data_t *game_data, char **scenes_name, int *index_run)
{
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "options") == 1)
            *index_run = index;
    }
    return (0);
}
