/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw.c
*/

#include "ennemies.h"

void draw_ennem(sfRenderWindow *win, ennem_t ennem)
{
    sfRenderWindow_drawCircleShape(win, ennem.circle, NULL);
}

void draw_ennemies(sfRenderWindow *win, ennemies_t *ennemies)
{
    if (ennemies == NULL || ennemies->next == NULL)
        return;
    draw_ennem(win, ennemies->next->ennem);
    draw_ennemies(win, ennemies->next);
}
