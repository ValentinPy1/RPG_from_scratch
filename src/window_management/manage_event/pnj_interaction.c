/*
** EPITECH PROJECT, 2022
** pnj_interaction
** File description:
** SOurce code of pnj_interaction
*/

#include "structures.h"

void interact_pnj(data_t *game_data, scene_t *scene, entity_t *tmp_ent)
{
    if (tmp_ent->is_interact == 0) {
        sfSound_play(tmp_ent->action_sound);
        tmp_ent->is_interact = 1;  
    }
}