/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** animations.c
*/

#include "movement.h"

void step_particles(data_t *game_data)
{
    partic_ll_t *node;
    particle_param_t param;

    param = setup_step_param();
    param.pos = (sfVector2f) {game_data->red->pos.x,
    game_data->red->pos.y};
    node = setup_partic_node(&param);
    add_partic_group(game_data->scene_list[1]->partic, node);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->top += offset;
    if (rect->top >= max_value) {
        rect->top = 0;
    }
}

void player_walk(data_t *game_data, sfIntRect *rect, int offset, int max_value)
{
    if (game_data->red->seconds > 0.15) {
        move_rect(game_data->red->player_rect, offset, max_value);
        sfClock_restart(game_data->red->clock);
        step_particles(game_data);
    }
}
