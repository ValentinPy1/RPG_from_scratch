/*
** EPITECH PROJECT, 2022
** construct_text3
** File description:
** Source code to construct text
*/

#include "construct_text.h"

int txt_construct_line_spacing(sfText *text, char *value)
{
    float spacing = my_atof(value);

    if (text != NULL)
        sfText_setLineSpacing(text, spacing);
    return (0);
}

int txt_construct_letter_spacing(sfText *text, char *value)
{
    float spacing = my_atof(value);

    if (text != NULL)
        sfText_setLetterSpacing(text, spacing);
    return (0);
}