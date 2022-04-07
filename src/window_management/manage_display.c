/*
** EPITECH PROJECT, 2021
** manage_display
** File description:
** Source code to manage display
*/
#include "manage_display.h"

void display_vertices(sfRenderWindow *window, hitbox_t *hitbox)
{
    for (int index = 0; index < 4; index++) {
        sfCircleShape *circle = sfCircleShape_create();

        sfCircleShape_setPosition(circle, *hitbox->vertices[index]);
        sfCircleShape_setRadius(circle, 3);
        sfCircleShape_setFillColor(circle, sfRed);
        sfCircleShape_setOutlineThickness(circle, 0);
        sfRenderWindow_drawCircleShape(window, circle, sfFalse);
    }
}

void display_scene(sfRenderWindow *window, scene_t *scene)
{
    for (int index = 0; scene->buttons[index] != NULL; index++) {
        sfRenderWindow_drawSprite(window,
            scene->buttons[index]->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, scene->buttons[index]->hitbox->rectangle, sfFalse);
        display_vertices(window, scene->buttons[index]->hitbox);
    }
}
