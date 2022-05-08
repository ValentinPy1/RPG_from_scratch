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
    sfVector2f position_txt = (sfVector2f) {game_data->red->pos.x,
                                                game_data->red->pos.y};
    sfText_setPosition(tmp_ent->dialogue, position_txt);
    sfRenderWindow_drawText(game_data->window, tmp_ent->dialogue, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->quest->sprite, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->quit->sprite, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->back_sprite, NULL);
    // sfRenderWindow_  // sfRenderWindow_drawSprite(game_data->window, tmp_ent->quest->sprite, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->quit->sprite, NULL);
    // sfRenderWindow_drawSprite(game_data->window, tmp_ent->back_sprite, NULL);
    // sfRenderWindow_drawText(game_data->widrawText(game_data->window, tmp_ent->dialogue, NULL);
}