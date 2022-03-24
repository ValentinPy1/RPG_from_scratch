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
    event_handling(window, game_data->scene_list[game_data->run_index]);
    display_scene(window, game_data->scene_list[game_data->run_index]);
}

void open_window(int width, int height, data_t *game_data)
{
    sfRenderWindow *window;

    create_window(&window, width, height);
        sfVector2f new = {0, game_data->scene_list[2]->buttons[0]->position.y};
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        scene_selector(window, game_data);
        if (game_data->run_index == -1) {
            sfRenderWindow_close(window);
            break;
        }
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            game_data->scene_list[2]->buttons[0]->hitbox->width += 0.5;
            printf("scale.x : %3f\n", game_data->scene_list[2]->buttons[0]->hitbox->width);
            new.x = game_data->scene_list[2]->buttons[0]->position.x + game_data->scene_list[2]->buttons[0]->hitbox->width / 2;
            sfSprite_setPosition(game_data->scene_list[2]->buttons[0]->sprite, new);
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            game_data->scene_list[2]->buttons[0]->hitbox->width -= 0.5;
            printf("scale.x : %3f\n", game_data->scene_list[2]->buttons[0]->hitbox->width);
            new.x = game_data->scene_list[2]->buttons[0]->position.x + game_data->scene_list[2]->buttons[0]->hitbox->width / 2;
            sfSprite_setPosition(game_data->scene_list[2]->buttons[0]->sprite, new);
        }
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
