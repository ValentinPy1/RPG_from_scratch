/*
** EPITECH PROJECT, 2022
** event_management
** File description:
** Header
*/

#ifndef EVMAN_H_
    #define EVMAN_H_
    #include <stddef.h>
    #include <unistd.h>
    #include "structures.h"

void button_collision(sfVector2i mouse_loc, button_t **buttons);
void manage_hover_buttons(data_t *game_data, button_t **buttons,
sfVector2i mouse_loc);
void manage_clic_buttons(data_t *game_data, button_t **buttons,
sfVector2i mouse_loc);

#endif /*MAIN_H_*/
