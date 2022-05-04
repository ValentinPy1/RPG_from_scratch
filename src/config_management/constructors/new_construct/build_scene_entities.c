/*
** EPITECH PROJECT, 2022
** build_scene_entities
** File description:
** Source code to build a scene
*/
#include "build_scene_entities.h"

int build_scene_entities(scene_t *scene, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;

    printf("DEBUG Entitie\n");
    *line += 1;
    char *test = NULL;
    while (content[*line] != NULL && (test = is_a_scene_opt(content, line)) == NULL) {
        for (int index = 0; content[*line][index] != '\0'; index++) {
            opt = get_obj_opt(content, line, &index);
            value = get_opt_value(content, line, &index);
            if (opt != NULL && value != NULL) {
                printf("[entitie]:%s->%s\n", opt, value);
                free(opt);
                free(value);
            }
        }
        if (is_a_scene_opt(content, line) == NULL)
            break;
        *line += 1;
    }
    return (0);
}