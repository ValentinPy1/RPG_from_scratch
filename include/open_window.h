/*
** EPITECH PROJECT, 2022
** open_window
** File description:
** Header
*/

#ifndef WIN_H_
    #define WIN_H_
    #include "structures.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

void check_button_state(button_t **buttons, sfVector2i mouse_loc);

void check_button_clicked(scene_t **scene_list, sfVector2i mouse_loc, int index);

void display_scene(sfRenderWindow *window, scene_t *scene);

#endif /*WIN_H_*/