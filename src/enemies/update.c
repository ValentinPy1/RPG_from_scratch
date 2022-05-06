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

void enemy_hover(enem_t *enem, sfVector2f intent)
{
    enem->time = sfClock_getElapsedTime(enem->anim);
    enem->seconds = enem->time.microseconds / MSEC;
    if (fabs(intent.x) > 20)
        if (intent.x < 0)
            sfSprite_setScale(enem->sprite, (sfVector2f) {1, 1});
        else
            sfSprite_setScale(enem->sprite, (sfVector2f) {-1, 1});
    if (enem->seconds > 0.20) {
        move_rect(enem->rect, 32, 128);
        sfClock_restart(enem->anim);
    }
    sfSprite_setTextureRect(enem->sprite, *enem->rect);
}

void enemy_move(data_t *gd, enemies_t *node)
{
    sfVector2f enem_pos = {node->enem->pos.x, node->enem->pos.y};
    sfVector2f intent = calculate_intent(gd, node);
    float angle = atan2(intent.y, intent.x);
    float dist = get_distance((sfVector2f) {0, 0}, intent);
    float speed = normalize(dist, node->enem->speed);
    sfVector2f move = {speed * cos(angle), speed * sin(angle)};
    float delta = 60.0 / gd->framerate;

    enem_pos.x += node->enem->kb_speed * cos(node->enem->kb_dir) * delta;
    enem_pos.y += node->enem->kb_speed * sin(node->enem->kb_dir) * delta;
    node->enem->kb_speed *= 0.9;
    node->enem->pos = (sfVector2f) {enem_pos.x + move.x * delta,
    enem_pos.y + move.y * delta};
    sfSprite_setPosition(node->enem->sprite, node->enem->pos);
    enemy_hover(node->enem, intent);
}

void enemy_attack(data_t *gd, enemies_t *node)
{
    sfVector2f ppos = gd->red->pos;
    sfVector2f epos = node->enem->pos;

    if (node->enem->last_attack < gd->frame_count -
    ENEM_ATTACK_DELAY * gd->framerate &&
    get_distance(node->enem->pos, gd->red->pos) < ENEM_ATTACK_DIST) {
        gd->red->kb_speed = 5 + gd->red->percentage / 10;
        gd->red->kb_dir = atan2((ppos.y - epos.y), (ppos.x - epos.x));
        spawn_blood(gd);
        gd->red->percentage += 5;
        node->enem->last_attack = gd->frame_count;
    }
}

void update_enem_node(data_t *gd, enemies_t *node)
{
    enemy_move(gd, node);
    enemy_attack(gd, node);
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
