/*
** EPITECH PROJECT, 2022
** back_opt
** File description:
** Source code to construct background option
*/
#include "build_scene_background.h"

int build_back_type(scene_t *scene, char *value)
{
    printf("Building scene background type\n");
    if (my_strcmp(value, "img") == 1)
        return (0);
    if (my_strcmp(value, "map") == 1)
        return (0);
    return (0);
}

int build_back_path(scene_t *scene, char *value)
{
    printf("Building scene background path\n");
    return (0);
}
