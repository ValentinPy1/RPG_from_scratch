/*
** EPITECH PROJECT, 2022
** manage_buttons
** File description:
** Source code to manage buttons
*/
#include "manage_buttons.h"

void check_button_state(button_t **buttons, sfVector2i mouse_loc)
{
    for (int index = 0; buttons[index] != NULL; index++) {
        if (cursor_is_in_button(buttons[index], mouse_loc) == 1)
            buttons[index]->hitbox->is_hovered = 1;
        else
            buttons[index]->hitbox->is_hovered = 0;
    }
}

void check_button_clicked(scene_t **scene_list, sfVector2i mouse_loc,
                            int index)
{
    for (int buttons = 0; scene_list[index]->buttons[buttons] != NULL;
                buttons++) {
        if (cursor_is_in_button(scene_list[index]->buttons[buttons],
                mouse_loc) == 1) {
            sfSound_play(scene_list[index]->buttons[buttons]->sound);
            (*scene_list[index]->buttons[buttons]->callback)
                (scene_list[index]->buttons[buttons], scene_list, index);
        }
    }
}
