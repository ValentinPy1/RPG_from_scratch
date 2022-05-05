/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** destroy.c
*/

#include "enemies.h"
#include <stdlib.h>
#include "structures.h"

void destroy_next_enemies(enemies_t *node)
{
    enemies_t *tmp = node->next;
    node->next = node->next->next;
    sfCircleShape_destroy(tmp->enem->circle);
    free(tmp);
}
