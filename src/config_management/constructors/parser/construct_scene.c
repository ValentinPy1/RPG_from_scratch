/*
** EPITECH PROJECT, 2022
** construct_scene
** File description:
** Source code to parse a config file
*/
#include "construct_scene.h"

void init_scene(scene_t *scene, char **content)
{
    int line;
    int nb_tab;

    for (line = 0; content[line] != NULL; line++) {
        nb_tab = nb_char_in_str(content[line], '\t');
        if (nb_tab != 2)
            constructor(scene, content, line);
    }
}

scene_t *my_parser(char **content)
{
    int nb_tab;
    scene_t *new_scene = malloc(sizeof(scene_t));

    if (content == NULL || error_handling(content) == 1)
        return (NULL);
    init_scene(new_scene, content);
    return (new_scene);
}
