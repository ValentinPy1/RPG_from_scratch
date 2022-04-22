/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** update.c
*/

#include "particles.h"

void update_particle(particle_t *p)
{
    float newposx = p->pos.x + p->vel.x;
    float newposy = p->pos.y + p->vel.y;
    float newvelx = p->vel.x * (1 - p->res.x) + p->grav.x;
    float newvely = p->vel.y * (1 - p->res.y) + p->grav.y;

    p->pos = (sfVector2f) {newposx, newposy};
    p->vel = (sfVector2f) {newvelx, newvely};
    p->duration -= 1;
    sfCircleShape_setPosition(p->circle, p->pos);
}

void update_partic_arr(partic_arr_t *partic)
{
    int i;

    partic->duration -= 1;
    for (i = 0; i < partic->count; i++) {
        if (partic->particles[i].duration > 0)
            update_particle(&partic->particles[i]);
    }
}

void update_groups(partic_ll_t *groups)
{
    if (groups == NULL)
        return;
    update_partic_arr(groups->partic_arr);
    update_groups(groups->next);
}
