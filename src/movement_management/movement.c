/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"

void player_move(data_t *game_data)
{
    int walk = 5;
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_y -= 2;
        game_data->scene_list[0]->map->movement_y -= walk;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_x -= 2;
        game_data->scene_list[0]->map->movement_x -= walk;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_y += 2;
        game_data->scene_list[0]->map->movement_y += walk;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_x += 2;
        game_data->scene_list[0]->map->movement_x += walk;
    }
}
