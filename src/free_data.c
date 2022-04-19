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
        sfCircleShape_destroy(hitbox->circle[index]);
    }
    sfRectangleShape_destroy(hitbox->rectangle);
    free(hitbox->vertices);
    free(hitbox->circle);
    free(hitbox);
}

void free_buttons(button_t **buttons)
{
    for (int index = 0; buttons[index] != NULL; index++) {
        free_hitbox(buttons[index]->hitbox);
        sfTexture_destroy(buttons[index]->texture);
        sfTexture_destroy(buttons[index]->ho_texture);
        sfSprite_destroy(buttons[index]->sprite);
        sfSprite_destroy(buttons[index]->ho_sprite);
        sfSound_stop(buttons[index]->sound);
        sfSound_destroy(buttons[index]->sound);
        sfSoundBuffer_destroy(buttons[index]->sound_buffer);
        free(buttons[index]);
    }
    free(buttons);
}

void free_entities(entity_t **entities)
{
    for (int index = 0; entities[index] != NULL; index++) {
        free_hitbox(entities[index]->hitbox);
        sfTexture_destroy(entities[index]->texture);
        sfSprite_destroy(entities[index]->sprite);
        sfSound_destroy(entities[index]->sound);
        sfSoundBuffer_destroy(entities[index]->sound_buffer);
        free(entities[index]->dialogue);
        free(entities[index]);
    }
    free(entities);
}

void free_images(image_t **images)
{
    for (int index = 0; images[index] != NULL; index++) {
        sfTexture_destroy(images[index]->texture);
        sfSprite_destroy(images[index]->sprite);
        free(images[index]);
    }
    free(images);
}

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
        free_int_tab(scene->map->tiles);
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

void free_data(data_t *game_data)
{
    free_scenes(game_data->scene_list, game_data->scene_names);
    free(game_data->settings);
    free(game_data);
}
