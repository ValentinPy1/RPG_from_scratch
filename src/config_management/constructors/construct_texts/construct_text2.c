/*
** EPITECH PROJECT, 2022
** construct_text2
** File description:
** Source code to construct text
*/

#include "construct_text.h"

int txt_construct_style(sfText *text, char *value)
{
    printf("style:%s\n", value);
    return (0);
}

int txt_construct_rotation(sfText *text, char *value)
{
    int rotation = my_getnbr(value);

    sfText_setRotation(text, rotation);
    return (0);
}

int txt_construct_color(sfText *text, char *value)
{
    printf("color:%s\n", value);
    return (0);
}

int txt_construct_outline_color(sfText *text, char *value)
{
    printf("outline_color:%s\n", value);
    return (0);
}

int txt_construct_outline_tickness(sfText *text, char *value)
{
    int tickness = my_getnbr(value);

    sfText_setOutlineThickness(text, tickness);
    return (0);
}
