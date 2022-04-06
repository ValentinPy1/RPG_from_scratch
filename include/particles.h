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

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    float duration;
    sfCircleShape circle;
} particle_t;

#endif