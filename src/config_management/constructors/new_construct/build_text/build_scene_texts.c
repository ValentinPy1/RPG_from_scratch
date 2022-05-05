/*
** EPITECH PROJECT, 2022
** build_scene_texts
** File description:
** Source code to build a scene
*/
#include "build_scene_texts.h"

int build_texts_opt(text_t *text, char *opt, char *value)
{
    if (opt == NULL || value == NULL)
        return (0);
    for (int index = 0; TEXT_OPT_TAB[index].name != NULL; index++) {
        if (my_strcmp(opt, TEXT_OPT_TAB[index].name) == 1)
            (*TEXT_OPT_TAB[index].func)(text, value);
    }
    free(opt);
    free(value);
    return (1);
}

int build_texts(text_t **head_ref, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;
    text_t *new_text = malloc(sizeof(text_t));
        
    for (int index = 0; content[*line][index] != '\0'; index++) {
        opt = get_obj_opt(content, line, &index);
        value = get_opt_value(content, line, &index);
        build_texts_opt(new_text, opt, value);
    }
    if ((*head_ref) == NULL) {
        new_text->next = NULL;
        *head_ref = new_text;
    } else {
        new_text->next = *head_ref;
        *head_ref = new_text;
    }
}

int build_scene_texts(scene_t *scene, char **content, int *line)
{
    *line += 1;
    while (content[*line] != NULL && is_a_scene_opt(content, line) == NULL) {
        build_texts(&(scene->texts), content, line);
        if (is_a_scene_opt(content, line) == NULL)
            break;
        *line += 1;
    }
    return (0);
}