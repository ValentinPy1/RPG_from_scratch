/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** Source code to open a window in csfml
*/

#include "open_window.h"

void create_window(sfRenderWindow **window, int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    *window = sfRenderWindow_create(mode, "MyRpg", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

void scene_selector(sfRenderWindow *window, data_t *game_data)
{
    event_handling(window, game_data, game_data->scene_list[game_data->run_index]);
    if (game_data->run_index == -1)
        return;
    player_move(game_data, game_data->scene_list[game_data->run_index]);
    display_scene(window, game_data,
    game_data->scene_list[game_data->run_index]);
    int bool = is_blocking_tile(
    game_data->scene_list[game_data->run_index]->map,  game_data->red->pos);
}

void open_window(int width, int height, data_t *game_data)
{
    sfRenderWindow *window;

    create_window(&window, width, height);
    sfSound_play(game_data->scene_list[game_data->run_index]->music);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        scene_selector(window, game_data);
        if (game_data->run_index == -1) {
            sfRenderWindow_close(window);
            break;
        }
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
