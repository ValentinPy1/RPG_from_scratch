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

void enemy_hover(enem_t *enem)
{
    if (enem->seconds > 0.20) {
        move_rect(enem->rect, 32, 128);
        sfClock_restart(enem->clock);
    }
    sfSprite_setTextureRect(enem->sprite, *enem->rect);
}

void update_enem_node(data_t *gd, enemies_t *node)
{
    sfVector2f enem_pos = {node->enem->pos.x, node->enem->pos.y};
    sfVector2f intent = calculate_intent(gd, node);
    float angle = atan2(intent.y, intent.x);
    float dist = get_distance((sfVector2f) {0, 0}, intent);
    float speed = normalize(dist, node->enem->speed);
    sfVector2f move = {speed * cos(angle), speed * sin(angle)};

    enem_pos.x += node->enem->kb_speed * cos(node->enem->kb_dir);
    enem_pos.y += node->enem->kb_speed * sin(node->enem->kb_dir);
    node->enem->kb_speed *= 0.9;
    node->enem->pos = (sfVector2f) {enem_pos.x + move.x, enem_pos.y + move.y};
    sfSprite_setPosition(node->enem->sprite, node->enem->pos);
    node->enem->time = sfClock_getElapsedTime(node->enem->clock);
    node->enem->seconds = node->enem->time.microseconds / 1000000.0;
    enemy_hover(node->enem);
}

void update_enemies(data_t *gd, enemies_t *enemies)
{
    if (enemies == NULL || enemies->next == NULL)
        return;
    update_enem_node(gd, enemies->next);
    if (enemies->next->enem->life <= 0 ||
    get_distance(enemies->next->enem->pos, gd->red->pos) > 1500)
        destroy_next_enemies(enemies);
    update_enemies(gd, enemies->next);
}
