/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Source code to construct a button
*/
#include "construct_button.h"

int construct_scale(button_t *button, char *value)
{
    button->scale.x = my_getnbr(value);
    button->scale.y = my_getnbr(value);
    return (0);
}

int construct_texture(button_t *button, char *value)
{
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(value, NULL);
    if (button->texture == NULL)
        return (-1);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setScale(button->sprite, button->scale);
    sfSprite_setRotation(button->sprite, button->rotation);
    sfSprite_setPosition(button->sprite, button->position);
    return (0);
}

int construct_ho_texture(button_t *button, char *value)
{
    button->ho_sprite = sfSprite_create();
    button->ho_texture = sfTexture_createFromFile(value, NULL);
    if (button->ho_texture == NULL)
        return (-1);
    sfSprite_setTexture(button->ho_sprite, button->ho_texture, sfFalse);
    sfSprite_setScale(button->ho_sprite, button->scale);
    sfSprite_setRotation(button->ho_sprite, button->rotation);
    sfSprite_setPosition(button->ho_sprite, button->position);
    return (0);
}

int construct_sound(button_t *button, char *value)
{
    sfSoundBuffer *sound_buffer = sfSoundBuffer_createFromFile(value);
    sfSound *sound = sfSound_create();

    if (sound_buffer == NULL)
        return (-1);
    sfSound_setBuffer(sound, sound_buffer);
    button->sound = sound;
    button->sound_buffer = sound_buffer;
    return (0);
}

int construct_callback(button_t *button, char *value)
{
    for (int index = 0; BUT_CALL[index].name != NULL; index++) {
        if (my_strcmp(BUT_CALL[index].name, value) == 1) {
            button->callback = BUT_CALL[index].func;
            return (0);
        }
    }
    write_error("Unable to find :");
    write_error(value);
    write_error("\n");
    return (-1);
}
