/*
** EPITECH PROJECT, 2022
** manage_buttons
** File description:
** Source code to manage buttons
*/

#include "manage_buttons.h"

void exec_button_clicked(data_t *game_data, button_t **buttons, int index)
{
    if (game_data->scene_list[game_data->run_index]->music != NULL)
        sfSound_stop(game_data->scene_list[game_data->run_index]->music);
    sfSound_play(buttons[index]->sound);
    (*buttons[index]->callback)(buttons[index], game_data->scene_names,
    &(game_data->run_index));
    if (game_data->run_index == -1)
        return;
    if (game_data->scene_list[game_data->run_index]->music != NULL)
        sfSound_play(game_data->scene_list[game_data->run_index]->music);
}

void manage_clic_buttons(data_t *game_data, button_t **buttons,
sfVector2i mouse_loc)
{
    for (int index = 0; buttons[index] != NULL; index++) {
        if (button_collision(mouse_loc, buttons[index]) == 1) {
            exec_button_clicked(game_data, buttons, index);
        }
    }
}

void manage_hover_buttons(data_t *game_data, button_t **buttons,
sfVector2i mouse_loc)
{
    for (int index = 0; buttons[index] != NULL; index++) {
        if (button_collision(mouse_loc, buttons[index]) == 1)
            buttons[index]->is_hovered = 1;
        else
            buttons[index]->is_hovered = 0;
    }
}