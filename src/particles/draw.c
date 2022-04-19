/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particles.c
*/

#include "particles.h"

void draw_partic_arr(sfRenderWindow *win, partic_arr_t *partic)
{
    int i;
    if (partic->duration > 0) {
        for (i = 0; i < partic->count; ++i) {
            sfRenderWindow_drawCircleShape(win, partic->particles[i].circle, NULL);
        }
    }
}
