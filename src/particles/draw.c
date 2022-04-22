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
    for (i = 0; i < partic->count; ++i) {
        if (partic->particles[i].duration > 0)
            sfRenderWindow_drawCircleShape(win, partic->particles[i].circle, NULL);
    }
}

void draw_groups(sfRenderWindow *win, partic_ll_t *groups)
{
    if (groups == NULL)
        return;
    draw_partic_arr(win, groups->partic_arr);
    draw_groups(win, groups->next);
}
