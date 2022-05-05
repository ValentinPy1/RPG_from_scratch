/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw.c
*/

#include "enemies.h"

void draw_enem(sfRenderWindow *win, enem_t *enem)
{
    sfRenderWindow_drawSprite(win, enem->sprite, NULL);
}

void draw_enemies(sfRenderWindow *win, enemies_t *enemies)
{
    if (enemies == NULL || enemies->next == NULL)
        return;
    draw_enem(win, enemies->next->enem);
    draw_enemies(win, enemies->next);
}
