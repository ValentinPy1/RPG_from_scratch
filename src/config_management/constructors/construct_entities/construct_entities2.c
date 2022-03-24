/*
** EPITECH PROJECT, 2022
** construct_entities
** File description:
** Source code of entities constructor
*/
#include "construct_entity.h"

int en_construct_scale(entity_t *entity, char *value)
{
    sfVector2f scale = (sfVector2f) {my_getnbr(value), my_getnbr(value)};

    entity->scale = scale;
    entity->hitbox->width *= scale.x;
    entity->hitbox->height *= scale.y;
    return (0);
}

int en_construct_texture(entity_t *entity, char *value)
{
    sfVector2f origin = (sfVector2f)
    {entity->hitbox->width / (2 * entity->scale.x),
    entity->hitbox->height / (2 * entity->scale.y)};

    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(value, NULL);
    if (entity->texture == NULL) {
        write_error("Enable to load texture:");
        write_error(value);
        write_error(".\n");
        return (-1);
    }
    sfSprite_setRotation(entity->sprite, entity->rotation);
    sfSprite_setScale(entity->sprite, entity->scale);
    sfSprite_setOrigin(entity->sprite, origin);
    sfSprite_setPosition(entity->sprite, entity->position);
    sfSprite_setTexture(entity->sprite, entity->texture, sfFalse);
    return (0);
}

int en_construct_sound(entity_t *entity, char *value)
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
    entity->sound = sound;
    entity->sound_buffer = sound_buffer;
    return (0);
}

int en_construct_dialogue(entity_t *entity, char *value)
{
    printf("DO dialogue:%s\n", value);
    return;
}