/*
** EPITECH PROJECT, 2021
** my_screensaver
** File description:
** Source code to do my_screensaver
*/
#include "open_window.h"

void display_scene(sfRenderWindow *window, scene_t *scene)
{
    sfRenderWindow_drawSprite(window, scene->background_sprite, NULL);
    for (int index = 0; scene->buttons[index] != NULL; index++) {
        if (scene->buttons[index]->hitbox->is_hovered == 1)
            sfRenderWindow_drawSprite(window,
                    scene->buttons[index]->ho_sprite, NULL);
        else
            sfRenderWindow_drawSprite(window,
                    scene->buttons[index]->sprite, NULL);
    }
    for (int index = 0; scene->entities[index] != NULL; index++)
            sfRenderWindow_drawSprite(window,
                scene->entities[index]->sprite, NULL);
}
