/*
** EPITECH PROJECT, 2022
** button_callback.c
** File description:
** Source code of every callback
*/

#include "callbacks.h"

int nothing(data_t *game_data, button_t *button, char **scenes_name)
{
    return (0);
}

int play(data_t *game_data, button_t *button, char **scenes_name)
{
    if (game_data->scene_list[game_data->run_index]->music != NULL)
        sfSound_stop(game_data->scene_list[game_data->run_index]->music);
    for (int index = 0; scenes_name[index] != NULL; index++) {
        if (my_strcmp(scenes_name[index], "game_menu") == 1)
            game_data->run_index = index;
    }
    if (game_data->scene_list[game_data->run_index]->music != NULL)
        sfSound_play(game_data->scene_list[game_data->run_index]->music);
    return (0);
}
