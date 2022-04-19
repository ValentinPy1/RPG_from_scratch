/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Source code to construct a button
*/
#include "construct_button.h"

int but_construct_scale(button_t *button, char *value)
{
    sfVector2f scale = (sfVector2f) {my_atof(value), my_atof(value)};

    button->scale = scale;
    button->hitbox->width *= scale.x;
    button->hitbox->height *= scale.y;
    return (0);
}

int but_construct_texture(button_t *button, char *value)
{
    sfVector2f origin = (sfVector2f)
    {button->hitbox->width / (2 * button->scale.x),
    button->hitbox->height / (2 * button->scale.y)};

    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(value, NULL);
    if (button->texture == NULL) {
        write_error("Enable to load texture:");
        write_error(value);
        write_error(".\n");
        return (-1);
    }
    sfSprite_setRotation(button->sprite, button->rotation);
    sfSprite_setScale(button->sprite, button->scale);
    sfSprite_setOrigin(button->sprite, origin);
    sfSprite_setPosition(button->sprite, button->position);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    return (0);
}

int but_construct_ho_texture(button_t *button, char *value)
{
    sfVector2f origin = (sfVector2f)
    {button->hitbox->width / (2 * button->scale.x),
    button->hitbox->height / (2 * button->scale.y)};

    button->ho_sprite = sfSprite_create();
    button->ho_texture = sfTexture_createFromFile(value, NULL);
    if (button->ho_texture == NULL) {
        write_error("Enable to load hovered texture:\"");
        write_error(value);
        write_error("\".\n");
        return (-1);
    }
    sfSprite_setTexture(button->ho_sprite, button->ho_texture, sfFalse);
    sfSprite_setScale(button->ho_sprite, button->scale);
    sfSprite_setOrigin(button->ho_sprite, origin);
    sfSprite_setRotation(button->ho_sprite, button->rotation);
    sfSprite_setPosition(button->ho_sprite, button->position);
    return (0);
}

int but_construct_sound(button_t *button, char *value)
{
    sfSoundBuffer *sound_buffer = sfSoundBuffer_createFromFile(value);
    sfSound *sound = sfSound_create();

    if (sound_buffer == NULL) {
        write_error("Enable to load sound:\"");
        write_error(value);
        write_error("\".\n");
        return (-1);
    }
    sfSound_setBuffer(sound, sound_buffer);
    button->sound = sound;
    button->sound_buffer = sound_buffer;
    return (0);
}

int but_construct_sel_texture(button_t *button, char *value)
{
    sfVector2f origin = (sfVector2f)
    {button->hitbox->width / (2 * button->scale.x),
    button->hitbox->height / (2 * button->scale.y)};

    button->sel_sprite = sfSprite_create();
    button->sel_texture = sfTexture_createFromFile(value, NULL);
    if (button->sel_texture == NULL) {
        write_error("Enable to load selected texture:\"");
        write_error(value);
        write_error("\".\n");
        return (-1);
    }
    sfSprite_setTexture(button->sel_sprite, button->sel_texture, sfFalse);
    sfSprite_setScale(button->sel_sprite, button->scale);
    sfSprite_setOrigin(button->sel_sprite, origin);
    sfSprite_setRotation(button->sel_sprite, button->rotation);
    sfSprite_setPosition(button->sel_sprite, button->position);
    return (0);
}