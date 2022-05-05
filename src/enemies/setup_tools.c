/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** setup_tools.c
*/

#include "enemies.h"
#include <stdlib.h>

sfIntRect *set_enemy_rect(void)
{
    sfIntRect *rectangle = malloc(sizeof(sfIntRect));
    rectangle->top = 0;
    rectangle->left = 0;
    rectangle->width = 32;
    rectangle->height = 32;
    return rectangle;
}
