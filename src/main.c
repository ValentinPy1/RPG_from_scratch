/*
** EPITECH PROJECT, 2022
** main
** File description:
** Source code of the main
*/
#include "main.h"

int main(int ac, char **av)
{
    scene_t **scene_list;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help_printer();
        return (0);
    }
    scene_list = get_scenes();
    if (scene_list == NULL)
        return (84);
    open_window(1920, 1080, scene_list);
    return (0);
}
