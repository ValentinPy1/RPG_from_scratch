/*
** EPITECH PROJECT, 2021
** manage_event
** File description:
** Source code to manage event
*/
#include "event_management.h"

static void init_hud(sfRenderWindow *window, data_t *game_data)
{
    sfFloatRect view_rect = {0, 0, 1920, 1080};
    sfVector2f center_player_cam = {0, 0};

    sfView_reset(game_data->red->view, view_rect);
    sfRenderWindow_setView(window, game_data->red->view);
}

void event_handling(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    sfEvent event;
    sfVector2i mouse_loc;

    mouse_loc = sfMouse_getPositionRenderWindow(window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape) {
            options(game_data, game_data->scene_names, &game_data->run_index);
            init_hud(game_data->window, game_data);
        }
        manage_hover_buttons(game_data, scene->buttons, mouse_loc);
        if (event.type == sfEvtMouseButtonReleased) {
            manage_clic_buttons(game_data, scene->buttons, mouse_loc);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            spawn_blood(game_data, mouse_loc);
        }
    }
}
