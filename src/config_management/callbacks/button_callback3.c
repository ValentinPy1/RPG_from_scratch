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
}

int volume_bar(data_t *game_data, char **scenes_name, int *index_run)
{
    (void) scenes_name;
    (void) index_run;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game_data->window);

    button_t *volume_bar = get_button(game_data->scene_list[2]->buttons, "volume_bar");
    
    volume_bar->position.x = mouse_pos.x;
    volume_bar->hitbox->position.x = mouse_pos.x;
    sfSprite_setPosition(volume_bar->ho_sprite, volume_bar->position);
    sfSprite_setPosition(volume_bar->sprite, volume_bar->position);
    sfRectangleShape_setPosition(volume_bar->hitbox->rectangle,
                                    volume_bar->position);
    load_vertices(volume_bar->hitbox);
    set_volumes(game_data, mouse_pos);
    return (0);
}
