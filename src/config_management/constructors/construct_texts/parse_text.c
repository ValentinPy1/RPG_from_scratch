/*
** EPITECH PROJECT, 2022
** parse_text
** File description:
** Source code to construct a text
*/

#include "construct_text.h"

int get_nb_texts(char **content, int texts)
{
    int counter = 0;

    for (texts = texts; content[texts] != NULL
        && nb_char_in_str(content[texts], '\t') != 1; texts++) {
        if (nb_char_in_str(content[texts], '\t') == 2)
            counter++;
    }
    return (counter);
}

int assign_text_value(sfText *text, char *keyword,
                        char *value, int index)
{
    if (my_strcmp(TEXT_CONS[index].name, keyword) == 1)
        if ((*TEXT_CONS[index].func)(text, value) == -1) {
            write_error("Error while loading texts\n");
            return (-1);
        }
    return (0);
}

int get_text_value(sfText *text, char **content, int line)
{
    char *keyword;
    char *value;

    for (int index = 0; TEXT_CONS[index].name != NULL; index++) {
        keyword = get_keyword(content[line]);
        value = get_value(content[line]);value = get_value(content[line]);
        if (assign_text_value(text, keyword, value, index) == -1)
            return (-1);
    }
    free(value);
    free(keyword);
    return (0);
}

void create_text(sfText *text, char **content, int line)
{
    for (line += 1; nb_char_in_str(content[line], '\t') == 3; line++) {
        if (get_text_value(text, content, line) == -1)
            text = NULL;
    }
}

void construct_text(scene_t *scene, char **content, int index)
{
    int texts = index + 1;
    int text_index = 0;
    int nb_texts = get_nb_texts(content, texts);
    sfText **list_text = malloc((nb_texts + 1) * sizeof(sfText *));

    for (texts = texts; content[texts] != NULL
        && nb_char_in_str(content[texts], '\t') != 1; texts++) {
        if (nb_char_in_str(content[texts], '\t') == 2) {
            list_text[text_index] = sfText_create();
            create_text(list_text[text_index], content, texts);
            text_index++;
        }
    }
    list_text[text_index] = NULL;
    scene->texts = list_text;
    return;
}
