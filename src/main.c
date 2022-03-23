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
        printf("HELP\n");
        return (0);
    }
    scene_list = get_scenes();
    if (scene_list == NULL) {
        printf("Error while loading scene\n"); //TODO REMOVE  
        return (84);
    }
    printf("Loading scene sucess\n"); //TODO REMOVE
    // open_window(1920, 1080, scene_list);
    return (0);
}
