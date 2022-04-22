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

typedef struct particle_param_s {
    sfVector2f pos;
    sfVector2f spawn_radius;
    sfVector2f init_vel;
    sfVector2f rdm_vel;
    sfColor color;
    int max_duration;
    float size;
    sfVector2f gravity;
    sfVector2f resistance;
} particle_param_t;

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    float duration;
    sfVector2f grav;
    sfVector2f res;
    sfCircleShape *circle;
} particle_t;

typedef struct partic_arr_s {
    particle_t *particles;
    int count;
    int duration;
} partic_arr_t;

typedef struct partic_ll_s {
    partic_arr_t *partic_arr;
    struct partic_ll_s *next;
} partic_ll_t;

partic_arr_t *setup_partic_arr(int count, particle_param_t *param);
void update_partic_arr(partic_arr_t *partic);
void draw_partic_arr(sfRenderWindow *win, partic_arr_t *partic);
particle_param_t setup_default_param(void);
void destroy_partic_arr(partic_arr_t *partic_arr);
partic_ll_t *setup_partic_node(int count, particle_param_t *p);
void draw_groups(sfRenderWindow *win, partic_ll_t *groups);
void sup_partic_groups(partic_ll_t *groups);
void update_groups(partic_ll_t *groups);
void add_partic_group(partic_ll_t *groups, partic_ll_t *node);

#endif