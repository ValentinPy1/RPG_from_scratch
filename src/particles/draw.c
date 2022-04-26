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
    particle_param_t param = setup_lava_param();
    partic_ll_t *node;

    update_groups(game_data->partic->next);
    sup_partic_groups(game_data->partic->next);
    draw_groups(win, game_data->partic->next);
    if (my_strcmp(scene->name, "game_menu") && get_rdm() > 0.5) {
        param.pos = (sfVector2f) {get_rdm() * 1920, get_rdm() * 1080};
        node = setup_partic_node(&param);
        add_partic_group(game_data->partic, node);
    }
}