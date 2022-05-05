/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** setup.c
*/

#include "enemies.h"
#include <stdlib.h>
#include <structures.h>
#include "random.h"
#include "math.h"
#include <stdio.h>

static enem_t setup_enem(sfVector2f pos)
{
    enem_t enem;
    sfCircleShape *circle = sfCircleShape_create();

    enem.damage = 0;
    enem.speed = 1.2;
    enem.direction = 0;
    enem.life = 100;
    enem.pos = pos;
    enem.destination = pos;
    enem.kb_dir = 0;
    enem.kb_speed = 0;
    sfCircleShape_setFillColor(circle, (sfColor) {150, 0, 150, 255});
    sfCircleShape_setOutlineColor(circle, (sfColor) {0, 0, 0, 255});
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setRadius(circle, 10);
    sfCircleShape_setOrigin(circle, (sfVector2f) {10, 10});
    sfCircleShape_setPosition(circle, pos);
    enem.circle = circle;
    return enem;
}

enemies_t *setup_enemies_node(sfVector2f pos)
{
    enemies_t *enemies = malloc(sizeof(enemies_t));

    enemies->enem = setup_enem(pos);
    enemies->next = NULL;
    return enemies;
}

static void add_enemies_node(enemies_t *enemies, enemies_t *node)
{
    if (enemies->next == NULL) {
        enemies->next = node;
        return;
    }
    add_enemies_node(enemies->next, node);
}

void add_enem(enemies_t *enemies, sfVector2f pos)
{
    enemies_t *node = setup_enemies_node(pos);

    add_enemies_node(enemies, node);
}

void spawn_enem(data_t *gd)
{
    float angle = rdm_float(0, 2 * PI);
    float dist = rdm_float(500, 1000);
    if (enem_count(gd->enemies) < 50)
        add_enem(gd->enemies, (sfVector2f)
        {gd->red->pos.x + cos(angle) * dist, gd->red->pos.y + sin(angle) * dist});
}
