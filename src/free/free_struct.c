/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** free_struct.c
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
    if (game_data == NULL)
        return;
    free_scenes(game_data->scene_list);
    free_player(game_data);
    free(game_data);
}
