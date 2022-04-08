/*
** EPITECH PROJECT, 2022
** load_vertices
** File description:
** Program to get vertices of a square
*/
#include "load_vertices.h"

sfVector2f **get_vertices_sq(sfVector2f center, int width, int height)
{
    sfVector2f **vertices_list = malloc((4 + 1) * sizeof(sfVector2f));
    sfVector2f *vertix1 = malloc(sizeof(sfVector2f));
    sfVector2f *vertix2 = malloc(sizeof(sfVector2f));
    sfVector2f *vertix3 = malloc(sizeof(sfVector2f));
    sfVector2f *vertix4 = malloc(sizeof(sfVector2f));

    vertix1->x = center.x - width / 2;
    vertix1->y = center.y + height / 2;
    vertix2->x = center.x + width / 2;
    vertix2->y = center.y + height / 2;
    vertix3->x = center.x + width / 2;
    vertix3->y = center.y - height / 2;
    vertix4->x = center.x - width / 2;
    vertix4->y = center.y - height / 2;
    vertices_list[0] = vertix1;
    vertices_list[1] = vertix2;
    vertices_list[2] = vertix3;
    vertices_list[3] = vertix4;
    vertices_list[4] = NULL;
    return (vertices_list);
}

sfVector2f **get_rot_vertices_sq(sfVector2f center, double rotation,
                                sfVector2f **vertices_list)
{
    double rotated_x;
    double rotated_y;
    double origin_x;
    double origin_y;

    rotation = (rotation) * (M_PI / 180);
    for (int index = 0; vertices_list[index] != NULL; index++) {
        origin_x = vertices_list[index]->x - center.x;
        origin_y = vertices_list[index]->y - center.y;
        rotated_x = origin_x * cos(rotation) - origin_y * sin(rotation);
        rotated_y = origin_x * sin(rotation) + origin_y * cos(rotation);
        vertices_list[index]->x = rotated_x + center.x;
        vertices_list[index]->y = rotated_y + center.y;
    }
    return (vertices_list);
}

void load_vertices(hitbox_t *hitbox)
{
    int index = 0;
    hitbox->vertices = get_rot_vertices_sq(hitbox->position, hitbox->rotation,
            get_vertices_sq(hitbox->position, hitbox->width, hitbox->height));
    hitbox->circle = malloc(sizeof(sfCircleShape *) * (4 + 1));
    for (index = 0; index < 4; index++) {
        sfCircleShape *circle = sfCircleShape_create();

        sfCircleShape_setPosition(circle, *hitbox->vertices[index]);
        sfCircleShape_setRadius(circle, 3);
        sfCircleShape_setFillColor(circle, sfRed);
        sfCircleShape_setOrigin(circle, (sfVector2f) {3, 3});
        sfCircleShape_setOutlineThickness(circle, 0);
        hitbox->circle[index] = circle;   
    }
    hitbox->circle[index] = NULL;
}
