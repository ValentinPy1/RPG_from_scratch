/*
** EPITECH PROJECT, 2022
** free_data
** File description:
** Header
*/

#ifndef FREE_H_
    #define FREE_H_
    #include "structures.h"
    #include <stdlib.h>

void free_str_tab(char **tab);
void free_int_tab(int **tab);

void free_hitbox(hitbox_t *hitbox);
void free_buttons(button_t **buttons);
void free_entities(entity_t **entities);
void free_images(image_t **images);

#endif