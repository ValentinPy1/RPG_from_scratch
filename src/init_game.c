/*
** EPITECH PROJECT, 2022
** init_game
** File description:
** Source code to initalize game data
*/
#include "init_game.h"

void data_constructor(data_t *game_data)
{
    game_data->scene_names = get_names_scene(game_data->scene_list);
//     game_data->run_index = get_run_index(game_data->scene_names, "home_menu");
//     game_data->red = player_constructor();
//     game_data->partic = malloc(sizeof(partic_ll_t));
//     game_data->partic->partic_arr = NULL;
//     game_data->partic->next = NULL;
}

int init_game(int ac, char **av, data_t *game_data)
{
    game_data->debug_mode = 0;
    if (ac == 2 && my_strcmp(av[1], "-d") == 1)
        game_data->debug_mode = 1;
    game_data->scene_list = get_scenes();
    if (game_data->scene_list == NULL) {
        my_putstr("Unable to load one or many scene\n");
        return (-1);
    }
    data_constructor(game_data);
    my_putstr("Loading scene sucess\n");
    return (0);
}
