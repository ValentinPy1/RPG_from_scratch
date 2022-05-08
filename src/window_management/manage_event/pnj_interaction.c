/*
** EPITECH PROJECT, 2022
** pnj_interaction
** File description:
** SOurce code of pnj_interaction
*/

#include "structures.h"

void interact_pnj(data_t *game_data, scene_t *scene, entity_t *tmp_ent)
{
    // Create an sfText in build and two button one close one accept
    // display text button maybe image
    if (tmp_ent->is_interact == 0) {
        sfSound_play(tmp_ent->action_sound);
        tmp_ent->is_interact = 1;  
    }

    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->quest->sprite, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->quit->sprite, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->back_sprite, NULL);
    // sfRenderWindow_  // sfRenderWindow_drawSprite(game_data->window, tmp_ent->quest->sprite, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->quit->sprite, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->back_sprite, NULL);
    // sfRenderWindow_drawText(game_data->widrawText(game_data->window, tmp_ent->dialogue, NULL);
}