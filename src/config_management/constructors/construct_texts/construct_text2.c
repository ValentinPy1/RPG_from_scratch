/*
** EPITECH PROJECT, 2022
** construct_text2
** File description:
** Source code to construct text
*/

#include "construct_text.h"

int txt_construct_style(sfText *text, char *value)
{
    int flag = 0;

    for (int index = 0; TEXT_STYLE[index].name != NULL; index++) {
        if (my_strcmp(TEXT_STYLE[index].name, value) == 1) {
            sfText_setStyle(text, TEXT_STYLE[index].style);
            flag = 1;
        }
    }
    if (flag == 0) {
        write_error("Invalid argument for text style \"");
        write_error(value);
        write_error("\".\n");
        return (-1);
    }
    return (0);
}

int txt_construct_rotation(sfText *text, char *value)
{
    float rotation = my_atof(value);

    if (text != NULL)
        sfText_setRotation(text, rotation);
    return (0);
}

int txt_construct_color(sfText *text, char *value)
{
    char **rgb_a_value = my_split(value, ';');
    sfUint8 r = 0;
    sfUint8 g = 0;
    sfUint8 b = 0;
    sfUint8 a = 255;
    sfColor color = {255, 255, 255, 255};

    r = my_getnbr(rgb_a_value[0]);
    g = my_getnbr(rgb_a_value[1]);
    b = my_getnbr(rgb_a_value[2]);
    if (rgb_a_value[3])
        a = my_getnbr(rgb_a_value[3]);
    color = sfColor_fromRGBA(r, g, b, a);
    if (text != NULL)
        sfText_setColor(text, color);
    free_str_tab(rgb_a_value);
    return (0);
}

int txt_construct_outline_color(sfText *text, char *value)
{
    char **rgb_a_value = my_split(value, ';');
    sfUint8 r = 0;
    sfUint8 g = 0;
    sfUint8 b = 0;
    sfUint8 a = 255;
    sfColor color = {255, 255, 255, 255};

    r = my_getnbr(rgb_a_value[0]);
    g = my_getnbr(rgb_a_value[1]);
    b = my_getnbr(rgb_a_value[2]);
    if (rgb_a_value[3])
        a = my_getnbr(rgb_a_value[3]);
    color = sfColor_fromRGBA(r, g, b, a);
    if (text != NULL)
        sfText_setOutlineColor(text, color);
    free_str_tab(rgb_a_value);
    return (0);
}

int txt_construct_outline_tickness(sfText *text, char *value)
{
    float tickness = my_atof(value);

    if (text != NULL)
        sfText_setOutlineThickness(text, tickness);
    return (0);
}
