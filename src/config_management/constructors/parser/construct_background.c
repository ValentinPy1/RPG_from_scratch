/*
** EPITECH PROJECT, 2022
** construct_background
** File description:
** SOurce code to construct background of a scene
*/
#include "construct_background.h"

void construct_background(scene_t *scene, char **content, int index)
{
    char *value = get_value(content, index);

    scene->background_sprite = sfSprite_create();
    scene->background_texture = sfTexture_createFromFile(value, NULL);
    sfSprite_setTexture(scene->background_sprite,
                            scene->background_texture, sfFalse);
    return;
}
