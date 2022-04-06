/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particles.c
*/

#include "particles.h"
#include "random.h"

particle_t setup_particle(sfVector2f pos, sfVector2f vel, sfColor color, float dur)
{
    particle_t particle;
    sfCircleShape *circle = sfCircleShape_create();
    particle.pos = pos;
    particle.vel = (sfVector2f) {rdm_float(-vel.x, vel.x),
    rdm_float(-vel.x, vel.x)};
    particle.duration = dur;
    particle.motion_power = power;
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setOrigin(circle, (sfVector2f) {radius, radius});
    sfCircleShape_setRadius(circle, 1);
    sfCircleShape_setPosition(circle, pos);
    particle.circle = circle;
}

void update_particle(particle_t *p, sfVector2f accel)
{
    float newposx = p->pos.x + p->vel.x;
    float newposy = p->pos.y + p->vel.y;
    float newvelx = p->vel.x + accel.x;
    float newvely = p->vel.y + accel.y;
    p->pos = (sfVector2f) {newposx, newposy};
    p->vel = (sfVector2f) {newvelx, newvely};
    p->duration -= 1;
    sfCircleShape_setPosition(p->pos);
}

