/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particles.c
*/

#include "particles.h"
#include "callbacks.h"
#include "structures.h"
#include "random.h"
#include <stdbool.h>
#include "manage_display.h"

bool is_in_screen(data_t *gd, sfVector2f pos);

void draw_partic_arr(sfRenderWindow *win, partic_arr_t *partic)
{
    int i;
    for (i = 0; i < partic->count; ++i) {
        if (partic->particles[i].duration > 0)
            sfRenderWindow_drawCircleShape(win,
            partic->particles[i].circle, NULL);
    }
}

void draw_groups(sfRenderWindow *win, partic_ll_t *groups)
{
    if (groups == NULL)
        return;
    draw_partic_arr(win, groups->partic_arr);
    draw_groups(win, groups->next);
}

static void spawn_fire(data_t *game_data)
{
    particle_param_t param = setup_fire_param();
    partic_ll_t *node;
    float delta = 60.0 / game_data->framerate;

    param.pos = (sfVector2f) {560, 495};
    if (is_in_screen(game_data, param.pos)) {
        node = setup_partic_node(&param);
        add_partic_group(game_data->scene_list[1]->partic, node);
    }
    param.pos = (sfVector2f) {1810, 720};
    if (is_in_screen(game_data, param.pos)) {
        node = setup_partic_node(&param);
        add_partic_group(game_data->scene_list[1]->partic, node);
    }
    param = setup_smoke_param();
    param.pos = (sfVector2f) {480, 240};
    if (is_in_screen(game_data, param.pos)) {
        node = setup_partic_node(&param);
        add_partic_group(game_data->scene_list[1]->partic, node);
    }
}

void handle_particles(sfRenderWindow *win,
data_t *game_data, scene_t *scene)
{
    particle_param_t lava = setup_lava_param();
    partic_ll_t *node_lava;

    update_groups(game_data, game_data->scene_list[1]->partic->next);
    sup_partic_groups(game_data->scene_list[1]->partic->next);
    draw_groups(win, game_data->scene_list[1]->partic->next);
    lava.pos = (sfVector2f) {get_rdm() * 1920, get_rdm() * 1080};
    if (is_in_screen(game_data, lava.pos) &&
    my_strcmp(scene->name, "main_scene") && get_rdm() > 0.5) {
        node_lava = setup_partic_node(&lava);
        add_partic_group(game_data->scene_list[1]->partic, node_lava);
    }
    spawn_fire(game_data);
}

void spawn_blood(data_t *game_data)
{
    partic_ll_t *node;
    particle_param_t param;

    param = setup_blood_param();
    param.pos = (sfVector2f) {game_data->red->pos.x,
    game_data->red->pos.y};
    node = setup_partic_node(&param);
    add_partic_group(game_data->scene_list[1]->partic, node);
}
