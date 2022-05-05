/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** update.c
*/

#include "enemies.h"
#include "structures.h"
#include "random.h"
#include <math.h>
#include <stdio.h>

sfVector2f calculate_intent(data_t *gd, enemies_t *node);
float get_distance(sfVector2f p1, sfVector2f p2);
void spawn_blood(data_t *game_data);

void update_enem_node(data_t *gd, enemies_t *node)
{
    sfVector2f enem = {node->enem->pos.x, node->enem->pos.y};
    sfVector2f intent = calculate_intent(gd, node);
    float angle = atan2(intent.y, intent.x);
    float dist = get_distance((sfVector2f) {0, 0}, intent);
    float speed = normalize(dist, node->enem->speed);
    sfVector2f move = {speed * cos(angle), speed * sin(angle)};
    sfVector2f ppos = gd->red->pos;
    sfVector2f epos = node->enem->pos;

    enem->x += node->enem->kb_speed * cos(node->enem->kb_dir);
    enem->y += node->enem->kb_speed * sin(node->enem->kb_dir);
    node->enem->kb_speed *= 0.9;
    node->enem->pos = (sfVector2f) {enem->x + move.x, enem->y + move.y};
    sfCircleShape_setPosition(node->enem->circle, node->enem->pos);
    if (get_distance(node->enem->pos, gd->red->pos) < 30) {
        gd->red->kb_speed = 10;
        gd->red->kb_dir = atan2((ppos.y - epos.y), (ppos.x - epos.x));
        spawn_blood(gd);
    }
}

void update_enemies(data_t *gd, enemies_t *enemies)
{
    enemies_t *next;

    if (enemies == NULL || enemies->next == NULL)
        return;
    next = enemies->next;
    update_enem_node(gd, next);
    if (next->enem->life <= 0 
    || get_distance(next->enem->pos, gd->red->pos) > 800) {
        destroy_next_enemies(enemies);
        return;
    }
    update_enemies(gd, next);
}
