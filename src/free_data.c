/*
** EPITECH PROJECT, 2022
** free_data
** File description:
** Source code to free all data
*/

#include "free_data.h"

void free_hitbox(hitbox_t *hitbox)
{
    for (int index = 0; hitbox->vertices[index] != NULL; index++) {
        free(hitbox->vertices[index]);
    }
    free(hitbox->vertices);
    free(hitbox);
}

void free_buttons(button_t **buttons)
{
    for (int index = 0; buttons[index] != NULL; index++) {
        free_hitbox(buttons[index]->hitbox);
        free(buttons[index]);
        // free(buttons[index]->texture);
        // free(buttons[index]->ho_texture);
    }
    free(buttons);
}

void free_entities(entity_t **entities)
{
    for (int index = 0; entities[index] != NULL; index++) {
        free_hitbox(entities[index]->hitbox);
        free(entities[index]);
        // free(entities[index]->texture);
    }
    free(entities);
}

void free_scenes(scene_t **scene_list, char **scene_names)
{
    for (int index = 0; scene_list[index] != NULL; index++) {
        free_buttons(scene_list[index]->buttons);
        free_entities(scene_list[index]->entities);
        free(scene_list[index]->name);
        free(scene_names[index]);
        free(scene_list[index]);
    }
    free(scene_names);
    free(scene_list);
}

void free_data(data_t *game_data)
{
    free_scenes(game_data->scene_list, game_data->scene_names);
    free(game_data);
}