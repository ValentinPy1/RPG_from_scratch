/*
** EPITECH PROJECT, 2022
** init_hitbox
** File description:
** Source code to initalize an hitbox
*/
#include "init_hitbox.h"

int init_hitbox(hitbox_t *hitbox)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f size = {hitbox->width, hitbox->height};
    sfVector2f origin = (sfVector2f) {hitbox->width / 2,
                                        hitbox->height / 2};

    sfRectangleShape_setPosition(rectangle, hitbox->position);
    sfRectangleShape_setRotation(rectangle, hitbox->rotation);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setOutlineColor(rectangle, sfGreen);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRectangleShape_setOrigin(rectangle, origin);
    hitbox->rectangle = rectangle;
    load_vertices(hitbox);
    
    return (0);
}