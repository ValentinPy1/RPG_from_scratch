/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"
#include "particles.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

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
        gd->red->pos.x += gd->red->stats->spd * dir.x * 0.6 * delta / 10;
        gd->red->pos.y += gd->red->stats->spd * dir.y * 0.6 * delta / 10;
    }
    gd->red->pos.x += gd->red->stats->spd * dir.x * delta / 10;
    gd->red->pos.y += gd->red->stats->spd * dir.y * delta / 10;
    player_walk(gd, gd->red->player_rect, 16, 64);
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
        for (int index = 0; gd->scene_names[index] != NULL; index++) {
            if (my_strcmp(gd->scene_names[index], "defeat") == 1)
                gd->run_index = index;
    }
    }
}

void handle_percentage(data_t *gd, scene_t *scene)
{
    char *str = my_getstr(gd->red->percentage);
    if (gd->frame_count % (gd->framerate * REGEN_DELAY) == 0 &&
    gd->red->percentage > 0) {
        gd->red->percentage -= 1;
    }
    sfText_setPosition(scene->texts[0],
    (sfVector2f) {gd->red->pos.x - 290, gd->red->pos.y - 200});
    sfText_setString(scene->texts[0], str);
    free(str);
}

void player_move(data_t *gd, scene_t *scene)
{
    gd->red->time = sfClock_getElapsedTime(gd->red->clock);
    gd->red->seconds = gd->red->time.microseconds / 1000000.0;
    if (scene->background_to_run == 1) {
        move_dir(gd, (sfVector2f) {0, -1}, gd->keys->up, 3);
        move_dir(gd, (sfVector2f) {0, 1}, gd->keys->down, 0);
        move_dir(gd, (sfVector2f) {-1, 0}, gd->keys->left, 1);
        move_dir(gd, (sfVector2f) {1, 0}, gd->keys->right, 2);
        set_position(gd->red->player_sprite,
        gd->red->pos.x, gd->red->pos.y);
        set_position(gd->red->attack_sprite,
        gd->red->pos.x, gd->red->pos.y);
        player_knockback(gd, scene);
        handle_percentage(gd, scene);
    }
}
