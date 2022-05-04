/*
** EPITECH PROJECT, 2022
** construct_background
** File description:
** SOurce code to construct background
*/

#include "construct_background.h"

int back_construct_map(scene_t *scene, char *path)
{
    scene->background_to_run = 1;
    scene->map = map_constructor();
    return (0);
}

int back_construct_img(scene_t *scene, char *path)
{
    scene->background_to_run = 2;
    scene->background_sprite = sfSprite_create();
    scene->background_texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(scene->background_sprite,
                            scene->background_texture, sfFalse);
    return (0);
}

    //TODO: Construct proc
int back_construct_proc(scene_t *scene, char *path)
{
    scene->background_to_run = 3;
    return (0);
}
