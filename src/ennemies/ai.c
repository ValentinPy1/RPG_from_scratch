/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ai.c
*/

#include "ennemies.h"
#include "structures.h"
#include "random.h"
#include <math.h>
#include <stdio.h>

sfVector2f handle_dest(ennemies_t *node)
{
    float angle = rdm_float(0, 2 * PI);
    float dist = rdm_float(100, 200);

    if (get_distance(node->ennem.pos, node->ennem.destination) < 1) {
        node->ennem.destination = (sfVector2f) {node->ennem.pos.x +
        cos(angle) * dist, node->ennem.pos.y + sin(angle) * dist};
        return (sfVector2f) {0, 0};
    }
    return (sfVector2f) {node->ennem.destination.x - node->ennem.pos.x,
    node->ennem.destination.y - node->ennem.pos.y};
}

sfVector2f calculate_intent(data_t *gd, ennemies_t *node)
{
    sfVector2f epos = node->ennem.pos;
    sfVector2f ppos = {gd->red->pos.x, gd->red->pos.y};
    sfVector2f dir = get_direction(epos, ppos);
    float dist = get_distance(epos, ppos);
    float target = 30;
    float spring = dist < 150 ? (dist - target) : 0;
    sfVector2f intent = {dir.x * spring, dir.y * spring};
    sfVector2f tmpos;

    dir = handle_dest(node);
    dist = get_distance(dir, (sfVector2f) {0, 0});
    spring = dist / 100;
    intent = (sfVector2f) {intent.x + dir.x * spring, intent.y + dir.y * spring};
    target = 100;
    for (ennemies_t *temp = gd->ennemies->next; temp != NULL;
    temp = temp->next) {
        tmpos = temp->ennem.pos;
        dist = get_distance(epos, tmpos);
        if (dist != 0 && dist < 20) {
            dir = get_direction(epos, tmpos);
            spring = target / (target + pow(dist, 3)) * 4000;
            intent = (sfVector2f)
            {intent.x - (tmpos.x - epos.x) * spring,
            intent.y - (tmpos.y - epos.y) * spring};
        }
    }
    return (sfVector2f) {intent.x, intent.y};
}