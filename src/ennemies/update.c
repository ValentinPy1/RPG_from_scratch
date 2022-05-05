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
    float angle = atan2(intent.y, intent.x);
    float dist = get_distance((sfVector2f) {0, 0}, intent);
    float speed = normalize(dist, node->ennem.speed);
    sfVector2f move = {speed * cos(angle), speed * sin(angle)};

    ennem.x += node->ennem.kb_speed * cos(node->ennem.kb_dir);
    ennem.y += node->ennem.kb_speed * sin(node->ennem.kb_dir);
    node->ennem.kb_speed *= 0.9;
    node->ennem.pos = (sfVector2f) {ennem.x + move.x, ennem.y + move.y};
    sfSprite_setPosition(node->ennem.sprite, node->ennem.pos);
}

void update_ennemies(data_t *gd, ennemies_t *ennemies)
{
    if (ennemies == NULL || ennemies->next == NULL)
        return;
    update_ennem_node(gd, ennemies->next);
    if (ennemies->next->ennem.life <= 0 ||
    get_distance(ennemies->next->ennem.pos, gd->red->pos) > 1500)
        destroy_next_ennemies(ennemies);
    update_ennemies(gd, ennemies->next);
}
