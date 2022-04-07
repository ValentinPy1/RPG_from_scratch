/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particles.h
*/

#ifndef _PARTICLES_H_
    #define _PARTICLES_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

    #define PI 3.14159265359

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    float duration;
    sfCircleShape *circle;
} particle_t;

typedef struct partic_array_s {
    particle_t *particles;
    int count;
} partic_array_t;

partic_array_t setup_particles_array(int count, sfVector2f pos);
void update_particles(partic_array_t partic);
void draw_particles(sfRenderWindow *win, partic_array_t partic);

#endif