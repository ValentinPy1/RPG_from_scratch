/*
** EPITECH PROJECT, 2022
** button_callback.c
** File description:
** Source code of every callback
*/

#include "callbacks.h"

void quit_game(button_t *button, scene_t **scene_list, int index)
{
    int scenes;

    scene_list[index]->is_running = 0;
}

void start_game(button_t *button, scene_t **scene_list, int index)
{
    int scenes;

    scene_list[index]->is_running = 0;
    for (scenes = 0; scene_list[scenes] != NULL; scenes++) {
        if (my_strcmp(scene_list[scenes]->name, "game_menu") == 1) {
            scene_list[scenes]->zombie->pos.x = 50;
            scene_list[scenes]->zombie->pos.y = 400;
            scene_list[scenes]->is_running = 1;
        }
    }
}