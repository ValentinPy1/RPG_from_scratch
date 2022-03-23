/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Source code to construct a button
*/
#include "construct_button.h"

// TO DO CLICKED TEXTURE

int construct_sel_texture(button_t *button, char *value)
{
    button->sel_sprite = sfSprite_create();
    button->sel_texture = sfTexture_createFromFile(value, NULL);
    if (button->sel_texture == NULL)
        return (-1);
    sfSprite_setTexture(button->sel_sprite, button->sel_texture, sfFalse);
    sfSprite_setScale(button->sel_sprite, button->scale);
    sfSprite_setRotation(button->sel_sprite, button->rotation);
    sfSprite_setPosition(button->sel_sprite, button->position);
    return (0);
}
