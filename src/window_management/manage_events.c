/*
** EPITECH PROJECT, 2021
** manage_event
** File description:
** Source code to manage event
*/
#include "event_management.h"
#include "particles.h"

void event_handling(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    sfEvent event;
    sfVector2i mouse_loc;
    partic_ll_t *node;
    particle_param_t param = setup_fire_param();

    mouse_loc = sfMouse_getPositionRenderWindow(window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        manage_hover_buttons(game_data, scene->buttons, mouse_loc);
        if (event.type == sfEvtMouseButtonReleased) {
            manage_clic_buttons(game_data, scene->buttons, mouse_loc);
            param.pos = (sfVector2f) {game_data->red->pos.x,
            game_data->red->pos.y - 10};
            param.init_vel.x = (mouse_loc.x - 980) / 50;
            param.init_vel.y = (mouse_loc.y - 540) / 50;
            node = setup_partic_node(&param);
            add_partic_group(game_data->partic, node);
        }
    }
}
