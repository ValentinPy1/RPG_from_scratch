/*
** EPITECH PROJECT, 2022
** build_scene_background
** File description:
** Source code to build a scene
*/
#include "build_scene_background.h"

int build_scene_background(char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;

    printf("[DEBUG][START]%s\n", content[*line]);   
    for (int index = 0; content[*line][index] != '>' && content[*line] != NULL; index++)
    {
        if (content[*line][index] == '\0' && content[*line + 1] != NULL) {
            index = 0;
            *line += 1;
        }
        opt = get_obj_opt(content, line, &index);
        value = get_opt_value(content, line, &index);
        if (opt != NULL && value != NULL)
            printf("[OPT]:%s\n[VAL]:%s\n", opt, value);
        else
            break;
    }
    return (0);
}