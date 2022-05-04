/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** setup.c
*/

#include "ennemies.h"
#include <stdlib.h>
#include <structures.h>
#include "random.h"
#include "math.h"
#include <stdio.h>

static ennem_t setup_ennem(sfVector2f pos)
{
    ennem_t ennem;
    sfCircleShape *circle = sfCircleShape_create();

    ennem.damage = 0;
    ennem.speed = 1.2;
    ennem.direction = 0;
    ennem.life = 100;
    ennem.pos = pos;
    sfCircleShape_setFillColor(circle, (sfColor) {150, 0, 150, 255});
    sfCircleShape_setOutlineColor(circle, (sfColor) {0, 0, 0, 255});
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setRadius(circle, 10);
    sfCircleShape_setOrigin(circle, (sfVector2f) {10, 10});
    sfCircleShape_setPosition(circle, pos);
    ennem.circle = circle;
    ennem.destination = pos;
    return ennem;
}

ennemies_t *setup_ennemies_node(sfVector2f pos)
{
    ennemies_t *ennemies = malloc(sizeof(ennemies_t));

    ennemies->ennem = setup_ennem(pos);
    ennemies->next = NULL;
    return ennemies;
}

static void add_ennemies_node(ennemies_t *ennemies, ennemies_t *node)
{
    if (ennemies->next == NULL) {
        ennemies->next = node;
        return;
    }
    add_ennemies_node(ennemies->next, node);
}

void add_ennem(ennemies_t *ennemies, sfVector2f pos)
{
    ennemies_t *node = setup_ennemies_node(pos);

    add_ennemies_node(ennemies, node);
}

void spawn_ennem(data_t *gd)
{
    float angle = rdm_float(0, 2 * PI);
    float dist = rdm_float(500, 1000);
    if (ennem_count(gd->ennemies) < 50)
        add_ennem(gd->ennemies, (sfVector2f)
        {gd->red->pos.x + cos(angle) * dist, gd->red->pos.y + sin(angle) * dist});
}
