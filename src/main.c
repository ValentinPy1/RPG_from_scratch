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

int main(int ac, char **av)
{
    data_t *game_data = malloc(sizeof(data_t));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0) {
        usage();
    if (ac == 2 && my_strcmp(av[1], "-h") == 1) {
        my_putstr("HELP\n"); // TO DO: USAGE
        return (0);
    }
    game_data->debug_mode = 0;
    if (ac == 2 && my_strcmp(av[1], "-d") == 1)
        game_data->debug_mode = 1;
    game_data->scene_list = get_scenes();
    game_data->scene_names = get_names_scene(game_data->scene_list);
    game_data->run_index = get_run_index(game_data->scene_names, "home_menu");
    if (game_data->scene_list == NULL) {
        my_putstr("Error while loading scene\n");
        return (84);
    }
    my_putstr("Loading scene sucess\n");
    open_window(1920, 1080, game_data);
    free_data(game_data);
    return (0);
}
