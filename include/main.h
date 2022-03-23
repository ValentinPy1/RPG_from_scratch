/*
** EPITECH PROJECT, 2022
** main
** File description:
** Header
*/

#ifndef MAIN_H_
    #define MAIN_H_
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include "structures.h"

scene_t **get_scenes(void);

int my_putstr(char const *str);

void open_window(int width, int height, data_t *game_data);

char **get_names_scene(scene_t **scene_list);

int get_run_index(char **scene_names, char *name);

#endif /*MAIN_H_*/
