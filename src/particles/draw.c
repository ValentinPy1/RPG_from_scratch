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

void handle_particles(sfRenderWindow *win,
data_t *game_data, scene_t *scene)
{
    particle_param_t lava = setup_lava_param();
    particle_param_t fire = setup_fire_param();
    partic_ll_t *node_lava;
    partic_ll_t *node_fire;

    update_groups(game_data->partic->next);
    sup_partic_groups(game_data->partic->next);
    draw_groups(win, game_data->partic->next);
    lava.pos = (sfVector2f) {get_rdm() * 1920, get_rdm() * 1080};
    if (is_in_screen(game_data, lava.pos) &&
    my_strcmp(scene->name, "main_scene") && get_rdm() > 0.5) {
        node_lava = setup_partic_node(&lava);
        add_partic_group(game_data->partic, node_lava);
    }
    fire.pos = (sfVector2f) {560, 400};
    if (is_in_screen(game_data, fire.pos)) {
        node_fire = setup_partic_node(&fire);
        add_partic_group(game_data->partic, node_fire);
    }
}

void spawn_blood(data_t *game_data, sfVector2i mouse_loc)
{
    partic_ll_t *node;
    particle_param_t param;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        param = setup_blood_param();
        param.pos = (sfVector2f) {game_data->red->pos.x,
        game_data->red->pos.y - 10};
        param.init_vel.x = (mouse_loc.x - 980) / 50;
        param.init_vel.y = (mouse_loc.y - 540) / 50;
        node = setup_partic_node(&param);
        add_partic_group(game_data->partic, node);
    } else if (sfMouse_isButtonPressed(sfMouseRight)) {
        param = setup_sperm_param();
        param.pos = (sfVector2f) {game_data->red->pos.x,
        game_data->red->pos.y - 10};
        param.init_vel.x = (mouse_loc.x - 980) / 50;
        param.init_vel.y = (mouse_loc.y - 540) / 50;
        node = setup_partic_node(&param);
        add_partic_group(game_data->partic, node);
    }
}