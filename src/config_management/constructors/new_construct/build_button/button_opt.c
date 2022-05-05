/*
** EPITECH PROJECT, 2022
** button_opt
** File description:
** SOurce code to build option of a button
*/
#include "build_scene_buttons.h"

int build_butt_name(button_t *button, char *value)
{
    printf("build button name...\n");
    button->name = my_strdup(value);
    return (0);
}
int build_butt_posx(button_t *button, char *value)
{
    printf("build button posx...\n");
    button->posx = my_getnbr(value);
    return (0);
}

int build_butt_posy(button_t *button, char *value)
{
    printf("build button posy...\n");
    button->posy = my_getnbr(value);
    return (0);
}

int build_butt_width(button_t *button, char *value)
{
    printf("build button width...\n");
    button->width = my_getnbr(value);
    return (0);
}

int build_butt_height(button_t *button, char *value)
{
    printf("build button height...\n");
    button->height = my_getnbr(value);
    return (0);
}
