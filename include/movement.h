/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** movement.h
*/

#ifndef _MOVEMENT_
    #define _MOVEMENT_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include "structures.h"

    #define OOB_UP game_data->scene_list[0]->map->movement_y > (game_data->settings->window_y / 2) * -1
    #define OOB_RIGHT game_data->scene_list[0]->map->movement_x < game_data->settings->window_x / 2
    #define OOB_DOWN game_data->scene_list[0]->map->movement_y < game_data->settings->window_y / 2
    #define OOB_LEFT game_data->scene_list[0]->map->movement_x > (game_data->settings->window_x / 2) * -1

#endif
