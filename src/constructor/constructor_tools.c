/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** constructor_tools.c
*/

#include "structures.h"

void set_position(sfSprite *sprite, float x, float y)
{
    sfVector2f position = {x, y};

    sfSprite_setPosition(sprite, position);
}
