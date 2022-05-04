/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** free_obj.c
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
