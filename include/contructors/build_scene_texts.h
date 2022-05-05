/*
** EPITECH PROJECT, 2022
** build_scene_texts
** File description:
** Header
*/

#ifndef BUILD_SCENE_TEXTS_H_
    #define BUILD_SCENE_TEXTS_H_
    #include "stddef.h"
    #include "structures.h"

typedef struct text_opt_s {
    char *name;
    int (*func)(text_t *text, char *value);
} text_opt_t;

int build_text_name(text_t *text, char *value);
int build_text_posx(text_t *text, char *value);
int build_text_posy(text_t *text, char *value);
int build_text_text(text_t *text, char *value);
int build_text_font(text_t *text, char *value);
int build_text_size(text_t *text, char *value);
int build_text_rotation(text_t *text, char *value);
int build_text_style(text_t *text, char *value);
int build_text_color(text_t *text, char *value);
int build_text_outline_color(text_t *text, char *value);
int build_text_outline_tickness(text_t *text, char *value);
int build_text_letter_spacing(text_t *text, char *value);
int build_text_line_spacing(text_t *text, char *value);

static text_opt_t TEXT_OPT_TAB[] =  {
    {"name", build_text_name},
    {"posx", build_text_posx},
    {"posy", build_text_posy},
    {"text", build_text_text},
    {"font", build_text_font},
    {"size", build_text_size},
    {"rotation", build_text_rotation},
    {"style", build_text_style},
    {"color", build_text_color},
    {"outline_color", build_text_outline_color},
    {"outline_tickness", build_text_outline_tickness},
    {"letter_spacing", build_text_letter_spacing},
    {"line_spacing", build_text_line_spacing},
    {NULL, NULL},
};

char *get_obj_opt(char **content, int *line, int *index);
char *get_opt_value(char **content, int *line, int *index);
#endif /* !BUILD_SCENE_TEXTS_H_ */
