/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** Source code to open a window in csfml
*/

#include "open_window.h"
#include "particles.h"

void create_window(sfRenderWindow **window, int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    *window = sfRenderWindow_create(mode, "MyRpg", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

void scene_selector(sfRenderWindow *window, data_t *game_data)
{
    event_handling(window, game_data, game_data->scene_list[game_data->run_index]);
    player_move(game_data, game_data->scene_list[game_data->run_index]);
    display_scene(window, game_data,
    game_data->scene_list[game_data->run_index]);
}

void open_window(int width, int height, data_t *game_data)
{
    sfRenderWindow *window;
    particle_param_t param = setup_default_param();
    partic_arr_t *partic;

    // param.resistance = (sfVector2f) {0.01, 0.1};
    // param.rdm_vel = (sfVector2f) {5, 1};
    // param.gravity = (sfVector2f) {0, 0.5};
    // param.init_vel = (sfVector2f) {-10, 0};
    partic = setup_partic_arr(1500, &param);
    game_data->settings = malloc(sizeof(set_t));
    game_data->settings->window_x = width;
    game_data->settings->window_y = height;
    create_window(&window, width, height);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        scene_selector(window, game_data);
        if (game_data->run_index == -1) {
            sfRenderWindow_close(window);
            break;
        }
        if (partic != NULL) {
            draw_partic_arr(window, partic);
            update_partic_arr(partic);
        }
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
