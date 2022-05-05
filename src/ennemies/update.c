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
void spawn_blood(data_t *game_data);

void update_ennem_node(data_t *gd, ennemies_t *node)
{
    sfVector2f ennem = {node->ennem.pos.x, node->ennem.pos.y};
    sfVector2f intent = calculate_intent(gd, node);
    float angle = atan2(intent.y, intent.x);
    float dist = get_distance((sfVector2f) {0, 0}, intent);
    float speed = normalize(dist, node->ennem.speed);
    sfVector2f move = {speed * cos(angle), speed * sin(angle)};
    sfVector2f ppos = gd->red->pos;
    sfVector2f epos = node->ennem.pos;

    ennem.x += node->ennem.kb_speed * cos(node->ennem.kb_dir);
    ennem.y += node->ennem.kb_speed * sin(node->ennem.kb_dir);
    node->ennem.kb_speed *= 0.9;
    node->ennem.pos = (sfVector2f) {ennem.x + move.x, ennem.y + move.y};
    sfCircleShape_setPosition(node->ennem.circle, node->ennem.pos);
    if (get_distance(node->ennem.pos, gd->red->pos) < 30) {
        gd->red->kb_speed = 10;
        gd->red->kb_dir = atan2((ppos.y - epos.y), (ppos.x - epos.x));
        spawn_blood(gd);
    }
}

void update_ennemies(data_t *gd, ennemies_t *ennemies)
{
    ennemies_t *next;

    if (ennemies == NULL || ennemies->next == NULL)
        return;
    next = ennemies->next;
    update_ennem_node(gd, next);
    if (next->ennem.life <= 0 
    || get_distance(next->ennem.pos, gd->red->pos) > 800) {
        destroy_next_ennemies(ennemies);
        return;
    }
    update_ennemies(gd, next);
}
