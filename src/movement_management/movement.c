/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"
#include "particles.h"
#include "math.h"

void move_dir(data_t *gd, sfVector2f dir, int key, int sprite)
{
    sfVector2f temp_pos = (sfVector2f) {gd->red->pos.x + gd->red->stats->spd
    * dir.x, gd->red->pos.y + gd->red->stats->spd * dir.y};
    float delta = 60.0 / gd->framerate;
    if (!sfKeyboard_isKeyPressed(key))
        return;
    gd->red->facing = sprite;
    gd->red->player_rect->left = sprite * 16;
    gd->red->attack_rect->left = sprite * 32;
    if (is_blocking_tile(gd->scene_list[gd->run_index]->map, temp_pos) == 1)
        return;
    if (is_blocking_tile(gd->scene_list[gd->run_index]->map, temp_pos) == 2) {
        gd->red->pos.x = 2260;
        gd->red->pos.y = 620;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        gd->red->pos.x += gd->red->stats->spd * dir.x * 0.6 * delta;
        gd->red->pos.y += gd->red->stats->spd * dir.y * 0.6 * delta;
    }
    gd->red->pos.x += gd->red->stats->spd * dir.x * delta;
    gd->red->pos.y += gd->red->stats->spd * dir.y * delta;
    player_walk(gd, 16, 64);
}

void player_knockback(data_t *gd, scene_t *scene)
{
    player_t *red = gd->red;
    float newx = red->pos.x + red->kb_speed * cos(red->kb_dir);
    float newy = red->pos.y + red->kb_speed * sin(red->kb_dir);

    red->pos = (sfVector2f) {newx, newy};
    if (!(scene->map->tiles[(int) newy / 32][(int) newx / 32] >= 36
    && scene->map->tiles[(int) newy / 32][(int) newx / 32] <= 43))
        red->kb_speed *= 0.9;
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
