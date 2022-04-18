/*
** EPITECH PROJECT, 2021
** manage_event
** File description:
** Source code to manage event
*/
#include "event_management.h"

void event_handling(sfRenderWindow *window, scene_t *scene, char **scene_name,
int *index_run)
{
    sfEvent event;
    sfVector2i mouse_loc;

    mouse_loc = sfMouse_getPositionRenderWindow(window);
    //TO DO EVENT
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased) {
            printf("Clic released at: (%i, %i)\n", mouse_loc.x, mouse_loc.y);
            button_collision(mouse_loc, scene->buttons);
        }
    }
}
