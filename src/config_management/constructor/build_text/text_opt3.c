/*
** EPITECH PROJECT, 2022
** text_opt3
** File description:
** Source code 
*/
#include "build_scene_texts.h"

int build_text_outline_tickness(text_t *text, char *value)
{
    float tickness = my_atof(value);

    text->outline_tickness = tickness;
    sfText_setOutlineThickness(text->text, text->outline_tickness);
    return (0);
}

int build_text_letter_spacing(text_t *text, char *value)
{
    float spacing = my_atof(value);

    text->letter_spacing = spacing;
    sfText_setLineSpacing(text->text, text->letter_spacing);
    return (0);
}

int build_text_line_spacing(text_t *text, char *value)
{
    float spacing = my_atof(value);

    text->line_spacing = spacing;
    sfText_setLetterSpacing(text->text, text->line_spacing);
    return (0);
}