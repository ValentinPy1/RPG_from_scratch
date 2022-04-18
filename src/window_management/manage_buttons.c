/*
** EPITECH PROJECT, 2022
** manage_buttons
** File description:
** Source code to manage buttons
*/

#include "manage_buttons.h"

void manage_buttons(data_t *game_data, button_t **buttons, sfVector2i mouse_loc)
{
    for (int index = 0; buttons[index] != NULL; index++) {
        if (button_collision(mouse_loc, buttons[index]) == 1) {
            sfSound_play(buttons[index]->sound);
            if (buttons[index]->is_selected == 1)
                buttons[index]->is_selected = 0;
            else if (buttons[index]->is_selected == 0)
                buttons[index]->is_selected = 1;
            (*buttons[index]->callback)(buttons[index], 
                    game_data->scene_names, &(game_data->run_index));
        }
    }
}