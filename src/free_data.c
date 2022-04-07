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
    sfRectangleShape_destroy(hitbox->rectangle);
    free(hitbox->vertices);
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
        free_str_tab(entities[index]->dialogue);
        free(entities[index]);
    }
    free(entities);
}

void free_text(sfText **texts)
{
    printf("DEBUG\n");
    if (texts == NULL)
        printf("LIST NULL\n");
    else 
        printf("LIST PAS NULL\n");
    for (int index = 0; texts[index] != NULL; index++) {
        sfText_destroy(texts[index]);
    } 
}

void free_scenes(scene_t **scene_list, char **scene_names)
{
    for (int index = 0; scene_list[index] != NULL; index++) {
        free_buttons(scene_list[index]->buttons);
        free_entities(scene_list[index]->entities);
        // free_text(scene_list[index]->texts);
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