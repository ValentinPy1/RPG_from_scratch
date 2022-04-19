/*
** EPITECH PROJECT, 2022
** manage_buttons
** File description:
** Header
*/

#ifndef MBUT_H_
    #define MBUT_H_
    #include <stddef.h>
    #include "structures.h"

void manage_hover_buttons(data_t *game_data, button_t **buttons, sfVector2i mouse_loc);
void manage_clic_buttons(data_t *game_data, button_t **buttons, sfVector2i mouse_loc);
#endif /*MBUT_H_*/