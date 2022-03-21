/*
** EPITECH PROJECT, 2022
** construct_entity2
** File description:
** Source code to construct entity from a config file
*/
#include "construct_entity.h"

int sp_construct_posx(entity_t *entity, char *value)
{
    entity->posx = my_getnbr(value);
    return (0);
}

int sp_construct_posy(entity_t *entity, char *value)
{
    sfVector2i center;

    entity->posy = my_getnbr(value);
    center.x = entity->posx;
    center.y = entity->posy;
    entity->center = center;
    return (0);
}

int sp_construct_width(entity_t *entity, char *value)
{
    entity->width = my_getnbr(value);
    return (0);
}

int sp_construct_height(entity_t *entity, char *value)
{
    entity->height = my_getnbr(value);
    return (0);
}

int sp_construct_rotation(entity_t *entity, char *value)
{
    entity->rotation = my_getnbr(value);
    return (0);
}
