/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** quest.c
*/

#include "structures.h"

void init_quest(data_t *gd)
{
    if (gd->quest_state == 0) {
        gd->quest_state = 1;
        gd->red->kill_streak = 0;
    }
}