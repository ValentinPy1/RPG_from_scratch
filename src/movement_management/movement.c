/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"

void move_up(data_t *game_data, int walk)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x,
    game_data->red->pos.y - walk};

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        game_data->red->player_rect->left = 48;
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map,
        temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.y -= 1;
        game_data->red->pos.y -= walk;
        player_walk(game_data, game_data->red->player_rect, 16, 64);
    }
}

void move_down(data_t *game_data, int walk)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x,
    game_data->red->pos.y + walk};

    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        game_data->red->player_rect->left = 0;
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map,
        temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.y += 1;
        game_data->red->pos.y += walk;
        player_walk(game_data, game_data->red->player_rect, 16, 64);
    }
}

void move_left(data_t *game_data, int walk)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x - walk,
    game_data->red->pos.y};

    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        game_data->red->player_rect->left = 16;
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map,
        temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.x -= 1;
        game_data->red->pos.x -= walk;
        player_walk(game_data, game_data->red->player_rect, 16, 64);
    }
}

void move_right(data_t *game_data, int walk)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x + walk,
    game_data->red->pos.y};

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        game_data->red->player_rect->left = 32;
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map,
        temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.x += 1;
        game_data->red->pos.x += walk;
        player_walk(game_data, game_data->red->player_rect, 16, 64);
    }
}

void player_move(data_t *game_data, scene_t *scene)
{
    int walk = 2;
    game_data->red->time = sfClock_getElapsedTime(game_data->red->clock);
    game_data->red->seconds = game_data->red->time.microseconds / 1000000.0;

    if (scene->background_to_run == 1) {
        move_right(game_data, walk);
        move_left(game_data, walk);
        move_down(game_data, walk);
        move_up(game_data, walk);
        set_position(game_data->red->player_sprite,
        game_data->red->pos.x, game_data->red->pos.y);
    }
}
