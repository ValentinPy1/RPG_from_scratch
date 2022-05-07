/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** button_callback3.c
*/

#include "callbacks.h"

static void set_volumes(data_t *game_data, sfVector2i mouse_pos)
{
    int volume = 1640 - mouse_pos.x;
    int ratio = 100 - (((float)volume / 420) * 100);
    sfSound_setVolume(game_data->scene_list[0]->music, ratio);
    sfSound_setVolume(game_data->scene_list[1]->music, ratio);
    sfSound_setVolume(game_data->scene_list[2]->music, ratio);
    sfSound_setVolume(game_data->red->kill, ratio);
}

int bar(data_t *game_data, char **scenes_name, int *index_run)
{
    sfVector2i mouse_pos = sfMouse_getPosition(game_data->window);
    game_data->scene_list[2]->buttons[8]->position.x = mouse_pos.x;
    game_data->scene_list[2]->buttons[8]->hitbox->position.x = mouse_pos.x;
    sfSprite_setPosition(game_data->scene_list[2]->buttons[8]->ho_sprite,
    game_data->scene_list[2]->buttons[8]->position);
    sfSprite_setPosition(game_data->scene_list[2]->buttons[8]->sprite,
    game_data->scene_list[2]->buttons[8]->position);
    sfRectangleShape_setPosition(game_data->scene_list[2]->buttons[8]
    ->hitbox->rectangle, game_data->scene_list[2]->buttons[8]->position);
    load_vertices(game_data->scene_list[2]->buttons[8]->hitbox);
    set_volumes(game_data, mouse_pos);
}

int update_att(data_t *game_data, char **scenes_name, int *index_run)
{
    game_data->red->stats->att += 1;
}

int update_def(data_t *game_data, char **scenes_name, int *index_run)
{
    game_data->red->stats->def += 1;
}

int update_spd(data_t *game_data, char **scenes_name, int *index_run)
{
    game_data->red->stats->spd += 1;
}
