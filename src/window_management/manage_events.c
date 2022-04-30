/*
** EPITECH PROJECT, 2021
** manage_event
** File description:
** Source code to manage event
*/
#include "event_management.h"
#include "movement.h"

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
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyY) {
            add_ennem(game_data->ennemies, (sfVector2f)
            {(float) mouse_loc.x / 1920 * VIEW_WIDTH + game_data->red->pos.x - VIEW_WIDTH / 2,
            (float) mouse_loc.y / 1080 * VIEW_HEIGHT + game_data->red->pos.y - VIEW_HEIGHT / 2});
        }
    }
}
