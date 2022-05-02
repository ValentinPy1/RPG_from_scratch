/*
** EPITECH PROJECT, 2022
** construct_scene
** File description:
** Source code to parse a config file
*/
#include "build_scene.h"

int parse_line(scene_t *scene, char **content, int *line)
{
    char *id = NULL;
    int return_value = 0;

    if ((id = is_a_scene_opt(content, line)) != NULL)
        if (find_scene_opt(id, content, line) == -1)
            return_value = -1;
    free(id);
    return (return_value);
}

scene_t *build_scene(char **content)
{
    scene_t *new_scene = malloc(sizeof(scene_t));

    if (content == NULL)
        return (NULL);
    
    for (int lines = 0; content[lines] != NULL; lines++) {
        if (parse_line(new_scene, content, &lines) == -1) {
            my_printf("Unable to load %s\n", content[lines]);
        }
    }
    return (new_scene);
}
