/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** update.c
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
    sfVector2f ppos = {gd->red->pos.x, gd->red->pos.y - 15};
    sfVector2f dir = get_direction(epos, ppos);
    float dist = get_distance(epos, ppos);
    float target = 30;
    float spring = dist - target;
    sfVector2f intent = {dir.x * spring, dir.y * spring};
    sfVector2f tmpos;

    target = 10;
    for (ennemies_t *temp = gd->ennemies->next; temp != NULL;
    temp = temp->next) {
        tmpos = temp->ennem.pos;
        dist = get_distance(epos, tmpos);
        if (dist != 0)
            dir = get_direction(epos, tmpos);
            spring = target / (target + pow(dist, 3)) * 4000;
            intent = (sfVector2f)
            {intent.x - (tmpos.x - epos.x) * spring,
            intent.y - (tmpos.y - epos.y) * spring};
    }
    return intent;
}

// sfVector2f calculate_intent(data_t *gd, ennemies_t *node)
// {
//     sfVector2f intent = {(gd->red->pos.x - node->ennem.pos.x),
//     (gd->red->pos.y - node->ennem.pos.y - 15)};
//     float dist;
//     for (ennemies_t *temp = gd->ennemies->next; temp != NULL;
//     temp = temp->next) {
//         dist = distance(temp->ennem.pos, node->ennem.pos);
//         if (dist != 0)
//             intent = (sfVector2f)
//             {intent.x - (temp->ennem.pos.x - node->ennem.pos.x)
//             / pow(dist, 3) * 4000,
//             intent.y - (temp->ennem.pos.y - node->ennem.pos.y)
//             / pow(dist, 3) * 4000};
//     }
//     return intent;
// }

void update_ennem_node(data_t *gd, ennemies_t *node)
{
    sfVector2f ennem = {node->ennem.pos.x, node->ennem.pos.y};
    sfVector2f intent = calculate_intent(gd, node);
    float angle = atan(intent.y / intent.x);
    float dist = get_distance((sfVector2f) {0, 0}, intent);
    float speed = normalize(dist, node->ennem.speed);
    sfVector2f move = {speed * cos(angle), speed * sin(angle)};

    if (intent.x > 0) {
        node->ennem.pos = (sfVector2f) {ennem.x + move.x, ennem.y + move.y};
    } else {
        node->ennem.pos = (sfVector2f) {ennem.x - move.x, ennem.y - move.y};
    }
    sfCircleShape_setPosition(node->ennem.circle, node->ennem.pos);
}

void update_ennemies(data_t *gd, ennemies_t *ennemies)
{
    if (ennemies == NULL)
        return;
    update_ennem_node(gd, ennemies);
    update_ennemies(gd, ennemies->next);
}
