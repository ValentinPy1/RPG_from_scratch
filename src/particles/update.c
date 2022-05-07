/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-3-myrpg-gabriel.lepinay
** File description:
** update
*/


#include "particles.h"
#include "structures.h"

void update_particle(data_t *gd, particle_t *p)
{
    float delta = 60.0 / gd->framerate;
    float newposx = p->pos.x + p->vel.x * delta;
    float newposy = p->pos.y + p->vel.y * delta;
    float newvelx = ((p->vel.x * (1 - p->res.x) + p->grav.x) - p->vel.x) * delta;
    float newvely = ((p->vel.y * (1 - p->res.y) + p->grav.y) - p->vel.y) * delta;

    p->pos = (sfVector2f) {newposx, newposy};
    p->vel = (sfVector2f) {p->vel.x + newvelx, p->vel.y + newvely};
    p->duration -= 1 * delta;
    sfCircleShape_setPosition(p->circle, p->pos);
}

void update_partic_arr(data_t *gd, partic_arr_t *partic)
{
    int i;

    partic->duration -= 1;
    for (i = 0; i < partic->count; i++) {
        if (partic->particles[i].duration > 0)
            update_particle(gd, &partic->particles[i]);
    }
}

void update_groups(data_t *gd, partic_ll_t *groups)
{
    if (groups == NULL)
        return;
    update_partic_arr(gd, groups->partic_arr);
    update_groups(gd, groups->next);
}