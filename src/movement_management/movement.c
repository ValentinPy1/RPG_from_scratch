/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"

void player_move(data_t *game_data)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        game_data->scene_list[0]->map->movement_y -= 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        game_data->scene_list[0]->map->movement_x -= 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        game_data->scene_list[0]->map->movement_y += 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        game_data->scene_list[0]->map->movement_x += 5;
    }
}
