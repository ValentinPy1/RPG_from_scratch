/*
** EPITECH PROJECT, 2022
** construct_button
** File description:
** Source code to construct a button
*/
#include "construct_button.h"

void fill_hitbox_data(hitbox_data_t *hitbox_data, sfVector2f pos,
                        sfVector2f scale, double rotation)
{
    hitbox_data->position = pos;
    hitbox_data->rotation = rotation;
    hitbox_data->scale = scale;
}

sfRectangleShape *create_shape(hitbox_data_t *hitbox_data,
                                int width, int height, int rotation)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, hitbox_data->position);
    sfRectangleShape_setRotation(rectangle, rotation);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRectangleShape_setOutlineColor(rectangle, sfGreen);
    return (rectangle);
}

sfVector2i **get_vertices(sfVector2f center, int width, int height)
{
    sfVector2i **vertices_list = malloc((4 + 1) * sizeof(sfVector2i));
    sfVector2i *vertix1 = malloc(sizeof(sfVector2i));
    sfVector2i *vertix2 = malloc(sizeof(sfVector2i));
    sfVector2i *vertix3 = malloc(sizeof(sfVector2i));
    sfVector2i *vertix4 = malloc(sizeof(sfVector2i));

    vertix1->x = center.x - width / 2;
    vertix1->y = center.y - height / 2;
    vertix2->x = center.x + width / 2;
    vertix2->y = center.y - height / 2;
    vertix3->x = center.x + width / 2;
    vertix3->y = center.y + height / 2;
    vertix4->x = center.x - width / 2;
    vertix4->y = center.y + height / 2;
    vertices_list[0] = vertix1;
    vertices_list[1] = vertix2;
    vertices_list[2] = vertix3;
    vertices_list[3] = vertix4;
    vertices_list[4] = NULL;
    return (vertices_list);
}

hitbox_t *init_hitbox(hitbox_data_t *hitbox_data, int height, int width)
{
    hitbox_t *hitbox = malloc(sizeof(hitbox_t));
    sfVector2f size = {(width * hitbox_data->scale.x),
                        (height * hitbox_data->scale.y)};

    hitbox->position = hitbox_data->position;
    hitbox->center = hitbox_data->center;
    hitbox->height = height * hitbox_data->scale.y;
    hitbox->width = width * hitbox_data->scale.x;
    hitbox->rotation = hitbox_data->rotation;
    hitbox->is_hovered = 0;
    hitbox->vertices = get_vertices(hitbox->center,
                                    hitbox->width, hitbox->height);
    hitbox->rectangle = create_shape(hitbox_data, hitbox->width,
                                    hitbox->height, hitbox_data->rotation);
    sfRectangleShape_setSize(hitbox->rectangle, size);
    return (hitbox);
}
