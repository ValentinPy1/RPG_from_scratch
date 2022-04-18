/*
** EPITECH PROJECT, 2022
** manage_buttons
** File description:
** Source code to manage buttons
*/

#include "manage_buttons.h"

void manage_buttons(button_t **buttons, sfVector2i mouse_loc)
{
    for (int index = 0; buttons[index] != NULL; index++) {
        if (button_collision(mouse_loc, buttons[index]) == 1) {
            sfSound_play(buttons[index]->sound);
            // TO DO exec callback
        }
    
    }
}