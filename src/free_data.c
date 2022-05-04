/*
** EPITECH PROJECT, 2022
** free_data
** File description:
** Source code to free all data
*/

#include "free_data.h"

void free_scenes(scene_t **scene_list, char **scene_names)
{
    if (scene_list == NULL)
        return;
    for (int index = 0; scene_list[index] != NULL; index++)
        free(scene_list[index]);
    free(scene_list);
}

void free_data(data_t *game_data)
{
    if (game_data == NULL)
        return;
    printf("DEBUG\n");
    free_scenes(game_data->scene_list, game_data->scene_names);
    free(game_data);
}
