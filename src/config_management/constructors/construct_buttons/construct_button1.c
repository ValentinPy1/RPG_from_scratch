/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Source code to construct a button
*/
#include "construct_button.h"

int but_construct_posx(button_t *button, char *value)
{
    int coord_x = my_getnbr(value);

    button->position.x = coord_x;
    button->hitbox->position.x = coord_x;
    return (0);
}

int but_construct_posy(button_t *button, char *value)
{
    int coord_y = my_getnbr(value);

    button->position.y = coord_y;
    button->hitbox->position.y = coord_y;
    return (0);
}

int but_construct_width(button_t *button, char *value)
{
    int width = my_getnbr(value);

    button->hitbox->width = width;
    return (0);
}

int but_construct_height(button_t *button, char *value)
{
    int height = my_getnbr(value);
    
    button->hitbox->height = height;
    return (0);
}

int but_construct_rotation(button_t *button, char *value)
{
    int rot = my_getnbr(value);

    button->rotation = rot;
    button->hitbox->rotation = rot;
    return (0);
}
