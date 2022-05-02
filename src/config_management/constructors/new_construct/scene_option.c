/*
** EPITECH PROJECT, 2022
** scene_option.c
** File description:
** Source code of the scene option
*/
#include "scene_option.h"

char *get_id(char **content, int *line, int index)
{
    int flag = 0;
    int counter = 0;
    char *id = NULL;
    int tmp_index = index + 1;
    int id_index = 0;

    while (content[*line][tmp_index] != '>' && content[*line][tmp_index] != '\0') {
        if (content[*line][tmp_index] == ':')
            flag = 1;
        counter++;
        tmp_index++;
    }
    if (flag == 0)
        return (NULL);
    id = malloc(sizeof(char) * (counter + 1));
    tmp_index = index + 1;
    while (content[*line][tmp_index] != ':') {
        id[id_index] = content[*line][tmp_index];
        tmp_index++;
        id_index++;
    }
    id[id_index] = '\0';
    return (id);
}

char *is_a_scene_opt(char **content, int *line)
{
    char *id = NULL;

    for (int index = 0; content[*line][index] != '\0'; index++) {
        if (content[*line][index] == '<')
            id = get_id(content, line, index);
    }
    return (id);
}

int exec_scene_opt(char *id, int func, char **content, int *line)
{
    if (my_strcmp(id, TAB_SOPT[func].name) == 1) {
        if ((*TAB_SOPT[func].func)(content, line) == -1) {
            return (-1);
        }
    }
    return (0);
}

int find_scene_opt(char *id, char **content, int *line)
{
    for (int func = 0; TAB_SOPT[func].name != NULL; func++) {
        if (exec_scene_opt(id, func, content, line) == -1)
            return (-1);
    }
    return (0);
}
