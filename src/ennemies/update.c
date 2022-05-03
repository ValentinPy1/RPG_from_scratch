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

sfVector2f calculate_intent(data_t *gd, ennemies_t *node);
float get_distance(sfVector2f p1, sfVector2f p2);

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
    } else if (intent.x < 0) {
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
