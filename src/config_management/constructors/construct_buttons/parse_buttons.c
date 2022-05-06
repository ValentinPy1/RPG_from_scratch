/*
** EPITECH PROJECT, 2022
** parse_button
** File description:
** Source code to construct a button
*/

#include "construct_button.h"

int get_nb_buttons(char **content, int buttons)
{
    int counter = 0;

    for (buttons = buttons; content[buttons] != NULL
        && nb_char_in_str(content[buttons], '\t') != 1; buttons++) {
        if (nb_char_in_str(content[buttons], '\t') == 2)
            counter++;
    }
    return (counter);
}

int assign_button_value(button_t *button, char *keyword,
                        char *value, int index)
{
    if (my_strcmp(BUT_CONS[index].name, keyword) == 1)
        if ((*BUT_CONS[index].func)(button, value) == -1) {
            write_error("Error while loading buttons\n");
            return (-1);
        }
    return (0);
}

int get_button_value(button_t *button, char **content, int line)
{
    char *keyword;
    char *value;

    keyword = get_keyword(content[line]);
    value = get_value(content[line]);
    for (int index = 0; BUT_CONS[index].name != NULL; index++) {
        if (assign_button_value(button, keyword, value, index) == -1)
            return (-1);
    }
    free(keyword);
    free(value);
    return (0);
}

void create_button(button_t *button, char **content, int line)
{
    button->hitbox = malloc(sizeof(hitbox_t));
    button->is_hovered = 0;
    for (line += 1; nb_char_in_str(content[line], '\t') == 3; line++) {
        if (get_button_value(button, content, line) == -1)
            button = NULL;
    }
    if (button != NULL)
        init_hitbox(button->hitbox);
}

void construct_button(scene_t *scene, char **content, int index)
{
    int buttons = index + 1;
    int button_index = 0;
    int nb_buttons = get_nb_buttons(content, buttons);
    button_t **list_button = malloc((nb_buttons + 1) * sizeof(button_t));

    for (buttons = buttons; content[buttons] != NULL
        && nb_char_in_str(content[buttons], '\t') != 1; buttons++) {
        if (nb_char_in_str(content[buttons], '\t') == 2) {
            list_button[button_index] = malloc(sizeof(button_t));
            create_button(list_button[button_index], content, buttons);
            button_index++;
        }
    }
    list_button[button_index] = NULL;
    scene->buttons = list_button;
    return;
}