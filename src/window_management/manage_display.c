/*
** EPITECH PROJECT, 2021
** manage_display
** File description:
** Source code to manage display
*/
#include "manage_display.h"

void display_hitbox(sfRenderWindow *window, hitbox_t *hitbox)
{
    sfRenderWindow_drawRectangleShape(window, hitbox->rectangle, sfFalse);
    for (int index = 0; hitbox->circle[index] != NULL; index++) {
        sfRenderWindow_drawCircleShape(window, hitbox->circle[index], sfFalse);       
    }
}

void display_scene(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    if (scene->background_to_run == 2)
        sfRenderWindow_drawSprite(window, scene->background_sprite, NULL);
    for (int index = 0; scene->buttons[index] != NULL; index++) {
        sfRenderWindow_drawSprite(window,
            scene->buttons[index]->sprite, NULL);
        if (game_data->debug_mode == 1)
            display_hitbox(window, scene->buttons[index]->hitbox);
    }
    for (int index = 0; scene->texts[index] != NULL; index++) {
        sfRenderWindow_drawText(window, scene->texts[index], NULL);
    }
}
