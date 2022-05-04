/*
** EPITECH PROJECT, 2022
** build_scene_name
** File description:
** Source code to build a scene
*/
#include "build_scene_name.h"

int build_scene_name(scene_t *scene, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;

    for (int index = 0; content[*line][index] != '>' && content[*line] != NULL; index++)
    {
        if (content[*line][index] == '\0' && content[*line + 1] != NULL) {
            index = 0;
            *line += 1;
        }
        opt = get_obj_opt(content, line, &index);
        value = get_opt_value(content, line, &index);
        if (opt != NULL && value != NULL) {
            printf("[NAME]:%s->%s\n", opt, value);
            free(opt);
            free(value);
        }
        else {
            printf("Error a \" or a \' is missing line %i\n", *line);
            break;
        }
    }
    return (0);
}