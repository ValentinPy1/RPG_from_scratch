/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"

void move_up(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_y -= 2;
        game_data->scene_list[0]->map->movement_y -= walk;
    }
}

void move_down(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_y += 2;
        game_data->scene_list[0]->map->movement_y += walk;
    }
}

void move_left(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_x -= 2;
        game_data->scene_list[0]->map->movement_x -= walk;
    }
}

void move_right(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_x += 2;
        game_data->scene_list[0]->map->movement_x += walk;
    }
}

void player_move(data_t *game_data, scene_t *scene)
{
    int walk = 5;

    if (scene->background_to_run == 1) {
        move_right(game_data, walk);
        move_left(game_data, walk);
        move_down(game_data, walk);
        move_up(game_data, walk);
    }
}