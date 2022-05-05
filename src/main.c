/*
** EPITECH PROJECT, 2022
** main
** File description:
** Source code of the main
*/
#include "main.h"

static void usage(void)
{
    my_putstr("./my_rpg\n");
}

keys_t *get_keys(void)
{
    keys_t *keys = malloc(sizeof(keys_t));
    keys->up = sfKeyUp;
    keys->right = sfKeyRight;
    keys->down = sfKeyDown;
    keys->left = sfKeyLeft;
    return keys;
}

void data_constructor(data_t *game_data)
{
    game_data->framerate = 60;
    game_data->debug_mode = 0;
    game_data->keys = get_keys();
    game_data->scene_list = get_scenes();
    game_data->scene_names = get_names_scene(game_data->scene_list);
    game_data->run_index = get_run_index(game_data->scene_names, "home_menu");
    game_data->red = player_constructor();
    game_data->scene_list[1]->partic = malloc(sizeof(partic_ll_t));
    game_data->scene_list[1]->partic->next = NULL;
    game_data->enemies = malloc(sizeof(enemies_t));
    game_data->enemies->next = NULL;
}

int main(int ac, char **av)
{
    data_t *game_data = malloc(sizeof(data_t));

    if (ac == 2 && my_strcmp(av[1], "-h") == 1) {
        usage();
        return (0);
    }
    data_constructor(game_data);
    if (ac == 2 && my_strcmp(av[1], "-d") == 1)
        game_data->debug_mode = 1;
    if (game_data->scene_list == NULL) {
        my_putstr("Error while loading scene\n");
        return (84);
    }
    my_putstr("Loading scene sucess\n");
    int index = get_run_index(game_data->scene_names, "main_scene");
    open_window(1920, 1080, game_data);
    free_data(game_data);
    return (0);
}
