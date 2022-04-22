/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"

void move_up(data_t *game_data, int walk)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x, game_data->red->pos.y - walk};

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map, temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.y -= 2;
        game_data->red->pos.y -= walk;
    }
}

void move_down(data_t *game_data, int walk)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x, game_data->red->pos.y + walk};
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map, temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.y += 2;
        game_data->red->pos.y += walk;
    }
}

void move_left(data_t *game_data, int walk)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x - walk, game_data->red->pos.y};

    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map, temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.x -= 2;
        game_data->red->pos.x -= walk;
    }
}

void move_right(data_t *game_data, int walk)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x + walk, game_data->red->pos.y};

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map, temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.x += 2;
        game_data->red->pos.x += walk;
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
        set_position(game_data->red->player_sprite, game_data->red->pos.x - 16, game_data->red->pos.y - 26);
    }
}
