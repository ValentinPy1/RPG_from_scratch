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
    if (p->duration < 0)
        sfCircleShape_setFillColor(p->circle, sfBlack);
    sfCircleShape_setPosition(p->circle, p->pos);
}

void update_partic_arr(partic_arr_t *partic)
{
    int i;

    for (i = 0; i < partic->count; i++)
        update_particle(&partic->particles[i]);
    partic->duration -= 1;
    if (partic->duration <= 0)
        destroy_partic_arr(partic);
}
