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
    #include "structures.h"

scene_t **get_scenes(void);

void open_window(int width, int height, scene_t **scene_list);

#endif /*MAIN_H_*/
