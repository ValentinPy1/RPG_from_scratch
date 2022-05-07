/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"
#include "particles.h"
#include "math.h"

void move_dir(data_t *game_data, sfVector2f dir, int key, int sprite)
{
    sfVector2f temp_pos = (sfVector2f) {game_data->red->pos.x +
    game_data->red->stats->spd * dir.x, game_data->red->pos.y +
    game_data->red->stats->spd * dir.y};

    if (sfKeyboard_isKeyPressed(key)) {
        game_data->red->player_rect->left = sprite * 16;
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map,
        temp_pos) == 1)
            return;
        if (is_blocking_tile(game_data->scene_list[game_data->run_index]->map,
        temp_pos) == 2) {
            game_data->red->pos.x = 1000;
            game_data->red->pos.y = 800;
        }
        if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            game_data->red->pos.x += game_data->red->stats->spd * dir.x * 0.5;
            game_data->red->pos.y += game_data->red->stats->spd * dir.y * 0.5;
        }
        game_data->red->pos.x += game_data->red->stats->spd * dir.x;
        game_data->red->pos.y += game_data->red->stats->spd * dir.y;
        player_walk(game_data, 16, 64);
    }
}

bool is_all_lava(scene_t *scene, int x, int y)
{
    for (int i = 0; i < 9; ++i) {
        if (!(scene->map->tiles[y / 32 +
        (i / 3 - 1)][x / 32 + (i % 3 - 1)] >= 4 && scene->map->tiles[y / 32 +
        (i / 3 - 1)][x / 32 + (i % 3 - 1)] <= 7)) {
            return false;
        }
    }
    return true;
}

void player_knockback(data_t *gd, scene_t *scene)
{
    player_t *red = gd->red;
    float newx = red->pos.x + red->kb_speed * cos(red->kb_dir);
    float newy = red->pos.y + red->kb_speed * sin(red->kb_dir);
    int x = floor(newx);
    int y = floor(newy);

    red->pos = (sfVector2f) {newx, newy};
    if (!(scene->map->tiles[(int) newy / 32][(int) newx / 32] >= 36 && scene->
    map->tiles[(int) newy / 32][(int) newx / 32] <= 43) && !(scene->map->tiles
    [y / 32][x / 32] >= 4 && scene->map->tiles[y / 32][x / 32] <= 7))
        red->kb_speed *= 0.9;
    if (is_all_lava(scene, x, y)) {
        gd->red->pos.x = 13 * 32;
        gd->red->pos.y = 9 * 32;
        gd->red->percentage = 0;
    }
}

void player_move(data_t *game_data, scene_t *scene)
{
    game_data->red->time = sfClock_getElapsedTime(game_data->red->clock);
    game_data->red->seconds = game_data->red->time.microseconds / 1000000.0;

    if (scene->map != NULL) {
        move_dir(game_data, (sfVector2f) {0, -1}, game_data->keys->up, 3);
        move_dir(game_data, (sfVector2f) {0, 1}, game_data->keys->down, 0);
        move_dir(game_data, (sfVector2f) {-1, 0}, game_data->keys->left, 1);
        move_dir(game_data, (sfVector2f) {1, 0}, game_data->keys->right, 2);
        set_position(game_data->red->player_sprite,
        game_data->red->pos.x, game_data->red->pos.y);
        player_knockback(game_data, scene);
    }
}
