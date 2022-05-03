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

float normalize(float dist, float max_speed)
{
    if (dist >= max_speed)
        return max_speed;
    return dist;
}

float get_distance(sfVector2f p1, sfVector2f p2)
{
    float distx = p2.x - p1.x;
    float disty = p2.y - p1.y;

    return sqrt(pow(distx, 2) + pow(disty, 2));
}

sfVector2f get_direction(sfVector2f p1, sfVector2f p2)
{
    int x = p2.x - p1.x;
    int y = p2.y - p1.y;

    return (sfVector2f) {x, y};
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