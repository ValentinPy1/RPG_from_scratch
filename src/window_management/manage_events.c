/*
** EPITECH PROJECT, 2021
** manage_event
** File description:
** Source code to manage event
*/

#include "event_management.h"
#include "movement.h"
#include <stdlib.h>
#include <math.h>

float get_distance(sfVector2f p1, sfVector2f p2);

void kbd_input(data_t *gd, scene_t *scene, sfEvent event, sfVector2i mouse_loc)
{
    if (event.key.code == sfKeyY)
        add_enem(gd->enemies, (sfVector2f) {(float) mouse_loc.x / 1920 *
        VIEW_WIDTH + gd->red->pos.x - VIEW_WIDTH / 2, (float) mouse_loc.y /
        1080 * VIEW_HEIGHT + gd->red->pos.y - VIEW_HEIGHT / 2});
    if (event.key.code == sfKeyK)
        if (gd->enemies->next != NULL)
            destroy_next_enemies(gd->enemies);
}

static void init_hud(sfRenderWindow *window, data_t *game_data)
{
    sfFloatRect view_rect = {0, 0, 1920, 1080};
    sfVector2f center_player_cam = {0, 0};

    sfView_reset(game_data->red->view, view_rect);
    sfRenderWindow_setView(window, game_data->red->view);
}

static void push_enemies(data_t *gd)
{
    enemies_t *tmp;
    sfVector2f ppos;
    sfVector2f epos;

    if (sfMouse_isButtonPressed(sfMouseRight)) {
        tmp = gd->enemies->next;
        ppos = gd->red->pos;
        while (tmp != NULL) {
            epos = tmp->enem.pos;
            if (get_distance(epos, ppos) < 60) {
                tmp->enem.kb_speed = 10;
                tmp->enem.kb_dir = atan2((ppos.y - epos.y), (ppos.x - epos.x)) + PI;
                tmp->enem.life -= 34; // TODO stat player
                spawn_enem_blood(gd, tmp->enem.pos);
            }
            tmp = tmp->next;
        }
    }
}

void event_handling(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    sfEvent event;
    sfVector2i mouse_loc = sfMouse_getPositionRenderWindow(window);

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
            push_enemies(game_data);
        }
        if (event.type == sfEvtKeyPressed) {
            kbd_input(game_data, scene, event, mouse_loc);
        }
    }
}
