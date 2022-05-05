/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw.c
*/

#include "ennemies.h"
#include "particles.h"
#include "structures.h"

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

void spawn_ennem_blood(data_t *gd, sfVector2f pos)
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
