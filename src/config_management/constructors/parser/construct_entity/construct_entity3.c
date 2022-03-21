/*
** EPITECH PROJECT, 2022
** construct_entity3
** File description:
** Source code to construct entity from a config file
*/
#include "construct_entity.h"

int sp_construct_scale(entity_t *entity, char *value)
{
    entity->scale.x = my_getnbr(value);
    entity->scale.y = my_getnbr(value);
    return (0);
}

int sp_construct_texture(entity_t *entity, char *value)
{
    sfVector2f pos = {entity->posx, entity->posy};

    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(value, NULL);
    if (entity->texture == NULL)
        return (-1);
    sfSprite_setTexture(entity->sprite, entity->texture, sfFalse);
    sfSprite_setScale(entity->sprite, entity->scale);
    sfSprite_setRotation(entity->sprite, entity->rotation);
    sfSprite_setPosition(entity->sprite, pos);
    return (0);
}

int sp_construct_sound(entity_t *entity, char *value)
{
    return (0);
}
