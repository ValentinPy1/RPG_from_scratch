/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Source code to construct a button
*/
#include "construct_button.h"

int construct_posx(button_t *button, char *value)
{
    button->posx = my_getnbr(value);
    button->is_selected = 0;
    return (0);
}

int construct_posy(button_t *button, char *value)
{
    button->posy = my_getnbr(value);
    button->position = (sfVector2f) {button->posx, button->posy};
    return (0);
}

int construct_width(button_t *button, char *value)
{
    button->width = my_getnbr(value);
    return (0);
}

int construct_height(button_t *button, char *value)
{
    button->height = my_getnbr(value);
    return (0);
}

int construct_rotation(button_t *button, char *value)
{
    button->rotation = my_getnbr(value);
    return (0);
}
