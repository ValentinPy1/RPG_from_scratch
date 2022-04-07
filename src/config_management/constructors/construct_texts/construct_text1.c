/*
** EPITECH PROJECT, 2022
** construct_text1
** File description:
** Source code to construct text
*/

#include "construct_text.h"

int txt_construct_str(sfText *text, char *value)
{
    sfText_setString(text, (const char *) value);
    return (0);
}

int txt_construct_font(sfText *text, char *value)
{
    sfFont *font = sfFont_createFromFile(value);
    
    sfText_setFont(text, font);
    return (0);
}

int txt_construct_posx(sfText *text, char *value)
{
    int x = my_getnbr(value);

    sfVector2f pos = {x, 0};
    sfText_setPosition(text, pos);
    return (0);
}

int txt_construct_posy(sfText *text, char *value)
{
    int y = my_getnbr(value);

    sfVector2f pos = sfText_getPosition(text);
    pos.y = y;
    sfText_setPosition(text, pos);
    return (0);
}

int txt_construct_size(sfText *text, char *value)
{
    int size = my_getnbr(value);

    sfText_setCharacterSize(text, size);
    return (0);
}