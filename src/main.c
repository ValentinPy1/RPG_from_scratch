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

int init_game(int ac, char **av, data_t *game_data);

int main(int ac, char **av)
{
    data_t *game_data = NULL;

    if (ac == 2 && my_strcmp(av[1], "-h") == 1) {
        usage();
        return (0);
    }
    if (init_game(ac, av, game_data) == -1)
        return (84);
    // parse_tile(game_data->scene_list[index]->map);
    // open_window(1920, 1080, game_data);
    // free_data(game_data);
    return (0);
}
