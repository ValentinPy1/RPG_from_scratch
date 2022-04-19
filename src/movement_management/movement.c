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
            game_data->red->pos.y -= 2;
        game_data->red->pos.y -= walk;
    }
}

void move_down(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.y += 2;
        game_data->red->pos.y += walk;
    }
}

void move_left(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.x -= 2;
        game_data->red->pos.x -= walk;
    }
}

void move_right(data_t *game_data, int walk)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            game_data->red->pos.x += 2;
        game_data->red->pos.x += walk;
    }
}

void init_view(sfRenderWindow *window, data_t *game_data)
{
    sfFloatRect view_rect = {0, 0, 640, 400};
    sfVector2f center_player_cam = {45, 45};

    sfView_reset(game_data->red->view, view_rect);
    sfView_setCenter(game_data->red->view, game_data->red->pos);
    sfView_move(game_data->red->view, center_player_cam);
    sfRenderWindow_setView(window, game_data->red->view);
}

void player_move(data_t *game_data, scene_t *scene)
{
    int walk = 5;

    if (scene->background_to_run == 1) {
        move_right(game_data, walk);
        move_left(game_data, walk);
        move_down(game_data, walk);
        move_up(game_data, walk);
        set_position(game_data->red->player_sprite, game_data->red->pos.x, game_data->red->pos.y);
    }
}
