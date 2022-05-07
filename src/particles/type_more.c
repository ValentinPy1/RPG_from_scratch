/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** type_more.c
*/

#include "particles.h"
#include "random.h"

particle_param_t setup_spark_param(void)
{
    particle_param_t param;
    float brightness = rdm_float(0, 255);
    param.pos = (sfVector2f) {960, 540};
    param.spawn_radius = (sfVector2f) {0, 0};
    param.rdm_vel = (sfVector2f) {1, 1};
    param.init_vel = (sfVector2f) {0, -1};
    param.color = (sfColor) {brightness, 255, 255, 255};
    param.max_duration = 50;
    param.size = 1;
    param.gravity = (sfVector2f) {0, 0.06};
    param.resistance = (sfVector2f) {0, 0.001};
    param.count = 1;
    return param;
}
