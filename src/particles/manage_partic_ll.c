/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** manage_partic_ll.c
*/

#include "particles.h"
#include <stdlib.h>

void add_partic_group(partic_ll_t *groups, partic_ll_t *node)
{
    if (groups->next == NULL) {
        groups->next = node;
        return;
    }
    add_partic_group(groups->next, node);
}

void sup_partic_groups(partic_ll_t *groups) {
    partic_ll_t *temp;
    if (groups == NULL || groups->next == NULL) {
        return;
    }
    if (groups->next->partic_arr->duration <= 0) {
        destroy_partic_arr(groups->next->partic_arr);
        temp = groups->next;
        groups->next = groups->next->next;
        free(temp->partic_arr);
        free(temp);
        sup_partic_groups(groups);
    } else {
        sup_partic_groups(groups->next);
    }
}
