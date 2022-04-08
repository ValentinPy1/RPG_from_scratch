/*
** EPITECH PROJECT, 2022
** construct_entities
** File description:
** Source code of entities constructor
*/
#include "construct_entity.h"

int en_construct_posx(entity_t *entity, char *value)
{
    int coord_x = my_getnbr(value);

    entity->position.x = coord_x;
    entity->hitbox->position.x = coord_x;
    return (0);
}

int en_construct_posy(entity_t *entity, char *value)
{
    int coord_y = my_getnbr(value);

    entity->position.y = coord_y;
    entity->hitbox->position.y = coord_y;
    return (0);
}

int en_construct_width(entity_t *entity, char *value)
{
    int width = my_getnbr(value);

    entity->hitbox->width = width;
    return (0);
}

int en_construct_height(entity_t *entity, char *value)
{
    int height = my_getnbr(value);
    
    entity->hitbox->height = height;
    return (0);
}

int en_construct_rotation(entity_t *entity, char *value)
{
    float rot = my_atof(value);

    entity->rotation = rot;
    entity->hitbox->rotation = rot;
    return (0);
}
