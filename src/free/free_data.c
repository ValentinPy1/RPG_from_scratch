/*
** EPITECH PROJECT, 2022
** free_data
** File description:
** Source code to free all data
*/

#include "free_data.h"

void free_text(sfText **texts)
{
    if (texts == NULL)
        return;
    for (int index = 0; texts[index] != NULL; index++)
            sfText_destroy(texts[index]);
    free(texts);
}

void free_background(scene_t *scene)
{
    if (scene->background_to_run == 1) {
    }
    if (scene->background_to_run == 2) {
        sfTexture_destroy(scene->background_texture);
        sfSprite_destroy(scene->background_sprite);
    }
}

void free_scenes(scene_t **scene_list, char **scene_names)
{
    for (int index = 0; scene_list[index] != NULL; index++) {
        free_buttons(scene_list[index]->buttons);
        free_entities(scene_list[index]->entities);
        free_text(scene_list[index]->texts);
        free_images(scene_list[index]->images);
        free_background(scene_list[index]);
        if (scene_list[index]->music != NULL) {
            sfSound_stop(scene_list[index]->music);
            sfSound_destroy(scene_list[index]->music);
            sfSoundBuffer_destroy(scene_list[index]->sound_buffer);
        }
        free(scene_list[index]->name);
        free(scene_names[index]);
        free(scene_list[index]);
    }
    free(scene_names);
    free(scene_list);
}

static void free_player(data_t *game_data)
{
    sfClock_destroy(game_data->red->clock);
    free(game_data->red->player_rect);
    sfView_destroy(game_data->red->view);
    free(game_data->red->stats);
    free(game_data->red);
}

void free_data(data_t *game_data)
{
    free_scenes(game_data->scene_list, game_data->scene_names);
    free_player(game_data);
    free(game_data->keys);
    free(game_data);
}
