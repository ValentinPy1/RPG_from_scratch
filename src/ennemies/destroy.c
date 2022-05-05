/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** destroy.c
*/

#include "ennemies.h"
#include <stdlib.h>

void destroy_next_ennemies(ennemies_t *node)
{
    ennemies_t *tmp = node->next;
    node->next = node->next->next;
    sfSprite_destroy(tmp->ennem.sprite);
    free(tmp);
}
