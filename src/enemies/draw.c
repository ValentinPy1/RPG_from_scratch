/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw.c
*/

#include "enemies.h"
#include "particles.h"
#include "structures.h"


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

void spawn_enem_blood(data_t *gd, sfVector2f pos)
{
    partic_ll_t *node;
    particle_param_t param;

        param = setup_blood_param();
        param.pos = (sfVector2f) pos;
        param.color = (sfColor) {150, 0, 150, 255};
        param.count = 10;
        node = setup_partic_node(&param);
        add_partic_group(gd->scene_list[1]->partic, node);
}
