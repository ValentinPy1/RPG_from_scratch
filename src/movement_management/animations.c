/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** animations.c
*/

#include "movement.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->top += offset;
    if (rect->top >= max_value) {
        rect->top = 0;
    }
}

void player_walk(data_t *game_data, sfIntRect *rect, int offset, int max_value)
{
    if (game_data->red->seconds > 0.15) {
        move_rect(game_data->red->player_rect, offset, max_value);
        sfClock_restart(game_data->red->clock);
    }
}
