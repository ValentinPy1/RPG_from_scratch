/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"

void move_up(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && OOB_UP) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_y -= 2;
        game_data->scene_list[0]->map->movement_y -= walk;
    }
}

void move_down(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && OOB_DOWN) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_y += 2;
        game_data->scene_list[0]->map->movement_y += walk;
    }
}

void move_left(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && OOB_LEFT) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->scene_list[0]->map->movement_x -= 2;
        game_data->scene_list[0]->map->movement_x -= walk;
    }
}

void move_right(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) && OOB_RIGHT) {
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
