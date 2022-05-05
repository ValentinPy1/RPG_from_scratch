/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** destroy.c
*/

#include "ennemies.h"
#include <stdlib.h>
#include "structures.h"

void destroy_next_ennemies(ennemies_t *node)
{
    ennemies_t *tmp = node->next;
    node->next = node->next->next;
    sfCircleShape_destroy(tmp->ennem.circle);
    free(tmp);
}
