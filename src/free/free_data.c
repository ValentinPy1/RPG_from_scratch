/*
** EPITECH PROJECT, 2022
** free_data
** File description:
** Source code to free all data
*/

#include "free_data.h"

static void free_player(data_t *game_data)
{
    sfClock_destroy(game_data->red->clock);
    free(game_data->red->player_rect);
    sfView_destroy(game_data->red->view);
    free(game_data->red->stats);
    free(game_data->red);
}

void free_data(data_t *game_data)
{
    free_scenes(game_data->scene_list, game_data->scene_names);
    free_player(game_data);
    free(game_data->keys);
    free(game_data);
}
