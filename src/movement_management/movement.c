/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"
#include "particles.h"


void move_dir(data_t *game_data, sfVector2f dir, int key, int sprite)
{
    float walk = 2;
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x + walk * dir.x,
    game_data->red->pos.y + walk * dir.y};

    if (sfKeyboard_isKeyPressed(key)) {
        game_data->red->player_rect->left = sprite * 16;
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map,
        temp_pos) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            game_data->red->pos.x += walk * dir.x * 0.5;
            game_data->red->pos.y += walk * dir.y * 0.5;
        }
        game_data->red->pos.x += walk * dir.x;
        game_data->red->pos.y += walk * dir.y;
        player_walk(game_data, game_data->red->player_rect, 16, 64);
    }
}

void player_move(data_t *game_data, scene_t *scene)
{
    int walk = 2;
    game_data->red->time = sfClock_getElapsedTime(game_data->red->clock);
    game_data->red->seconds = game_data->red->time.microseconds / 1000000.0;

    if (scene->background_to_run == 1) {
        move_dir(game_data, (sfVector2f) {0, -1}, sfKeyUp, 3);
        move_dir(game_data, (sfVector2f) {0, 1}, sfKeyDown, 0);
        move_dir(game_data, (sfVector2f) {-1, 0}, sfKeyLeft, 1);
        move_dir(game_data, (sfVector2f) {1, 0}, sfKeyRight, 2);
        set_position(game_data->red->player_sprite,
        game_data->red->pos.x, game_data->red->pos.y);
    }
}
