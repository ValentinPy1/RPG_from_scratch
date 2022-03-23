/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Source code to construct a button
*/
#include "construct_button.h"

int construct_posx(button_t *button, char *value)
{
    int coord_x = my_getnbr(value);

    button->position.x = coord_x;
    button->center.x = coord_x / 2;
    button->hitbox->position.x = coord_x;
    button->hitbox->center.x = coord_x / 2;
    return (0);
}

int construct_posy(button_t *button, char *value)
{
    int coord_y = my_getnbr(value);

    button->position.y = coord_y;
    button->center.y = coord_y / 2;
    button->hitbox->position.y = coord_y;
    button->hitbox->center.y = coord_y / 2;
    return (0);
}

int construct_width(button_t *button, char *value)
{
    button->hitbox->width = my_getnbr(value);
    return (0);
}

int construct_height(button_t *button, char *value)
{
    button->hitbox->height = my_getnbr(value);
    return (0);
}

int construct_rotation(button_t *button, char *value)
{
    int rot = my_getnbr(value);

    button->rotation = rot;
    button->hitbox->rotation = rot;
    return (0);
}
