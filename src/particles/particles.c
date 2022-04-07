/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particles.c
*/

#include "particles.h"
#include "random.h"
#include <math.h>

particle_t setup_particle(sfVector2f pos, sfVector2f vel, sfColor color, float dur)
{
    particle_t particle;
    sfCircleShape *circle = sfCircleShape_create();
    float angle = get_rdm() * PI * 2;
    particle.pos = pos;
    particle.vel = (sfVector2f) {rdm_float(0, cos(angle) * vel.x),
    rdm_float(0, sin(angle) * vel.y)};
    particle.duration = dur;
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setOrigin(circle, (sfVector2f) {1, 1});
    sfCircleShape_setRadius(circle, 1);
    sfCircleShape_setPosition(circle, pos);
    particle.circle = circle;
    return particle;
}

void update_particle(particle_t *p, sfVector2f vel)
{
    float newposx = p->pos.x + p->vel.x;
    float newposy = p->pos.y + p->vel.y;
    p->pos = (sfVector2f) {newposx, newposy};
    p->vel = vel;
    p->duration -= 1;
    if (p->duration < 0)
        sfCircleShape_setFillColor(p->circle, sfBlack);
    sfCircleShape_setPosition(p->circle, p->pos);
}

partic_array_t setup_particles_array(int count, sfVector2f pos)
{
    partic_array_t particles;
    int i;

    particles.particles = malloc(count * sizeof(particle_t));
    particles.count = count;
    for (i = 0; i < count; i++)
        particles.particles[i] = setup_particle(pos, (sfVector2f) {10, 10}, sfBlue, 200);
    return particles;
}

void update_particles(partic_array_t partic)
{
    int i;

    for (i = 0; i < partic.count; i++) {
        update_particle(&partic.particles[i], (sfVector2f) {partic.particles[i].vel.x * 0.999, partic.particles[i].vel.y * 0.999 + 0.2});
    }
}

void draw_particles(sfRenderWindow *win, partic_array_t partic)
{
    int i;

    for (i = 0; i < partic.count; i++) {
        sfRenderWindow_drawCircleShape(win, partic.particles[i].circle, NULL);
    }
}
