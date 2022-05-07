/*
** EPITECH PROJECT, 2022
** build_game_data
** File description:
** Source cod to build game data
*/
#include "structures.h"

void data_constructor(data_t *game_data)
{
    game_data->framerate = 60;
    game_data->debug_mode = 0;
    game_data->keys = build_keys();
    game_data->scene_list = get_scenes();
    game_data->scene_names = get_names_scene(game_data->scene_list);
    game_data->run_index = get_run_index(game_data->scene_names, "home_menu");
    game_data->red = player_constructor();
    game_data->scene_list[1]->partic = malloc(sizeof(partic_ll_t));
    game_data->scene_list[1]->partic->next = NULL;
    game_data->enemies = malloc(sizeof(enemies_t));
    game_data->enemies->next = NULL;
}
