/*
** EPITECH PROJECT, 2021
** manage_event
** File description:
** Source code to manage event
*/
#include "event_management.h"

void event_handling(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    sfEvent event;
    sfVector2i mouse_loc;

    mouse_loc = sfMouse_getPositionRenderWindow(window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        manage_hover_buttons(game_data, scene->buttons, mouse_loc);
        if (event.type == sfEvtMouseButtonReleased) {
            manage_clic_buttons(game_data, scene->buttons, mouse_loc);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            spawn_blood(game_data, mouse_loc);
        }
    }
}
