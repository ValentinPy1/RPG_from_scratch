/*
** EPITECH PROJECT, 2022
** construct_text
** File description:
** Header
*/

#ifndef TEXT_H_
    #define TEXT_H_
    #include "structures.h"
    #include <stddef.h>
    #include <stdlib.h>

typedef struct style_s {
    sfTextStyle style;
    char *name;
} style_t;

static const style_t TEXT_STYLE[6] = {
    {sfTextRegular, "regular"},
    {sfTextBold, "bold"},
    {sfTextItalic, "italic"},
    {sfTextUnderlined, "underlined"},
    {sfTextStrikeThrough, "strike_through"},
    {sfTextRegular, NULL}
};

typedef struct text_cons_s {
    char *name;
    int (*func)(sfText *text, char *value);
} text_cons_t;

int txt_construct_str(sfText *text, char *value);
int txt_construct_font(sfText *text, char *value);
int txt_construct_posx(sfText *text, char *value);
int txt_construct_posy(sfText *text, char *value);
int txt_construct_size(sfText *text, char *value);
int txt_construct_style(sfText *text, char *value);
int txt_construct_rotation(sfText *text, char *value);
int txt_construct_color(sfText *text, char *value);
int txt_construct_outline_color(sfText *text, char *value);
int txt_construct_outline_tickness(sfText *text, char *value);
int txt_construct_line_spacing(sfText *text, char *value);
int txt_construct_letter_spacing(sfText *text, char *value);

static const text_cons_t TEXT_CONS[] = {
    {"text", txt_construct_str},
    {"font", txt_construct_font},
    {"posx", txt_construct_posx},
    {"posy", txt_construct_posy},
    {"size", txt_construct_size},
    {"style", txt_construct_style},
    {"rotation", txt_construct_rotation},
    {"color", txt_construct_color},
    {"outline_color", txt_construct_outline_color},
    {"outline_tickness", txt_construct_outline_tickness},
    {"line_spacing", txt_construct_line_spacing},
    {"letter_spacing", txt_construct_letter_spacing},
    {NULL, NULL}
};

int write_error(char const *str);
int nb_char_in_str(char *str, char c);
char *get_keyword(char *str);
char *get_value(char *str);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char *str);
float my_atof(char *str);
char **my_split(char *str, char splitter);
void free_str_tab(char **tab);
int count_line(char **tab);

#endif /*BUTT_H_*/
