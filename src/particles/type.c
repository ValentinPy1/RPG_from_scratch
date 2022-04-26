/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** type.c
*/

#include "particles.h"
#include "random.h"

particle_param_t setup_lava_param(void)
{
    particle_param_t param;
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {0, 0};
    param.rdm_vel = (sfVector2f) {2, 0.5};
    param.init_vel = (sfVector2f) {0, -2};
    param.color = (sfColor) {234 + 20 * get_rdm(), 98 + 20 * get_rdm(), 0, 255};
    param.max_duration = 100;
    param.size = 2;
    param.gravity = (sfVector2f) {0, 0.1};
    param.resistance = (sfVector2f) {0, 0.001};
    param.count = 2;
    return param;
}

particle_param_t setup_blood_param(void)
{
    particle_param_t param;
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {0, 0};
    param.rdm_vel = (sfVector2f) {3, 3};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {220, 10, 10, 255};
    param.max_duration = 20;
    param.size = 1.5;
    param.gravity = (sfVector2f) {0, 0.3};
    param.resistance = (sfVector2f) {0, 0.01};
    param.count = 100;
    return param;
}

particle_param_t setup_fire_param(void)
{
    particle_param_t param;
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {20, 20};
    param.rdm_vel = (sfVector2f) {1, 1};
    param.init_vel = (sfVector2f) {0, 0};
    param.color = (sfColor) {230, 50 + get_rdm() * 50, 10, 200};
    param.max_duration = 60;
    param.size = 1.5;
    param.gravity = (sfVector2f) {0, -0.2};
    param.resistance = (sfVector2f) {0, 0.1};
    param.count = 200;
    return param;
}
