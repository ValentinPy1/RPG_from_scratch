/*
** EPITECH PROJECT, 2022
** construct_image1
** File description:
** Source code to construct a image
*/

#include "construct_image.h"

int img_construct_posx(image_t *image, char *value)
{
    int coord_x = my_getnbr(value);

    image->position.x = coord_x;
    return (0);
}

int img_construct_posy(image_t *image, char *value)
{
    int coord_y = my_getnbr(value);

    image->position.y = coord_y;
    return (0);
}

int img_construct_width(image_t *image, char *value)
{
    int width = my_getnbr(value);

    image->width = width;
    return (0);
}
int img_construct_height(image_t *image, char *value)
{
    int height = my_getnbr(value);

    image->height = height;
    return (0);
}

int img_construct_scale(image_t *image, char *value)
{
    sfVector2f scale = (sfVector2f) {my_atof(value), my_atof(value)};

    image->scale = scale;
    return (0);
}
