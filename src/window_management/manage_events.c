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
    
    //TO DO EVENT
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased) {
            manage_buttons(game_data, scene->buttons, mouse_loc);
        }
    }
}
