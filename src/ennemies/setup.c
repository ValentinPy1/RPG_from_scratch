/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** setup.c
*/

#include "ennemies.h"

static ennem_t setup_ennem(sfVector2f pos)
{
    ennem_t ennem;
    sfCircleShape *circle = sfCircleShape_create();

    ennem.damage = 0;
    ennem.speed = (sfVector2f) {0, 0};
    ennem.life = 100;
    sfCircleShape_setFillColor(circle, (sfColor) {200, 0, 200, 255});
    sfCircleShape_setRadius(circle, 10);
    sfCircleShape_setOrigin(circle, (sfVector2f) {10, 10});
    sfCircleShape_setPosition(circle, pos);
    ennem.circle = circle;
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
